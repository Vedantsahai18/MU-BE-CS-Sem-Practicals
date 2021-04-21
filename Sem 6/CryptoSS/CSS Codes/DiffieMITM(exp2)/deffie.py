#Name:Vedant Sahai
#Roll No:8364
#Batch: C

def modulus(tocompute,modulo):
    result = 0
    for i in tocompute:
        result = (result*10 + int(i))%modulo
    return result

def isPrime2(n):
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    for i in range(3,int(n**0.5)+1,2):   # only odd numbers
        if n%i==0:
            return False    
    return True

def __gcd(a, b):
    # Everything divides 0  
    if (a == 0 or b == 0): 
        return 0
    # base case 
    if (a == b): 
        return a 
    # a is greater 
    if (a > b):  
        return __gcd(a - b, b) 
    return __gcd(a, b - a) 
  
# Function to check and print if  
# two numbers are co-prime or not  
def coprime(a, b): 
    if ( __gcd(a, b) == 1): 
        return 1
    else: 
        return 0

def coprime_driver(q):
    i = 2
    ls = []
    for i in range(2, q-1):
        if coprime(q, i) == 1:
            ls.append(i)
        else:
            continue
    for i in ls:
        if isPrime2(i) and i%2!=0:
            return i
# base = int(input("Enter base"))
# exponent = int(input("Enter exponent"))
# print(modulus(str(base**exponent),23))
