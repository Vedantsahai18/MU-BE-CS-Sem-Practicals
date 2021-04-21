from collections import deque

def D2B(num, bin):
	c = 0
	while(num > 0):
		c = c+1
		temp = num%2
		num = int(num/2)
		bin.insert(0,temp)
	return c

def B2D(arr):
	arr.reverse()
	sum = 0
	num = 0
	while(num != len(arr)-1):
		if(arr[num] == 1):
			sum = sum + 2**num
		num = num + 1
	arr.reverse()
	return sum

md = int(input("Enter Multiplicand: "))
M = []
c1 = D2B(abs(md), M)
M.insert(0,0)
c1 = c1+1

mr = int(input("Enter Multiplier: "))
Q = []
c2 = D2B(abs(mr), Q)

while(c1 != c2):
	Q.insert(0,0)
	c2 = c2+1

def complement(bin, new):
		bin.reverse()
		check = False
		for i, ele in enumerate(bin):
			if(not bool(check) and ele == 1):
				check = True
				new[i] = 1
			elif(not bool(check) and ele == 0):
				new[i] = 0
			elif(bool(check) and ele == 1):
				new[i] = 0
			elif(bool(check) and ele == 0):
				new[i] = 1
		bin.reverse()
		new.reverse()

CQ = []
CM = []

steps = 0
A = []
while(steps != c1):
	A.append(0)
	steps = steps + 1


def add(A, Q):
	carry = 0
	i = 0
	A.reverse()
	Q.reverse()
	while(i < len(A)):
		a = A[i]
		m = Q[i]
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
	Q.reverse()

steps = 1

def rs(arr):
	arr = deque(arr)
	arr.rotate(1)
	arr = list(arr)
	return arr

if(md < 0):
	CM = M.copy()
	complement(CM, M)

if(mr < 0):
	CQ = Q.copy()
	complement(CQ, Q)

print("\nMultiplicand is")
print(*M, sep = ' ')
print("Multiplier is")
print(*Q, sep = ' ')
print("Complement of Multiplicand is")
print(*CM, sep = ' ')
print("Complement of Multiplier is")
print(*CQ, sep = ' ')

e = 0
steps = 1
print(f"\nAccumuator-> ", *A, sep = ' ')
print(f"Q-> ", *Q, sep = ' ')
print("")
while(steps <= c1):
	if((Q[-1] == 0 and e == 0) or (Q[-1] == 1 and e == 1)):
		print(f"1->1/0->0 RS Step:{steps}")
		e = Q[-1]
		Q = rs(Q)
		Q[0] = A[-1]
		A = rs(A)
		A[0] = A[1]
	elif(Q[-1] == 1 and e == 0):
		print(f"0->1 SUB Step:{steps}")
		e = Q[-1]
		CM = M.copy()
		complement(M, CM)
		add(A, CM)
		Q = rs(Q)
		Q[0] = A[-1]
		A = rs(A)
		A[0] = A[1]

	elif(Q[-1] == 0 and e == 1):
		print(f"1->0 ADD Step:{steps}")
		e = Q[-1]
		add(A, M)
		Q = rs(Q)
		Q[0] = A[-1]
		A = rs(A)
		A[0] = A[1]

	print(f"Accumuator->", *A, sep = ' ')
	print(f"Q->", *Q, sep = ' ')

	print("-----------\n")
	steps = steps + 1

A.extend(Q)
if(A[0] == 1):
	CA = A.copy()
	complement(A, CA)
	dec = -B2D(CA)
else:
	dec = B2D(A)
print(f"Final Accumulator is:", *A, sep = ' ')
print(f"Decimal-> {dec}")

'''
Enter Multiplicand: 6
Enter Multiplier: 7

Multiplicand is
0 1 1 0
Multiplier is
0 1 1 1
Complement of Multiplicand is

Complement of Multiplier is


Accumuator->  0 0 0 0
Q->  0 1 1 1

0->1 SUB Step:1
Accumuator-> 1 1 0 1
Q-> 0 0 1 1
-----------

1->1/0->0 RS Step:2
Accumuator-> 1 1 1 0
Q-> 1 0 0 1
-----------

1->1/0->0 RS Step:3
Accumuator-> 1 1 1 1
Q-> 0 1 0 0
-----------

1->0 ADD Step:4
Accumuator-> 0 0 1 0
Q-> 1 0 1 0
-----------

Final Accumulator is: 0 0 1 0 1 0 1 0
Decimal-> 42



Enter Multiplicand: 6
Enter Multiplier: -7

Multiplicand is
0 1 1 0
Multiplier is
1 0 0 1
Complement of Multiplicand is

Complement of Multiplier is
0 1 1 1

Accumuator->  0 0 0 0
Q->  1 0 0 1

0->1 SUB Step:1
Accumuator-> 1 1 0 1
Q-> 0 1 0 0
-----------

1->0 ADD Step:2
Accumuator-> 0 0 0 1
Q-> 1 0 1 0
-----------

1->1/0->0 RS Step:3
Accumuator-> 0 0 0 0
Q-> 1 1 0 1
-----------

0->1 SUB Step:4
Accumuator-> 1 1 0 1
Q-> 0 1 1 0
-----------

Final Accumulator is: 1 1 0 1 0 1 1 0
Decimal-> -42



Enter Multiplicand: -6
Enter Multiplier: 7

Multiplicand is
1 0 1 0
Multiplier is
0 1 1 1
Complement of Multiplicand is
0 1 1 0
Complement of Multiplier is


Accumuator->  0 0 0 0
Q->  0 1 1 1

0->1 SUB Step:1
Accumuator-> 0 0 1 1
Q-> 0 0 1 1
-----------

1->1/0->0 RS Step:2
Accumuator-> 0 0 0 1
Q-> 1 0 0 1
-----------

1->1/0->0 RS Step:3
Accumuator-> 0 0 0 0
Q-> 1 1 0 0
-----------

1->0 ADD Step:4
Accumuator-> 1 1 0 1
Q-> 0 1 1 0
-----------

Final Accumulator is: 1 1 0 1 0 1 1 0
Decimal-> -42



Enter Multiplicand: -6
Enter Multiplier: -7

Multiplicand is
1 0 1 0
Multiplier is
1 0 0 1
Complement of Multiplicand is
0 1 1 0
Complement of Multiplier is
0 1 1 1

Accumuator->  0 0 0 0
Q->  1 0 0 1

0->1 SUB Step:1
Accumuator-> 0 0 1 1
Q-> 0 1 0 0
-----------

1->0 ADD Step:2
Accumuator-> 1 1 1 0
Q-> 1 0 1 0
-----------

1->1/0->0 RS Step:3
Accumuator-> 1 1 1 1
Q-> 0 1 0 1
-----------

0->1 SUB Step:4
Accumuator-> 0 0 1 0
Q-> 1 0 1 0
-----------

Final Accumulator is: 0 0 1 0 1 0 1 0
Decimal-> 42
'''
