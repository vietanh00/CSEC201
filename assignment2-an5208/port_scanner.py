# port scanner, client-side socket program

import socket
host = 'scanme.nmap.org'
port = 70

for port in range(0, 1000):
    try:
        client_sock = socket.socket()
        client_sock.settimeout(3)
        """Without the try-except block:
        1) raise error if the port is closed, 
        2) proceed if the port is open
        3) port may be filtered - program blocked
        -> raise timeout error if operation cannot be done within the timeout period"""
        client_sock.connect((host, port))
        print(f"port {port} is open")
        client_sock.close()
    except socket.timeout:
        print(f"port {port} is filtered")
    except OSError:
        print(f"port {port} is closed")


