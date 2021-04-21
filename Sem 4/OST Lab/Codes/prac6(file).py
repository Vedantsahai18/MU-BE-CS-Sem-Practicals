'''
 Title   : File Analysis
 Name    : Kevlyn Kadamala
 Roll no.: 8340
 '''

import hashlib, os

def MD5():
    testFile = open('Test.txt', 'rb')
    hash = hashlib.md5()
    while True:
        piece = testFile.read(1024)

        if piece:
            hash.update(piece)
        else: # we're at end of file
            hex_hash = hash.hexdigest()
            break

    print (f"For MD5 - {hex_hash}")

def SHA1():
    testFile = open('Test.txt', 'rb')
    BLOCKSIZE = 65536
    hash = hashlib.sha1()
    while True:

        piece = testFile.read(BLOCKSIZE)

        if piece:
            hash.update(piece)
        else: # we're at end of file
            hex_hash = hash.hexdigest()
            break

    print (f"For SHA1 - {hex_hash}\n")

def read(txtfile):
    file = open(txtfile, 'r')
    print(file.read())
    file.close()

def reverse():
    with open('Test.txt', 'r') as readf, open ('New.txt', 'w') as writef:
        lines = list(map(lambda word : word.split(" "), readf.readlines()))
        for line in reversed(lines):
            for word in reversed(line):
                text = str(word).split('\n')
                for txt in text:
                    writef.write(str(txt))
                writef.write(' ')
            writef.write('\n')
    print("Reversing word order\n")
    read('New.txt')

def count():
    count = 0
    with open('Test.txt', 'r') as readf:
        lines = list(map(lambda word : word.split(" "), readf.readlines()))
        for line in lines:
            for word in line:
                    count = count + 1

    print(f"Word count in file is {count}")

file = open('Test.txt', 'w')
file.write("This is the first line in my file\n")
file.write("This is the second line\n")
file.close()

print("Before editing\n")
read('Test.txt')

MD5()
SHA1()

file = open('Test.txt', 'a')
file.write("This is after editing\n")
file.close()

print("\nAfter editing\n")
read('Test.txt')

MD5()
SHA1()

reverse()
count()


'''
Before editing

This is the first line in my file
This is the second line

For MD5 - 55eb42d47eb34f7d8f9b080a352cf4fa
For SHA1 - 8cdd3f1f5fd84684e09b76e1fbaab702c920c7c3


After editing

This is the first line in my file
This is the second line
This is after editing

For MD5 - 3de44b1ba48f430a48dee2c1beafd59b
For SHA1 - 42d297da6a218ac93fb694cad7a2acb1fda87f52

Reversing word order

editing after is This
line second the is This
file my in line first the is This

Word count in file is 17
'''
