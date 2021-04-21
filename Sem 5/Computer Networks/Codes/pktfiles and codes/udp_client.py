import time
import socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#creating a socket connection
message = b'Thanks for connecting'
addr = ('localhost', 12000)
client_socket.sendto(message, addr)
#sending a request to server through message
data, server = client_socket.recvfrom(1024)
print(str(data.decode('utf-8')))

message=input("Enter the string : ").encode('utf-8')
client_socket.sendto(message, addr)

data, server = client_socket.recvfrom(1024)
print(str(data.decode('utf-8')))

'''Output:
> python udp_client.py
Connected to server
Enter the string : neen
The string is palindrome'''