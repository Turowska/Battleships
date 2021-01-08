import socketio

sio = socketio.Server(cors_allowed_origins='http://localhost:3000')
app = socketio.WSGIApp(sio)

players = [None, None]

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
            print(f"Player {i} has disconected GAME OVER!")
            return


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
