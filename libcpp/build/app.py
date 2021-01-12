#!/usr/bin/python3
import socketio
import pythonGame

sio = socketio.Server(cors_allowed_origins='http://localhost:3000')
app = socketio.WSGIApp(sio)

players = [None, None]

gameInstace = None
playerTurn = 0


@sio.event
def connect(sid, environ):
    print(sid, 'connected')


@sio.event
def disconnect(sid):
    print(f"{sid} disconnected")
    global playerTurn
    global gameInstace
    global players

    for i, player in enumerate(players):
        if(player != None and player["sid"] == sid):
            print("One of the players has left the game")
            winnerIDX = 0 if i == 1 else 1
            if players[winnerIDX] != None:
                winnerSID = players[winnerIDX]["sid"]
                sio.emit('game-over-left', to=winnerSID)
            players = [None, None]
            gameInstace = None
            playerTurn = 0
            return


def finishGame():
    global playerTurn
    global players
    global gameInstace
    for idx, player in enumerate(players):
        playerSID = player["sid"]
        if idx == playerTurn and player != None:
            sio.emit('game-over-win', to=playerSID)
        else:
            sio.emit('game-over-lost', to=playerSID)
    players = [None, None]
    gameInstace = None
    playerTurn = 0


def changePlayer():
    global playerTurn
    playerTurn = 1 if playerTurn == 0 else 0
    for player in players:
        playerSID = player["sid"]
        sio.emit('player-turn', playerTurn, to=playerSID)


@sio.event
def shoot(sid, data):
    opponentSID = -1
    playerSID = -1

    global players
    if(players[0]["sid"] == sid):
        opponentSID = players[1]["sid"]
        playerSID = players[0]["sid"]
    else:
        opponentSID = players[0]["sid"]
        playerSID = players[1]["sid"]

    global gameInstace
    global playerTurn

    field = data["field"]
    player = playerTurn + 1
    isHit = gameInstace.Shot(field, player)

    sio.emit('isHit', {"hit": isHit, "field": field}, to=sid)
    sio.emit('fire', {"hit": isHit, "field": field}, to=opponentSID)

    sunkedShip = gameInstace.IsSunk(field)

    if sunkedShip:
        sio.emit('sunked', sunkedShip, to=playerSID)

    if gameInstace.IsEnd():
        finishGame()
    else:
        if not isHit:
            changePlayer()


@ sio.event
def join(sid, data):
    playerNumber = -1

    global players
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
        gameInstace = pythonGame.Game(players[0]["board"], players[1]["board"])
        if not gameInstace.IsGood():
            for player in players:
                playerSID = player["sid"]
                sio.emit('bad-board', to=playerSID)
            players = [None, None]
            gameInstace = None
        else:
            for player in players:
                playerSID = player["sid"]
                sio.emit('player-turn', playerTurn, to=playerSID)
