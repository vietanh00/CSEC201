import socket
import threading


def handle(client_socket, address0):
    print("Server is listening to" + str(address0))
    # Param: No of bytes the function can receive at a time
    received_msg = client_socket.recv(4096)
    received_msg = received_msg.decode()
    print('Received: ' + received_msg)
    client_socket.send(received_msg.upper().encode())
    client_socket.close()


def main():
    port = 10021  # the port the socket will be listening on
    # Param may be like this by default
    server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    # Empty string -> server listens to all hosts
    server_sock.bind(('', port))
    server_sock.listen()  # How many attempts will be tolerated
    while True:
        # This method is blocking if no client
        client_sock, address = server_sock.accept()
        # Create a thread to deal with a single client
        thread = threading.Thread(target=handle, args=[client_sock, address])
        thread.start()
    server_sock.close()


main()
