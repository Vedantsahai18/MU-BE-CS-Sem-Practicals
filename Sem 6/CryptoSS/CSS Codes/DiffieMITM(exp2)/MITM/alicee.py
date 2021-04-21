import socket 

s = socket.socket()

host = socket.gethostname()

port = 12239

sharedPrime = 11    #n 
sharedBase = 7      # g
aliceSecret = 3
A = (sharedBase**aliceSecret) % sharedPrime
	
s.connect((host,port))

print('Alice') 
print('Alice A = ',A)
print('sending A to Bob (tim)')
s.send(str(A))

print(' waiting for B from bob(tim)....')
B = s.recv(1024)
Bi = float(B)
   
print('B received from Bob "tim" = ',Bi)
    
aliceSharedSecret = (Bi ** aliceSecret) % sharedPrime

   
print('Alice Shared key= ',aliceSharedSecret)
s.close()

# OUTPUT
# Alice
# Alice A =  2
# sending A to Bob (tim)
#  waiting for B from bob(tim)....
# B received from Bob "tim" =  4.0
# Alice Shared key=  9.0
