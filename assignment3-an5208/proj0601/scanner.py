import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM) #tcp -- this is the default
s.settimeout(3)
host = "137.74.187.100" #hackthissite.org
port = 443

def portscan(port):
    # raises an error when fail, instead of an exception (connect())
    # this is so that the program stops instead of continuing
    if s.connect_ex((host, port)):  
        print("Port is closed.")
    else:
        print("Port is open.")

def main():
    port = input("Enter your port, or \"quit\": ")
    while port != "quit":
        port_num = int(port)
        portscan(port_num)
        port = input("Enter your port, or \"quit\": ")
    
main()