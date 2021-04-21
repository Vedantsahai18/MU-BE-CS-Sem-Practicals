import math
import socket
import pickle
from   Crypto.Util import number
 
def PrimeNum():         # Returns a 100-digit Prime Number
    n_length = 5     # 2 raised to 355 is around 100 digit number
    primeNum = number.getPrime(n_length)        # getPrime() takes number of bits as parameter
    return primeNum

s    = socket.socket()
host = socket.gethostname()
port = 5002

s.connect((host,port))
print(s.recv(5002).decode())
msg='From Receiver'
s.send(msg.encode())
	
p = int(s.recv(5002).decode())
print("Received p => ",p)

d = int(s.recv(5002).decode())
print("Received d => ",d)


C1 = int(s.recv(5002).decode())
print("Received C1=> ",C1)

C2 = int(s.recv(5002).decode())
print("Received C2=> ",C2)

x=1
while(not ((C1**d)*x)%p==1):
    x=x+1

pt=(C2*x)%p

print("Decrypted PT => ",pt)

s.close

'''
**OUTPUT**
EXAMPLE 1

Connected to Sender
Received p =>  11
Received d =>  3
Received C1=>  5
Received C2=>  6
Decrypted PT =>  7
'''
'''
EXAMPLE 2

Connected to Sender
Received p =>  29
Received d =>  29
Received C1=>  8
Received C1=>  16
Decrypted PT =>  2
'''