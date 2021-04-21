import socket
import hashlib
import pickle
from Crypto.Util import number

def PrimeNum():         # Returns a 100-digit Prime Number
    n_length =5      # 2 raised to 354 is around 100 digit number
    primeNum = number.getPrime(n_length)        # getPrime() takes number of bits as parameter
    return primeNum
 
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

p=PrimeNum()   
print('Prime No. p                                => ',p)
p=str(p)
temp=input("Sending p...")
c.send(p.encode())

d=PrimeNum()    
print('Decryption key d(Sender private key)       => ',d)
d=str(d)
temp=input("Sending d...")
c.send(d.encode())

E1=PrimeNum()   
print('Encryption key E1                         => ',E1)

d=int(d)
p=int(p)
E2=(E1**d)%p 
print('Encryption key E2                         => ',E2)

print('Public key of sender (E1,E2)              => ',(E1,E2))

R=PrimeNum()
if not(0 <= R  and  R <= (p-2)):
    R=PrimeNum()

print('R is                        => ',R)
pt=int(input('Enter pt : '))
C1=(E1**R)%p

C2=(pt*(E2**R))%p
print('CT is (C1,C2)      => ',(C1,C2))

C1=str(C1)
print("Sending C1...")
c.send(C1.encode())

C2=str(C2)
temp=input("Sending C2...")
c.send(C2.encode())

s.close

'''
**OUTPUT**
EXAMPLE 1

Connection from:  ('127.0.0.1', 57680)
From Receiver
Prime No. p                                =>  11
Sending p...
Decryption key d(Sender private key)       =>  3
Sending d...
Encryption key E1                         =>  2
Encryption key E2                         =>  8
Public key of sender (E1,E2)              =>  (2, 8)
R is                        =>  4
CT is (C1,C2)      =>  (5, 6)
Sending C1...
Sending C2...
'''
'''
EXAMPLE 2
python3 elgs.py
Connection from:  ('127.0.0.1', 57730)
From Receiver
Prime No. p                                =>  29
Sending p...
Decryption key d(Sender private key)       =>  29
Sending d...
Encryption key E1                         =>  31
Encryption key E2                         =>  2
Public key of sender (E1,E2)              =>  (31, 2)
R is                        =>  31
Enter pt : 2
CT is (C1,C2)      =>  (8, 16)
Sending C1...
Sending C2...
'''




