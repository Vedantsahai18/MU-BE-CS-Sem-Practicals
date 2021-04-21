def buildWalsh( walsh , l , i1 , i2 , j1 , j2 , bar ):

    if l == 2:

        one = -1 if bar else 1

        walsh[i1][j1] = one
        walsh[i1][j2] = one
        walsh[i2][j1] = one
        walsh[i2][j2] = -one

        return


    midi = (i1+i2)//2
    midj = (j1+j2)//2

    nl = l//2

    buildWalsh( walsh , nl, i1, midi, j1, midj, bar); 
    buildWalsh( walsh , nl, i1, midi, midj + 1, j2, bar); 
    buildWalsh( walsh , nl, midi + 1, i2, j1, midj, bar); 
    buildWalsh( walsh , nl, midi + 1, i2, midj + 1, j2, not bar)


def showWalsh(walsh):
    print("*********")
    print("Walsh Table")
    for w in walsh:
        print(*w)
    print("*********")


def setup( walsh , chnlSeq ,  data ):

    for i , d in enumerate(data):
        w = matrix_dot_multiplication( walsh[i] , d)
        chnlSeq = matrix_addition( chnlSeq  , w )

    return chnlSeq


def listenTo( walsh , chnlSeq , source ):

    print("Listening to Channel", source)
    inner = sum(matrix_inner_product( walsh[source-1] , chnlSeq ))
    print("Data recieved is: " , inner//num_stations)
        

def matrix_addition(matrix_a , matrix_b):
    new_matrix = []
    for a , b in zip(matrix_a , matrix_b):
        new_matrix.append(a+b)
    return new_matrix

def matrix_dot_multiplication(matrix , scalar):
    new_matrix = []
    for element in matrix:
        new_matrix.append( element * scalar )
    return new_matrix

def matrix_inner_product(matrix_a , matrix_b):
    new_matrix = []
    for a , b in zip(matrix_a , matrix_b):
        new_matrix.append(a*b)
    return new_matrix




code = {
    0 : -1,
    1: 1
}
num_stations = 2
walshTable = [ [0 for _ in range (num_stations) ] for __ in range(num_stations) ]
chnlSeq =  [0 for _ in range (num_stations) ]
data = [] 

for i in range(0, num_stations):
    data.append(code[int(input("Enter 0 or 1 for input: "))])
print(data)

buildWalsh( walshTable, num_stations,  0 , num_stations-1 , 0 , num_stations-1 , False)
showWalsh(walshTable)

chnlSeq = setup( walshTable , chnlSeq , data )
print("Resultant Channel Sequence : ",chnlSeq)

print("Enter the channel number who's data you wish to receive : ")
n = int(input()) 
listenTo( walshTable , chnlSeq , n )

'''
Enter 0 or 1 for input: 1
Enter 0 or 1 for input: 0
[1, -1]
*********
Walsh Table
1 1
1 -1
*********
Resultant Channel Sequence :  [0, 2]
Enter the channel number who's data you wish to receive :
1
Listening to Channel 1
Data recieved is:  1

'''

    