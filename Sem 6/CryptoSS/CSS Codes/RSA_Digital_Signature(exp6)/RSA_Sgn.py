import socket
import math
import time
import fractions

def modInverse(a, m) : 
    a = a % m
    for x in range(1, m) : 
        if ((a * x) % m == 1) : 
            return x 
    return 1
		

p = 11
q = 7

n = p*q

Phi = (p-1)*(q-1)

print Phi

e = Phi-2

# Calc public key (e)

while e>1:
	#print ("GCD",math.gcd(e,Phi))
	if fractions.gcd(e,Phi) == 1:
		break
	else:
		e = e - 1
	
print e	
# Calc private key (d)


d = modInverse(e,Phi)

print d

print "Enter plain text"

pt = input()

ds = (int(pt)**d)%n

print ds

#send(ds)

v = (ds**e)%n

print v



