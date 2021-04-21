input_program = [line.strip() for line in open("input.txt")]
#Pass 1
code=[]
macro_name_table,mdtable = [],[]
macro = 0
for linenumber,line in enumerate(input_program):
    if line == "MACRO":
        continue
    elif input_program[linenumber-1] == "MACRO":
        macro_name_table.append(line)
        mdtable.append(line)
        macro = 1
    elif line == "MEND":
        macro = 0
        mdtable.append(line)
    elif macro == 1:
        mdtable.append(line)
    else:
        code.append(line)
        continue

with open('mnt.txt','a') as mnt:
    for i in macro_name_table:
        mnt.write(i)
with open('mdt.txt','a') as mdt:
    for i in mdtable:
        i = i + '\n'
        mdt.write(i)

#Pass 2
macro_name_table = [line.strip() for line in open('mnt.txt')]
macro_definition_table = [line.strip() for line in open('mdt.txt')]
x=len(macro_definition_table)
print(x)
with open('expanded.txt','a+') as expanded_source_code:
    for line in code:
        if line in macro_name_table:
            for macro_lines in range(1,x-1):
                print(macro_definition_table[macro_lines])
                expanded_source_code.write(macro_definition_table[macro_lines] + '\n')
        else:
            expanded_source_code.write(line + '\n')
'''
##OUTPUT
Source Code:
MACRO
INCR
AR 1,2
SR 1,2
MEND
PG1 Start
using *15
AR 1,2
INCR
SR 1,2
INCR
L1,five
End
MNT:
INCR
MDT:
INCR
AR 1,2
SR 1,2
MEND
Expanded Source Code:
PG1 Start
using *15
AR 1,2
AR 1,2
SR 1,2
SR 1,2
AR 1,2
SR 1,2
L1,five
End
'''
