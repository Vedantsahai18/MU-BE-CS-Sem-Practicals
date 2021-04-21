'''
 Title   : Basics of Python
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

import random

n = int(input("Enter your option:\n1:Area of triangle\n2:Area of square\n3:Area of rectangle\n"))
if n == 1:
	a = int(input("Enter the length of side 1:"))
	b = int(input("Enter the length of side 2:"))
	c = int(input("Enter the length of side 3:"))
	s = (a + b + c)/2
	A1 = pow((s*(s-a)*(s-b)*(s-c)),0.5)
	print (f"Area of triangle : {A1}")
elif n == 2 :
	side = int(input("Enter the length of the side: "))
	A2 = side*side
	print (f"Area of square :{A2}")
else :
	le = int(input("Enter the length :"))
	bd = int(input("Enter the breadth"))
	A3 = le*bd
	print (f"Area of rectangle :{A3}")


print("-------Quadratic equ-------\n")
a = int(input("Enter a:"))
b = int(input("Enter b:"))
c = int(input("Enter c:"))
d = b*b - 4 *a*c
x = (-b/(2.0*a))
if (d >= 0):
	a1 = x + (pow(d,0.5)/(2.0*a))
	a2 = x -(pow(d,0.5)/(2.0*a))
	print (f"Roots are :{a1} & {a2}")
else :
	am = pow(d,0.5)/(2.0*a)
	print (f"Roots are :{x} +i{am}  & {x} -i{am}")


print("--------Swap-------\n")
x = int(input("Enter x:"))
y = int(input("Enter y:"))
(x,y) = (y,x)
print (f"x = {x}  y = {y}")


print("-------Random no-------\n")
for i in range(0,10):
	print (random.randint(0,101))


print("--------Conversion-------\n")
cel = int(input("Enter the temperature in degree:"))
fr =(cel *9.0)/5 + 32
print (f"temperature in fahrenheit :{fr} F")
km = int(input("Enter the distance in km:"))
miles = km*0.62137
print (f"distance in miles :{miles} miles")

'''
Enter your option:
1:Area of triangle
2:Area of square
3:Area of rectangle
1
Enter the length of side 1:5
Enter the length of side 2:6
Enter the length of side 3:7
Area of triangle : 14.696938456699069
-------Quadratic equ-------

Enter a:1
Enter b:5
Enter c:6
Roots are :-2.0 & -3.0
--------Swap-------

Enter x:3
Enter y:6
x = 6  y = 3
-------Random no-------

26
21
74
64
64
59
37
61
98
75
--------Conversion-------

Enter the temperature in degree:100
temperature in fahrenheit :212.0 F
Enter the distance in km:4
distance in miles :2.48548 miles
'''
