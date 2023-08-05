import nmap 

scanner = nmap.PortScanner()
print("Welcome! This is a simple nmap program")
print("-----------------------------------")

#prompt the user for an ip to scan
ip = input("Enter your desired IP address to be scanned: ")
print("Entered IP is: ", ip)
type(ip)

resp = input("""\nEnter the type of scan you want to run: 
                    1) SYN ACK scan
                    2) UDP scan
                    3) Comprehensive scan\n""")
print("You have selected option ", resp)

print("nmap version: ", scanner.nmap_version())
if resp == '1': 
    scanner.scan(ip, '1-1024', '-v -sS') #ip; range of ports (customizable); type of scan
    print(scanner.scaninfo())
    #check if ip is active
    print("IP status: ", scanner[ip].state())
    #print protocol - tcp
    print("Using protocol:", scanner[ip].all_protocols())
    #open ports within the range
    port_list = ""
    for key in scanner[ip]['tcp'].keys():
        port_list += str(key) + " "
    print("Open ports: ", port_list)
elif resp == 2:
    scanner.scan(ip, '1-1024', '-v -sU') #ip; range of ports (customizable); type of scan
    print(scanner.scaninfo())
    #check if ip is active
    print("IP status: ", scanner[ip].state())
    #print protocols - udp
    print("Using protocol:", scanner[ip].all_protocols())
    #open ports within the range
    port_list = ""
    for key in scanner[ip]['udp'].keys():
        port_list += str(key) + " "
    print("Open ports: ", port_list)
elif resp == 3:
    scanner.scan(ip, '1-1024', '-v -sS -sV -sC -A -OS') #ip; range of ports (customizable); 
    #types of scan: verbose, SYN, service enum, default script, aggressive, os detection
    print(scanner.scaninfo())
    #check if ip is active
    print("IP status: ", scanner[ip].state())
    #print protocols - tcp or udp
    print("Using protocol(s):", scanner[ip].all_protocols())
    #open ports within the range    
    port_list = ""
    for key in scanner[ip]['tcp'].keys():
        port_list += str(key) + ", "
    print("Open ports: ", port_list)
        
else:
    print("Not funny.")