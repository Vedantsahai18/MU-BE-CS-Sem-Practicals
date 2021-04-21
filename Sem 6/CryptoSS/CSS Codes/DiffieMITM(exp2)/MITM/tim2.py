import socket
import time
s = socket.socket()
host = socket.gethostname()
port = 12239
sharedPrime = 11    # n
sharedBase = 7      # g
MaliceSecret = 8     # a
MbobSecret = 6     # b
A = (sharedBase**MaliceSecret) % sharedPrime
B = (sharedBase**MbobSecret) % sharedPrime

s.bind((host,port))
s.listen(5)
print('Waiting for Alice and bob to communicate')
c, addr = s.accept()
print('TIM') 
print('got connection from ', addr)
fromA = c.recv(1024)

Ai = float(fromA)
print('A Received from alice = ',fromA) 
print('Send modified B to Alice ',B)
c.send(str(B))


s2 = socket.socket()
host = socket.gethostname()
port = 12238
s2.connect((host,port))
#print 'Waiting for Alice and bob to communicate'
#c, addr = s2.accept()
#print 'TIM' 
#print 'got connection from ', addr
#fromA = s2.recv(1024)

#Ai = float(fromA)
print('A Received from alice = ',fromA) 
print('Send modified B to Alice ',B)
s2.send(str(B))


#s2.listen(5)
#c, addr = s2.accept()
#time.sleep(10)
#portt = 12238 

#s.connect((host,portt))
print('Send modified A to BOB..... A =',A)
 

s2.send(str(A))
Bo = s2.recv(1024)
Bi = float(Bo)

print('B received from bob ',Bi)

aliceSharedSecret = (Bi ** MaliceSecret) % sharedPrime
print('Alice Shared key',aliceSharedSecret)
bobSharedSecret = (Ai ** MbobSecret) % sharedPrime

   
print('BOB Shared key= ',bobSharedSecret)

# OUTPUT
# Waiting for Alice and bob to communicate
# TIM
# got connection from  ('192.168.43.100', 60544)
# A Received from alice =  2
# Send modified B to Alice  4
# A Received from alice =  2
# Send modified B to Alice  4
# Send modified A to BOB..... A = 9
# B received from bob  8.0
# Alice Shared key 5.0
# BOB Shared key=  9.0