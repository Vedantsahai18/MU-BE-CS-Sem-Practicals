
kw = []
op = []
sc = []
idty = []
keywords = "auto break case char const continue default do double else enum extern float for goto if int long register return short signed sizeof static struct switch typedef union unsigned void volatile while"
kwList = keywords.split()
operators = "+ - * / % ++ -- < = <= > >= == != && || ! ?: & | << >> ~ ^ += -= *= /= %= "
oplist = operators.split()
schar = "{ } ( ) $ @ "
scharlist = schar.split()


inputFile = open('exp5a.txt', 'r' )
tokens = inputFile.read().split()

for token in tokens:
    for keyword in kwList:
        if keyword in token:
            kw.append(keyword)
    if token in oplist:
        op.append(token)
    elif token in scharlist:
        sc.append(token)
    else :
        idty.append(token)
        
        

print(kw)
print("number of keywords is ", len(kw))
print(op)
print("number of operators is ", len(op))
print(sc)
print("number of special characters is ", len(sc))
print(idty)
print("number of identifiers is ", len(idty))

'''
Input:
$ a = b + c - d * 40
Output:
[]
number of keywords is  0
['=', '+', '-', '*']
number of operators is  4
['$']
number of special characters is  1
['a', 'b', 'c', 'd', '40']
number of identifiers is  5
'''