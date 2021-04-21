import socket			 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)		 
#creates socket
port = 12345	
s.connect(('localhost', port))                               
#connecting to the socket on the port
print(s.recv(1024).decode('utf-8'))

data=input("Enter the string : ")	
s.send(data.encode('utf-8'))

print("The reversed string is",str(s.recv(1024).decode('utf-8')))

print(s.recv(1024).decode('utf-8'))

s.close()	 

'''Output : 
> python tcp_client.py
Thank you for connecting
Enter the string : neen
The reversed string is neen
The string is palindrome'''