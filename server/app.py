import socketio

sio = socketio.Server(cors_allowed_origins='http://localhost:3000')
app = socketio.WSGIApp(sio)

players = [None, None]

gameInstace = None
playerTurn = 0

"""
[
    {
        "sid" : number,
        "board" : []
    },
    {
        "sid" : number,
        "board" : []
    }
]
"""


@sio.event
def connect(sid, environ):
    print(sid, 'connected')


@sio.event
def disconnect(sid):
    print(f"{sid} disconnected")
    for i, player in enumerate(players):
        if(player != None and player["sid"] == sid):
            players[i] = None
            #  Send game-over event to notify user about finished game
            print(f"Player {i} has disconected GAME OVER!")
            return


@sio.event
def shoot(sid, data):
    # implement shooting a single shot - round logic
    opponentSID = -1

    if(players[0]["sid"] == sid):
        opponentSID = players[1]["sid"]
    else:
        opponentSID = players[0]["sid"]

    # Use game logic to determine weather or not is hit
    field = data["field"]
    isHit = False
    # Emit if hit or not hit
    sio.emit('fire', {"hit": isHit, "field": field}, to=opponentSID)

    global playerTurn

    playerTurn = 1 if playerTurn == 0 else 0

    if not isHit:
        for player in players:
            playerSID = player["sid"]
            sio.emit('player-turn', playerTurn, to=playerSID)
        pass

    # check if end game emit end-game

    return isHit


@sio.event
def join(sid, data):
    print(f"Player {sid} has joined")
    playerNumber = -1

    for i, player in enumerate(players):
        if(player == None):
            playerNumber = i
            players[i] = {
                "sid": sid,
                "board": data
            }
            print(f"Player {i} with sid: {sid} joined with board {data}")
            break

    sio.emit('player-number', playerNumber, to=sid)

    if(playerNumber == -1):
        print("No place for you, sorry")
        return

    if players[0] != None and players[1] != None:
        print("Start the game!")
        for player in players:
            playerSID = player["sid"]
            print(f"Sending player number notification to player {playerSID}")
            sio.emit('player-turn', playerTurn, to=playerSID)
        # Create new gameinstance and nofiy users that game began
        # Check if everything is all right
        pass
