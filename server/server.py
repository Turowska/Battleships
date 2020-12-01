import socket
import threading

HEADER = 64
PORT = 8000
SERVER = socket.gethostbyname(socket.gethostname())
ADDR = (SERVER, PORT)
FORMAT = "UTF-8"
DISCONNECT_MESSAGE = "!DISCONNEC"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)


def handle_client(conn, addr):
    print(f"[NEW CONNECTION] {addr} connected.")

    connected = True
    while connected:
        msg_len = conn.recv(HEADER).decode(FORMAT)
        msg_len = int(msg_len)
        msg = conn.recv(msg_len).decode(FORMAT)
        if msg == DISCONNECT_MESSAGE:
            connected = False

        print(f"[{addr} {msg}]")
    conn.close()


def start():
    server.listen()
    print(f"[Listening] Server is listening on {SERVER}")
    while True:
        conn, addr = server.accept()
        thread = threading.Thread(target=handle_client, args=(conn, addr))
        thread.start()
        print(f"[ACTIVE CONNETCTIONS] {threading.active_count() - 1}")


print("[STARTING] Server is starting....")
start()
