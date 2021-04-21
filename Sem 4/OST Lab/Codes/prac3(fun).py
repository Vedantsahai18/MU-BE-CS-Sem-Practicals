'''
 Title   : Creating Functions
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

'''PS 1:Find Numbers divisible by given number'''
print("Find Numbers divisible by given number")
x = input('Enter the number: ')
y=input('Enter the limit: ')
x=int(x)
y=int(y)
print('The divisible numbers are')
for i in range(1,y):
    if i%x==0:
        print(i)

print("-----------x-----------\n")
'''PS 2:Convert decimal to binary, octal, hexadecimal'''
print("Convert decimal to binary, octal, hexadecimal")
import math
def con(x):
    a=[]
    b=[]
    k=i=j=s=s1=0
    stype=int(input("Enter the intial type for conversion 1.decimal 2.hex 3.octal 4.binary : "))
    etype=int(input("Enter the final type for conversion 1.decimal 2.hex 3.octal 4.binary : "))
    if stype==etype:
        print('The same number will be found: ',x)
        exit()
    elif stype==2 :
        s=16
    elif stype==3 :
	    s=8
    elif stype==4 :
    	s=2
    if s!=0:
        for i in range(0,len(x)):
            if x[i]=='.':
                k=i
                break
            a.append(x[i:i+1])
        for i in range(k+1,len(x)):
            b.append(x[i:i+1])
        x=float(0)
        a.reverse()
        for i in a :
            if i.isalpha():
                if i=='A':
                    x+=10*(s**j)
                elif i=='B':
                    x+=11*(s**j)
                elif i=='C':
                    x+=12*(s**j)
                elif i=='D':
                    x+=13*(s**j)
                elif i=='E':
                    x+=14*(s**j)
                elif i=='f':
                    x+=15*(s**j)
            else :
                i=int(i)
                x+=i*(s**j)
            j+=1
        j=-1
        for i in b :
            if i.isalpha():
                if i=='A':
                    x+=10*(s**j)
                elif i=='B':
                    x+=11*(s**j)
                elif i=='C':
                    x+=12*(s**j)
                elif i=='D':
                    x+=13*(s**j)
                elif i=='E':
                    x+=14*(s**j)
                elif i=='f':
                    x+=15*(s**j)
            else :
                i=int(i)
                x+=i*(s**j)
            j-=1
    i=j=0
    a=[]
    if etype==1 :
        e=10
    elif etype==2 :
	    e=16
    elif etype==3 :
	    e=8
    elif etype==4 :
    	e=2
    x=float(x)
    t=math.modf(x)
    x=t[1]
    r=t[0]
    while x!=0 :  #create before point
        s1=x%e
        x//=e
        if s1>9:
            if s1==10:
                a.append('A')
            elif s1==11:
                a.append('B')
            elif s1==12:
                a.append('C')
            elif s1==13:
                a.append('D')
            elif s1==14:
                a.append('E')
            elif s1==15:
                a.append('F')
        else:
            a.append(str(int(s1)))
        j+=1
    a.reverse()
    a.append('.')
    while (i<5):        #create after point
        r=r*e
        t=math.modf(r)
        r=t[0]
        i+=1
        if t[1]>9:
            if t[1]==10:
                a.append('A')
            elif t[1]==11:
                a.append('B')
            elif t[1]==12:
                a.append('C')
            elif t[1]==13:
                a.append('D')
            elif t[1]==14:
                a.append('E')
            elif t[1]==15:
                a.append('F')
        else:
            a.append(str(int(t[1])))

    print('The converted number is: ')
    for i in a:
        print(i,end="")
con(input('Enter the number (in float): '))

print("\n-----------x-----------\n")
'''PS 3:Factorial using recursion'''
print("Factorial using recursion")
def fact(x):
	if x==0:
		return 1
	else:
		return x*fact(x-1)
i=1
while i==1:
	x=int(input("Enter the no. to find factorial: "))
	print (fact(x))
	i=input("Enter 1 to exit: ")

print("-----------x-----------\n")
'''PS 4:Sum of n natural numbers using recursion'''
print("Sum of n natural numbers using recursion")
def sum(x):
    if x==1:
        return 1
    else:
        return x+sum(x-1)
i=1
while i==1:
    x=int(input("Enter the number to find sum: "))
    print("The sum is {}".format(sum(x)))
    i=input("Enter 1 to exit: ")

print("-----------x-----------\n")
'''PS 5:Displaying calendar'''
print("Displaying calendar")
import calendar
y=int(input("Enter the year: "))
m=int(input("Enter the month: "))
print(calendar.month(y,m))

print("-----------x-----------\n")
'''PS 6:Shuffling deck of cards'''
print("Shuffling deck of cards")
import random
def shuffle():
    sign = ['Hearts', 'Spades', 'Clubs', 'Diamonds']
    values = ['Ace', 'Jack', 'King', 'Queen']
    for i in range(2,11):
        values.append(str(i))

    print(f"Your card is {random.choice(values)} of {random.choice(sign)}")

shuffle()
shuffle()
shuffle()
shuffle()
shuffle()
shuffle()

'''
Find Numbers divisible by given number
Enter the number: 24
Enter the limit: 150
The divisible numbers are
24
48
72
96
120
144
-----------x-----------

Convert decimal to binary, octal, hexadecimal
Enter the number (in float): 10
Enter the intial type for conversion 1.decimal 2.hex 3.octal 4.binary : 1
Enter the final type for conversion 1.decimal 2.hex 3.octal 4.binary : 3
The converted number is:
12.00000
-----------x-----------

Factorial using recursion
Enter the no. to find factorial: 5
120
Enter 1 to exit: 1
-----------x-----------

Sum of n natural numbers using recursion
Enter the number to find sum: 6
The sum is 21
Enter 1 to exit: 1
-----------x-----------

Displaying calendar
Enter the year: 2012
Enter the month: 10
    October 2012
Mo Tu We Th Fr Sa Su
 1  2  3  4  5  6  7
 8  9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
29 30 31

-----------x-----------

Shuffling deck of cards
Your card is 7 of Hearts
Your card is 9 of Diamonds
Your card is 7 of Clubs
Your card is Ace of Hearts
Your card is Jack of Hearts
Your card is Ace of Hearts
'''
