#!/usr/bin/python3
import socketio
import pythonGame

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
            winnerIDX = 0 if i == 1 else 1
            winner = players[winnerIDX]["sid"]
            sio.emit('game-over', to=winner)
            players[0] = None
            players[1] = None
            gameInstace = None
            playerTurn = 0
            print(f"Player {i} has disconected GAME OVER!")
            return


@sio.event
def shoot(sid, data):
    opponentSID = -1

    if(players[0]["sid"] == sid):
        opponentSID = players[1]["sid"]
    else:
        opponentSID = players[0]["sid"]

    global gameInstace
    global playerTurn

    field = data["field"]
    player = playerTurn + 1
    isHit = gameInstace.Shot(field, player)

    sio.emit('fire', {"hit": isHit, "field": field}, to=opponentSID)

    if not isHit:
        playerTurn = 1 if playerTurn == 0 else 0
        for player in players:
            playerSID = player["sid"]
            sio.emit('player-turn', playerTurn, to=playerSID)

    if gameInstace.IsEnd():
        for player in players:
            playerSID = player["sid"]
            sio.emit('game-over', to=playerSID)

    return isHit


@sio.event
def join(sid, data):
    print(f"Player {sid} has joined")
    playerNumber = -1

    # CHECK FOR HTE SAME PLAYER JOINING
    for i, player in enumerate(players):
        if(player == None):
            playerNumber = i
            players[i] = {
                "sid": sid,
                "board": data
            }
            break

    sio.emit('player-number', playerNumber, to=sid)

    if(playerNumber == -1):
        print("No place for you, sorry")
        return

    global playerTurn
    global gameInstace

    if players[0] != None and players[1] != None:
        print("Start the game!")
        gameInstace = pythonGame.Game(players[0]["board"], players[1]["board"])
        for player in players:
            playerSID = player["sid"]
            sio.emit('player-turn', playerTurn, to=playerSID)

        # Create new gameinstance and nofiy users that game began
        # Check if everything is all right
        pass
