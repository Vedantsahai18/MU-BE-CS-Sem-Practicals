
import socket
from Crypto.Util import number
import timeit

start = timeit.default_timer()

def PrimeNum():
    n_length =5
    #2 raised to 355 is around 100 digit number
    primeNum = number.getPrime(n_length)
    return primeNum

def Gcd(x, y):

   # This function implements the Euclidian algorithm to find H.C.F. of two numbers
    while(y):
       x, y = y, x % y

    return x

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

s= socket.socket()
host = socket.gethostname()
port =5002

s.connect((host,port))
print(s.recv(5002).decode())
msg='From Receiver'
s.send(msg.encode())
	
p=PrimeNum()
q=PrimeNum()
print('Prime No. p       => ',p)
print('Prime No. q       => ',q)

N=p*q
print("N = p*q           => ",N)

f=(p-1)*(q-1)
print('phi = (p-1)*(q-1) => ',f)

for i in range(f-1,1,-1): #(start,stop,step)
    if (Gcd(f,i)==1):
        e=i
        print("Public Key of Receiver (e) => ",e)
        break

d=modinv(e,f)
print("Private Key of Receiver (d) => ",d)

e=str(e)
s.send(e.encode())
temp=input("sending N...")
N=str(N)
s.send(N.encode())

ct = int(s.recv(5002).decode())
print("Received CT => ",ct)
d=int(d)
N=int(N)
pt=str((ct**d)%N)
print("Decrypted PT => ",pt)
stop = timeit.default_timer()

print('Time: ', stop - start) 
s.close
'''
Connected to Sender
Prime No. p       =>  31
Prime No. q       =>  23
N = p*q           =>  713
phi = (p-1)*(q-1) =>  660
Public Key of Receiver (e) =>  659
Private Key of Receiver (d) =>  659
sending N...
Received CT =>  357
Decrypted PT =>  2
Time:  70.12973559999999
 '''
