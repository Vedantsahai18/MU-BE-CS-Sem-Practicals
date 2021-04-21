mot = {
    'A': '5A',
    'L': '6A',
    'ST': '7A'
}
pot = ['DS', 'DC', 'START', 'USING']
print(mot)
print(pot)
inputList = []
with open("ainput.txt", "r") as f:
    for ip in f:
        inputList.append(ip.strip("\n").strip("\r"))
print(inputList)
symtab = open("SymbolTable.txt", "w")

a = (inputList.pop(0)).split(" ")
symtab.write(a[0] + " " + "0" + "\n")
startaddr = int(a[2])

for item in inputList:
    ins = item.split(" ")
    print ("Ins is: ",ins)

    if ins[1] == 'USING':
        continue
    else:
        if not ins[0] == "**" :
            symtab.write(ins[0] + " " + str(startaddr) + "\n")
            startaddr += 4
        else:
            startaddr += 4
#OUTPUT
# MOT:
# {'A': '5A', 'L': '6A', 'ST': '7A'}
# POT:
# ['DS', 'DC', 'START', 'USING']
# SOT:
# PG1 0
# FIVE 12
# FOUR 16
# TEMP 20

    
