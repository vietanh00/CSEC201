import socket


def main():
    DEFAULT_BUFFLEN = 512
    port = 9999
    msg = "hello"

    serverSocket = socket.socket()
    serverSocket.connect(("localhost", port))
    serverSocket.settimeout(2)

    serverSocket.send(b"sup")
    msg = serverSocket.recv(DEFAULT_BUFFLEN)
    print(msg.decode())

    msg = input("Enter your message or \'bye\': ")

    while (msg != 'bye'):
        serverSocket.send(msg.encode())

        #print server response (if any)
        msg = serverSocket.recv(DEFAULT_BUFFLEN)
        print(msg.decode())

        msg = input("Enter your message or \'bye\': ")

    serverSocket.close()

