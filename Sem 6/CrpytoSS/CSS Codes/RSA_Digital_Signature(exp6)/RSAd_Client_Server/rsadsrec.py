import math
import socket
import hashlib
from   Crypto.Util import number
 
def PrimeNum():         # Returns a 100-digit Prime Number
    n_length = 355      # 2 raised to 355 is around 100 digit number
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

s    = socket.socket()
host = socket.gethostname()
port = 5002

s.connect((host,port))
print(s.recv(5002).decode())
msg='From Receiver'
s.send(msg.encode())
	
p=PrimeNum()    # Prime no. 1
q=PrimeNum()    # Prime no. 2
print('Prime No. p       => ',p)
print('Prime No. q       => ',q)

Nr=p*q          # Product of two 100-digit primes
print("Nr = p*q          => ",Nr)

f=(p-1)*(q-1)
print('phi = (p-1)*(q-1) => ',f)

for i in range(54321,f): 
    if (Gcd(f,i)==1):
        er=i    # er is between 1 to f such that gcd(er,f) = 1
        print("Public Key of Receiver  (er) => ",er)
        break

dr=modinv(er,f)
dr=int(dr)
print("Private Key of Receiver (dr) => ",dr)

er=str(er)
temp=input("Sending er...")
s.send(er.encode())
temp=input("Sending Nr...")
Nr=str(Nr)
s.send(Nr.encode())

ct = int(s.recv(5002).decode())
print("Received CT => ",ct)
Nr=int(Nr)
pt=power(ct,dr,Nr)
print("Decrypted PT => ",pt)

sign = int(s.recv(5002).decode())
print("Received Digital Signature => ",sign)
ds = int(s.recv(5002).decode())
print("Receved Public Key of Sender (ds) => ",ds)
Ns = int(s.recv(5002).decode())
print('Received Ns=(p*q) => ',Ns)

h1=power(sign,ds,Ns)
print("Generated using ds and es Hash1 => ",h1)
m = hashlib.md5()
pt=str(pt)
m.update(pt.encode('utf-8'))
h2=m.hexdigest()
h2=int(h2,16)
#h2=18
print("Generated using md5 on pt Hash2 => ",h2)

if(h1==h2):
	print("Hash1 equals Hash2\nRSA as Digital Signature verfied!")

s.close

''' @@@@@@@@@@@@@@@@@ OUTPUT RECEIVER @@@@@@@@@@@@@@@@@@@@@@
Connected to Sender
Prime No. p       =>  46795887553131829718213873383727512158862760027886479693035667199699531454079152624791135315982743513296489
Prime No. q       =>  58202756284395036538304954354969137861384930151104879499662770610331889131049915502459335255736515836164507
Nr = p*q          =>  2723649638366887071438087567114189149926421741607856300514260875106145921840931899822578756412546172431670753545617918223549985189499454609591438343769579204192724668282084934006772504038786463115208898841669515923
phi = (p-1)*(q-1) =>  2723649638366887071438087567114189149926421741607856300514260875106145921840931899822578756412546172431670648546974080696683728670671715912941418096079400212833531969844274902586187374970659212644637179582320054928
Public Key of Receiver  (er) =>  54323
Private Key of Receiver (dr) =>  1183960064068546864218452585642075411637106253453011039161013867142030627880488299291467237706420214564760243263226367129420127180554128077760776225923070460502016161403138772705303990437883523505521829771126516891
Sending er...
Sending Nr...
Received CT =>  139143908187338307598404908887969219262504090827141545827489256932817972331575312103727787645645469721326211115352419125180813272190078004824575773872207138584982094685161188324307970434408968394950917844037015405
Decrypted PT =>  234
Received Digital Signature =>  356199155976945161662937507188816963640482144767801842601984541446986966157075423605875506832823851881489722992836969791664681617563384437080322419551008785155501497859953511859833886087031925895386688424306053996
Receved Public Key of Sender (ds) =>  107125876574286709646378768404601656110479897029186483447123970793622865365023762226270583212221590406077690690091931281901358710164364111112819394006201972234532400120997735634615938728006383777726512653040723123
Received Ns=(p*q) =>  858327837808382870865566939319673360153209142517433816431953061251694690890297464119249118054055792825335066805468807480639102611451086805106902504858434074253621410050657368300784291389073493097087779159228499559
Generated using ds and es Hash1 =>  53989483038990520775444686317057812967
Generated using md5 on pt Hash2 =>  53989483038990520775444686317057812967
Hash1 equals Hash2
RSA as Digital Signature verfied!
'''













































