import socket
# "A banner is a message presented to a user who is using the Cisco switch. 
# The type of banner you configured for use determines when this message is shown. 
# You can configure three main types of banners: Message of the Day, Login, and Exec."
def banner(ip, port):
    s = socket.socket()
    s.settimeout(2)
    try:
        s.connect((ip, int(port)))
    except:
        print("Connection refused.")

    print(s.recv(1024).decode())
    print("Target machine refused to answer.")

def main():
    ip = input("Enter the IP address you want this program to execute on: ")
    port = str(input("Enter the port you want this program to execute on: "))
    banner(ip, port)

main()