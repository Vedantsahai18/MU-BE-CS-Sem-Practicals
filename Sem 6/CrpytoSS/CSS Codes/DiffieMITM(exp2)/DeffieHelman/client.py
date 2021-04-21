#Name:Vedant Sahai
#Roll No:8364
#Batch: C
#DeffieClient
from deffie import coprime_driver,modulus
import socket

host = '127.0.0.1'
port = 6789
p = int(input("Enter secret random number p"))
q = coprime_driver(p)

tcp = socket.socket()
tcp.bind((host, port))
tcp.listen(1)

conn, addr = tcp.accept()

while True:
    yb = conn.recv(1024).decode()
    if not yb:
        break
    yb = int(yb)
    print('Enter Private Key :')
    xa = int(input())
    data = modulus(str(yb**xa),p)
    print('Client Key :', data)

    message = modulus(str(q**xa),p)
    message = str(message)
    message = message.encode()
    conn.send(message)
conn.close()

#OUTPUT:-
# Enter secret random number p353
# Enter Private Key :
# 233
# Client Key : 160