mot = {
    'A': '5A',
    'L': '6A',
    'ST': '7A'
}

pot = ['DS', 'DC', 'START', 'USING']

insList = []
with open("ainput.txt", "r") as f:
    for ins in f:
        insList.append(ins.strip("\n").strip("\r"))

symtab = {}
with open("SymbolTable.txt", "r") as f:
    for symbol in f:
        sym = symbol.strip("\n").split(" ")
        symtab[sym[0]] = sym[1]

LC = 0
with open("MachineCode.txt", "w") as f:
    for ins in insList:
        data = ins.split(" ")
        if data[1] in pot:
            if data[1] == 'DC':
                num = data[2].split("'")
                print(str(LC) + " " + str(num[1]))
                f.write(str(LC) + " " + str(num[1]) + "\n")
                LC += 4
            elif data[1] == 'DS':
                print(str(LC) + " " + "--")
                f.write(str(LC) + " " + "--" + "\n")
                LC += 4
            else:
                print("--")
                f.write("--" + "\n")

        else:
            sym = data[2].split(",")
            try:
                print(str(LC) + " " + mot[data[1]] + " " + sym[0] + "," +symtab[sym[1]])
                f.write(str(LC) + " " + mot[data[1]] + " " + sym[0] + "," +symtab[sym[1]]+ "\n")
                LC += 4
            except KeyError as e:
                print ("--")
                f.write("--"+"\n")

        