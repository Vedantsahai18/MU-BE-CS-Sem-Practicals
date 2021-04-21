import socket
s = socket.socket()
host = socket.gethostname()
port = 12238
sharedPrime = 11    # n
sharedBase = 7      # g
bobSecret = 9      # b
B = (sharedBase**bobSecret) % sharedPrime
s.bind((host,port))
#s.connect((host,port))
s.listen(5)
c, addr = s.accept()

print('Waiting ')

print('BOB') 


#print 'got connection from ', addr
fromA = c.recv(1024)
print('A Received from alice(Tim) = ',fromA) 
Ai = float(fromA)	
print(' BOB B = ',B)
print(' Sending B to Alice (tim)')
print('B sent  to Alice ',B)
c.send(str(B))
bobSharedSecret = (Ai ** bobSecret) % sharedPrime

   
print('BOB Shared key= ',bobSharedSecret)

s.close()

# OUTPUT
# Waiting 
# BOB
# A Received from alice(Tim) =  49
#  BOB B =  8
#  Sending B to Alice (tim)
# B sent  to Alice  8
# BOB Shared key=  9.0

