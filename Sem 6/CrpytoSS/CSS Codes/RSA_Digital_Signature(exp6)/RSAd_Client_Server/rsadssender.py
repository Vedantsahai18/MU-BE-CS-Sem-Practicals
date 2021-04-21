import socket
import hashlib
from Crypto.Util import number

def PrimeNum():         # Returns a 100-digit Prime Number
    n_length =354       # 2 raised to 354 is around 100 digit number
    primeNum = number.getPrime(n_length)        # getPrime() takes number of bits as parameter
    return primeNum

def power(x, y, p) :    # Computes fast-growth modular exponentiation
    res = 1             # Initialize result 
                        # Update x if it is more 
                        # than or equal to p 
    x = x % p  
    while (y > 0) : 
          
        # If y is odd, multiply 
        # x with result 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
  
        # y must be even now 
        y = y >> 1      # y = y/2 
        x = (x * x) % p 
          
    return res


def Gcd(x, y):  # Implements the Euclidian algorithm to find H.C.F. of two numbers
    while(y):
       x, y = y, x % y

    return x

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):       #Computes Modular Inverse of a number
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m

 
s = socket.socket()
host = socket.gethostname()
port = 5002
s.bind((host,port))
s.listen(5)

c, addr = s.accept()
print('Connection from: ', addr)
msg='Connected to Sender'
c.send(msg.encode())
print(c.recv(5002).decode())
      
er=c.recv(5002).decode()
er=int(er)
print('Received Public Key of Receiver (er) => ',er)
Nr=c.recv(5002).decode()
Nr=int(Nr)
print('Received Nr = (p*q) => ',Nr)

pt=int(input('Enter pt : '))
ct=power(pt,er,Nr)
ct=str(ct)
print("Encrypted CT => ",ct)
temp=input("Sending CT...")
c.send(ct.encode())

p=PrimeNum()
q=PrimeNum()
print('Prime No. p       => ',p)
print('Prime No. q       => ',q)

Ns=p*q
print("Ns = p*q          => ",Ns)

f=(p-1)*(q-1)
print('phi = (p-1)*(q-1) => ',f)

for i in range(12345,f): 
    if (Gcd(f,i)==1):
        es=i    # es is between 1 to f such that gcd(es,f) = 1
        print("Public Key of Sender  (es) => ",es)
        break

ds=modinv(es,f)
print("Private Key of Sender (ds) => ",ds)

es=str(es)
Ns=int(Ns)
pt=str(pt)
ds=int(ds)

m = hashlib.md5()
m.update(pt.encode('utf-8'))
h=m.hexdigest()
h=int(h,16)
#h=18
print("MD5 Hash => ",h)
es=int(es)
sign=power(h,es,Ns)
sign=str(sign)
print("Sending Digital Signature => ",sign)

temp=input("Sending Digital Signature...")
c.send(sign.encode())

temp=input("Sending Public Key of Sender...")
ds = str(ds)
c.send(ds.encode())

Ns=str(Ns)
temp=input("Sending Ns...")
c.send(Ns.encode())

s.close

''' @@@@@@@@@@@@@ OUTPUT SENDER @@@@@@@@@@@@@@@@@@

Connection from:  ('127.0.0.1', 59700)
From Receiver
Received Public Key of Receiver (er) =>  54323
Received Nr = (p*q) =>  2723649638366887071438087567114189149926421741607856300514260875106145921840931899822578756412546172431670753545617918223549985189499454609591438343769579204192724668282084934006772504038786463115208898841669515923
Enter pt : 234
Encrypted CT =>  139143908187338307598404908887969219262504090827141545827489256932817972331575312103727787645645469721326211115352419125180813272190078004824575773872207138584982094685161188324307970434408968394950917844037015405
Sending CT...
Prime No. p       =>  25863297574674908571328179789523766266895935207404365022650283496506531569426520910620991589506418932459361
Prime No. q       =>  33187099801567809651338820029481269265681736610348551952721938504767103022135812552995075265143780468779719
Ns = p*q          =>  858327837808382870865566939319673360153209142517433816431953061251694690890297464119249118054055792825335066805468807480639102611451086805106902504858434074253621410050657368300784291389073493097087779159228499559
phi = (p-1)*(q-1) =>  858327837808382870865566939319673360153209142517433816431953061251694690890297464119249118054055792825335007755071431237920879944451267800071369927186616321336646037828656094666192729055609877030233128959827260480
Public Key of Sender  (es) =>  12347
Private Key of Sender (ds) =>  107125876574286709646378768404601656110479897029186483447123970793622865365023762226270583212221590406077690690091931281901358710164364111112819394006201972234532400120997735634615938728006383777726512653040723123
MD5 Hash =>  53989483038990520775444686317057812967
Sending Digital Signature =>  356199155976945161662937507188816963640482144767801842601984541446986966157075423605875506832823851881489722992836969791664681617563384437080322419551008785155501497859953511859833886087031925895386688424306053996
Sending Digital Signature...
Sending Public Key of Sender...
Sending Ns...

