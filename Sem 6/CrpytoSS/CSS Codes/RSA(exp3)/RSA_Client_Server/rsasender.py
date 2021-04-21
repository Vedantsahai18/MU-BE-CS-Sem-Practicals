import socket
import timeit

start = timeit.default_timer()
s = socket.socket()
host = socket.gethostname()
port = 5002
s.bind((host,port))
s.listen(5)

c, addr = s.accept()
print('Connection from: ', addr)
msg='Connected to Sender'
c.send(msg.encode())
print(c.recv(5002).decode())
      
e=c.recv(5002).decode()
e=int(e)
print('Public Key of  Receiver (e) => ',e)
N=c.recv(5002).decode()
N=int(N)
print('Received N=(p*q) => ',N)

pt=int(input('Enter pt : '))

ct=str((pt**e)%N)
c.send(ct.encode())
print("Sending CT => ",ct)
stop = timeit.default_timer()

print('Time: ', stop - start) 
s.close

'''
Connection from:  ('127.0.0.1', 45506)
From Receiver
Public Key of  Receiver (e) =>  659
Received N=(p*q) =>  713
Enter pt : 2
Sending CT =>  357
Time:  95.48030680000001
'''
