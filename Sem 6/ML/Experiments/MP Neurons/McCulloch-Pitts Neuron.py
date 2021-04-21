def And(x):
    # Assume all weights = 1
    return sum(x) == len(x)

def Or(x):
    # Assume all weights = 1
    return sum(x) > 0

def Not(x):
    # Assume all weights = 1
    return x > 0

def Nand(x):
    # Assume all weights = 1
    return sum(x) < len(x)

def Nor(x):
    # Assume all weights = 1
    return sum(x) == 0

def Xor(x):
    X1 = Or(x)
    X2 = Nand(x)
    Y = And([X1, X2])
    return Y

print('And', And([True, True, True, True]))
print('And', And([True, True, True, False]))
print()
print('Or', Or([False, False, False, False]))
print('Or', Or([True, True, True, False]))
print()
print('Nor', Nor([False, False, False, False]))
print('Nor', Nor([True, True, True, False]))
print()
print('Xor', Xor([False, True]))
print('Xor', Xor([True, True]))

'''
OUTPUT:

And True
And False

Or False
Or True

Nor True
Nor False

Xor True
Xor False
'''