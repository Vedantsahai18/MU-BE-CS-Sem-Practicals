import fractions
import random


def modinv(a,m):
	a = a%m
	for x in range(1,m):
		if ((a*x)%m == 1):
			return x
	return 1

p = 11
q = 7

x = p-1

while x != q:
	x = x-1

y = (q**x)%p

# public key (p,q,y)

#r = random.randint(1,p)
r = 5

pt = input()

ct1 = (q**r)%p
ct2 = int(pt)*((y**r)%p)

# Encrypted Shit
print(ct1)
print(ct2)


# Lets decrypt

print("Lets decrypt")

b = modinv(-x,(p-1))

dt = ct2*(ct1**b)%p

print(dt)
