import socket 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)		 
print("Socket successfully created")

port = 12345			
s.bind(('localhost', port))		 
print("socket binded to %s" %(port)) 

s.listen(5)	 
print("socket is listening") 	

conn, addr = s.accept()	
print('Got connection from : ',addr) 

conn.send(b'Thank you for connecting')

data = conn.recv(1024).decode('utf-8')
print("The received string is : "+str(data))

data1 = data[::-1]

conn.send(data1.encode('utf-8'))

if(data1==data):
    conn.send(b'The string is palindrome')
else:
    conn.send(b'The string is not palindrome')
conn.close() 

'''Output :
> python tcp_server.py
Socket successfully created
socket binded to 12345
socket is listening
Got connection from :  ('127.0.0.1', 52551)
The received string is : neen
'''