#Name:Vedant Sahai
#Roll No:8364
#Batch: C
#DeffieServer
from deffie import coprime_driver,modulus
import socket

host = '127.0.0.1'
port = 6789
p = int(input("Enter secret random number p"))
q = coprime_driver(p)

tcp = socket.socket()
tcp.connect((host, port))

while True:
    print('Enter Private Key :')
    xb = int(input())
    if xb == 'q':
        break
    message = modulus(str(q**xb),p)
    message = str(message)
    message = message.encode()
    tcp.send(message)

    ya = tcp.recv(1024).decode()
    ya = int(ya)
    data = modulus(str(ya**xb),p)
    print('Server Key : ', data)
tcp.close()

#OUTPUT:-
# Enter secret random number p353
# Enter Private Key :
# 97
# Server Key :  160