import numpy as np

reg_1 = np.empty
reg_2 = np.empty
reg_3 = np.empty

def user_input():
    usrinput = np.array(list(map(int,(input("Enter the 64 bit key with space between the elements ").strip().split()))), dtype=bool)
    if len(usrinput) == 64:
        return usrinput
    else:
        while len(usrinput) != 64:
            if len(usrinput) == 64:
                return usrinput
            usrinput = np.array(list(map(int,(input("Enter the 64 bit key with space between the elements ").strip().split()))), dtype=bool)
        return usrinput

def load_key(key):

    global reg_1
    global reg_2
    global reg_3
    reg_1 = key[0:19]
    reg_2 = key[19:41]
    reg_3 = key[41:64]
    print("registers loaded succesfully")

def to_binary(plain):
	s = ""
	i = 0
	for i in plain:
		binary = str(' '.join(format(ord(x), 'b') for x in i))
		j = len(binary)
		while(j < 8):
			binary = "0" + binary
			s = s + binary
			j = j + 1
	binary_values = []
	k = 0
	while(k < len(s)):
		binary_values.insert(k, int(s[k]))
		k = k + 1
	return binary_values


def get_majority(a,b,c):
    if int(a) + int(b) + int(c) > 1:
        return True
    else:
        return False

def clock_a5(length):
	global reg_1
	global reg_2
	global reg_3
	keystream = []
	i = 0

	while i < length:
		majority = get_majority(reg_1[8], reg_2[10], reg_3[10])
		if reg_1[8] == majority:
			first_bit = int(reg_1[18]) ^ int(reg_1[17]) ^ int(reg_1[16]) ^ int(reg_1[13])
			temp_arr1 = np.empty_like(reg_1)
			temp_arr1[0] = first_bit
			temp_arr1[1:] = reg_1[:18]
			reg_1 = temp_arr1


		if reg_2[10] == majority:
			first_bit = int(reg_2[20]) ^ int(reg_2[21])
			temp_arr2 = np.empty_like(reg_2)
			temp_arr2[0] = first_bit
			temp_arr2[1:] = reg_2[:21]
			reg_2 = temp_arr2

		if reg_3[10] == majority:
			first_bit = int(reg_3[20]) ^ int(reg_3[21]) ^ int(reg_3[22])
			temp_arr3 = np.empty_like(reg_3)
			temp_arr3[0] = first_bit
			temp_arr3[1:] = reg_3[:22]
			reg_3 = temp_arr3

		keystream.insert(i, int(reg_1[18]) ^ int(reg_2[21]) ^ int(reg_3[22]))
		i = i + 1

	return keystream




def main():
	key = user_input()
	load_key(key)
	plain_text = input("Please enter plain text ")
	encrypt = ""
	i = 0
	binary = to_binary(plain_text)
	keystream = clock_a5(len(binary))
	while(i < len(binary)):
		encrypt = encrypt + str(binary[i] ^ keystream[i])
		i = i + 1
	print("Encrypted Plaintext: "+ encrypt)
main()


'''
Enter the 64 bit key with space between the elements 0 1 0 1 0 0 1 0 0 0 0 1 1 0 1 0 1 1 0 0 0 1 1 1 0 0 0 1 1 0 0 1 0 0 1 0 1 0 0 1 0 0 0 0 0 0 1 1 0 1 1 1 1 1 1 0 1 0 1 1 0 1 0 1 
registers loaded succesfully
Please enter plain text elvis
Encrypted Plaintext: 1011110111100110101110011110100001001011
'''