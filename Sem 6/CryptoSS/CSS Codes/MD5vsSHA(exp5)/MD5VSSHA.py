import hashlib as hl
import time
def MD5():
    f = open('exp5text.txt','rb')
    contents = f.read()


    start = time.time()

    print("The content is : ")
    print(contents)
    print("The MD5 hash is as follows : ")

    x = hl.md5(contents)

    print(x.digest())

    stop = time.time()

    time_taken = start-stop

    print(time_taken)

def SHA():
    f = open('exp5text.txt','rb')
    contents = f.read()


    start = time.time()

    print("The content is : ")
    print(contents)
    print("The SHA hash is as follows : ")

    x = hl.sha1(contents)

    print(x.digest())

    stop = time.time()

    time_taken = start-stop

    print(time_taken)

MD5()
SHA()

'''
OUTPUT

The content is :
b'qazwsxedcrfvtgyhnujmiklop'
The MD5 hash is as follows :
b'O\xa4[^\x00Y\x16\xe5\xe7\x9c\xd0\x8e\xe1h\x81\xdc'
-0.003900289535522461
The content is :
b'qazwsxedcrfvtgyhnujmiklop'
The SHA hash is as follows :
b'n\xf1^\x96\x93\xad\r)q\xd4u\xab\x1a\xd0\xf8\x89\\g\xb6\x90'
-0.007976770401000977

'''