from collections import deque

def D2B(num, bin):
	c = 0
	while(num > 0):
		c = c+1
		temp = num%2
		num = int(num/2)
		bin.insert(0,temp)
	return c

dd = int(input("Enter Dividend: "))
Q = []
c1 = D2B(abs(dd), Q)
Q.insert(0,0)
c1 = c1+1

ds = int(input("Enter Divisor: "))
M = []
c2 = D2B(abs(ds), M)

while(c1 != c2):
	M.insert(0,0)
	c2 = c2+1
print("\nDividend is")
print(*Q, sep = ' ')
print("Divisor is")
print(*M, sep = ' ')


def comp(bin, new):
		bin.reverse()
		check = False
		for i, ele in enumerate(bin):
			if(not bool(check) and ele == 1):
				check = True
				new.insert(0, 1)
			elif(not bool(check) and ele == 0):
				new.insert(0, 0)
			elif(bool(check) and ele == 1):
				new.insert(0, 0)
			elif(bool(check) and ele == 0):
				new.insert(0, 1)
		bin.reverse()

CQ = []
CM = []
comp(Q, CQ)
print("Complement of Dividend is")
print(*CQ, sep = ' ')
comp(M, CM)
print("Complement of Divisor is")
print(*CM, sep = ' ')

steps = 0
A = []
while(steps != c1):
	A.append(0)
	steps = steps + 1


def add(A, M):
	carry = 0
	i = 0
	A.reverse()
	M.reverse()
	while(i < len(A)):
		a = A[i]
		m = M[i]
		if((a + m > 1) and carry == 0):
			carry = 1
			A[i] = 0

		elif((a + m > 1) and carry == 1):
			carry = 1
			A[i] = 1

		elif((a + m == 1) and carry == 0):
			carry = 0
			A[i] = 1
		elif((a + m == 1) and carry == 1):
			carry = 1
			A[i] = 0
		elif((a + m == 0) and carry == 1):
			carry = 0
			A[i] = 1
		i = i + 1
	A.reverse()
	M.reverse()

steps = 1

def ls(arr):
	arr = deque(arr)
	arr.rotate(-1)
	arr = list(arr)
	return arr

while(steps <= c1):
	print(f"\nStep{steps}")
	A = ls(A)
	A[-1] = Q[0]
	Q = ls(Q)
	add(A, CM)
	if(A[0] == 1):
		add(A, M)
		Q[-1] = 0
	elif(A[0] == 0):
		Q[-1] = 1
	print("A->", *A, sep = ' ')
	print("Q->", *Q, sep = ' ')
	steps = steps + 1

print("\nRemainder is: ")
print(*A, sep = ' ')
print("Quotient is: ")
print(*Q, sep = ' ')

'''
Enter Dividend: 19
Enter Divisor: 7

Dividend is
0 1 0 0 1 1
Divisor is
0 0 0 1 1 1
Complement of Dividend is
1 0 1 1 0 1
Complement of Divisor is
1 1 1 0 0 1

Step1
A-> 0 0 0 0 0 0
Q-> 1 0 0 1 1 0

Step2
A-> 0 0 0 0 0 1
Q-> 0 0 1 1 0 0

Step3
A-> 0 0 0 0 1 0
Q-> 0 1 1 0 0 0

Step4
A-> 0 0 0 1 0 0
Q-> 1 1 0 0 0 0

Step5
A-> 0 0 0 0 1 0
Q-> 1 0 0 0 0 1

Step6
A-> 0 0 0 1 0 1
Q-> 0 0 0 0 1 0

Remainder is:
0 0 0 1 0 1
Quotient is:
0 0 0 0 1 0

Enter Dividend: 7
Enter Divisor: 3

Dividend is
0 1 1 1
Divisor is
0 0 1 1
Complement of Dividend is
1 0 0 1
Complement of Divisor is
1 1 0 1

Step1
A-> 0 0 0 0
Q-> 1 1 1 0

Step2
A-> 0 0 0 1
Q-> 1 1 0 0

Step3
A-> 0 0 0 0
Q-> 1 0 0 1

Step4
A-> 0 0 0 1
Q-> 0 0 1 0

Remainder is:
0 0 0 1
Quotient is:
0 0 1 0
'''
