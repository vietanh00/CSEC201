import socket

host = 'localhost'
port = 10021

client_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_sock.connect((host, port))

client_sock.send(b"Sup")
msg = client_sock.recv(4096)
print(msg.decode())

client_sock.close()
