'''
 Title   : Control Statements
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

'''PS 1:Check if a Number is positive, negative or 0'''
print("Check if a Number is positive, negative or 0")
while True:
    num=int(input("Enter a number: "))
    if num>0:
            print("The number is positive")
    elif num==0:
            print("The number is zero")
    else:
            print("The number is negative")
    p=int(input('If you want to end loop enter 0: '))
    if p==0:
        break

print("-----------x-----------\n")
'''PS 2:Check if a Number is odd or even'''
print("Check if a Number is odd or even")
while True:
    y=int(input('Enter the number to be checked: '))
    if y%2==0:
        print('Entered number is even.')
    else:
        print('Entered number is odd.')
    i=int(input('Enter 0 to end the loop: '))
    if i==0:
        break

print("-----------x-----------\n")
'''PS 3:Check if a Leap Year'''
print("Check if a Leap Year")
while True:
    y=int(input('Enter the year to be checked: '))
    if(y%1000!=0 and y%4==0):
        print("Entered year is a leap year")
    else:
        print("Entered year is not a leap year")
    i=int(input('Enter 0 to end the loop: '))
    if i==0:
        break

print("-----------x-----------\n")
'''PS 4:Finding the largest number among three'''
print("Finding the largest number among three")
a=int(input("Enter 1st number: "))
b=int(input("Enter 2nd number: "))
c=int(input("Enter 3rd number: "))
if a>=b:
    if a>=c:
        print(f"The largest value is: {a}")
    else:
        print(f"The largest value is: {c}")
else:
    if b>=c:
        print(f"The largest value is: {b}")
    else:
        print(f"The largest value is: {c}")

print("-----------x-----------\n")
'''PS 5:Count number of vowels and consonants from the string'''
print("Count number of vowels and consonants from the string")
q=w=0
a=input("Enter the string: ")
for i in a:
    if i.isalpha():
        if i=='a' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U':
            q+=1
        else:
            w+=1
print(f"The number of consonants are {w} and vowels are {q}")

print("-----------x-----------\n")
'''PS 6:Demonstrating sorting algorithm using lists'''
print("Demonstrating sorting algorithm using lists")
def bubble_sort(li):
    for i in range(0,len(li)):
        for j in range(i,len(li)):
            if li[i]>li[j]:
                temp=li[i]
                li[i]=li[j]
                li[j]=temp
def display_list(li):
    for i in li:
        print(i,end=' ')
    print()
n=int(input('Enter the size of the list: '))
li=[]
for i in range(0,n):
    li.append(int(input(f'Enter the element {i}: ')))
print('The list before sorting: ')
display_list(li)
bubble_sort(li)
print('The list after sorting: ')
display_list(li)

print("-----------x-----------\n")
'''PS 7:Demonstrating searching algorithm using lists'''
print("Demonstrating searching algorithm using lists")
def lSearch(li,n):
    for i in range(0,len(li)):
        if n==li[i]:
            print('Element '+str(li[i])+' found at location '+str(i+1))
            return
    print('Element not present in list')

n=int(input('Enter the size of the list: '))
li=[]
for i in range(0,n):
    li.append(int(input(f'Enter the element {i}: ')))
m=int(input('Enter the element to be found: '))
lSearch(li,m)

'''
Check if a Number is positive, negative or 0
Enter a number: 1
The number is positive
If you want to end loop enter 0: 1
Enter a number: -1
The number is negative
If you want to end loop enter 0: 1
Enter a number: 0
The number is zero
If you want to end loop enter 0: 0
-----------x-----------

Check if a Number is odd or even
Enter the number to be checked: 1
Entered number is odd.
Enter 0 to end the loop: 4
Enter the number to be checked: 4
Entered number is even.
Enter 0 to end the loop: 0
-----------x-----------

Check if a Leap Year
Enter the year to be checked: 2012
Entered year is a leap year
Enter 0 to end the loop: 1
Enter the year to be checked: 2014
Entered year is not a leap year
Enter 0 to end the loop: 0
-----------x-----------

Finding the largest number among three
Enter 1st number: 1
Enter 2nd number: 5
Enter 3rd number: 3
The largest value is: 5
-----------x-----------

Count number of vowels and consonants from the string
Enter the string: hEllO
The number of consonants are 3 and vowels are 2
-----------x-----------

Demonstrating sorting algorithm using lists
Enter the size of the list: 4
Enter the element 0: 1
Enter the element 1: 2
Enter the element 2: 9
Enter the element 3: 3
The list before sorting:
1 2 9 3
The list after sorting:
1 2 3 9
-----------x-----------

Demonstrating searching algorithm using lists
Enter the size of the list: 5
Enter the element 0: 7
Enter the element 1: 4
Enter the element 2: 3
Enter the element 3: 6
Enter the element 4: 9
Enter the element to be found: 3
Element 3 found at location 3
'''
