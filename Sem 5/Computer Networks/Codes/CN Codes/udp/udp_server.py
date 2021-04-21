import random
import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.bind(('localhost', 12000))
#creating socket connection
message, address = server_socket.recvfrom(1024)
print(str(message.decode('utf-8')))
#recieving and accepting a request
data=b'Connected to server'
server_socket.sendto(data, address)

message, address = server_socket.recvfrom(1024)
message = message.decode('utf-8')
message1 = message[::-1]

print("The string sent is : "+str(message))

#reversing string
if(message1==message):
    server_socket.sendto(b'The string is palindrome', address)
else:
    server_socket.sendto(b'The string is not palindrome', address)
#checking if string is palindrome
'''Output:
> python udp_server.py
Thanks for connecting
The string sent is : neen'''