# Input must be in 3 address code form
import re   # Regex for splitting

registers = {}  # Dictionary to keep track of register assignment
output_code = []  # Output lines


def allocateRegister(operand):
    if operand in registers.values():  # Operand already present in one of the registers, use it
        for key, value in registers.items():
            if operand == value:
                return key
    else:
        register_name = "R" + str(len(registers))  # Allocate a new register for the operand
        registers[register_name] = operand  # Assign operand to register
        output_code.append("MOV "+operand+","+register_name)  # Add MOV statement to output
        return register_name

def renameReg(location,operand):
    if operand in registers.values():
        for key, value in registers.items():
            if operand==value:
                registers[key]=location
                #print(registers)


input_code = list(line.strip() for line in open("code_gen_input.txt"))
for index,line in enumerate(input_code):
    line = re.split("([\=\+\-\*\/])", line)  # Split the TAG into operands and operator
    LHS, eq, op1, operator, op2 = line
    oper=op1
    if op2 in registers.values():
        op2=allocateRegister(op2)
    op1 = allocateRegister(op1)
    if operator.strip() == "+":
        output_line = "ADD "+str(op2)+","+str(op1)
        #print(oper,LHS)
        renameReg(LHS,oper)   # Register now hold output i.e. LHS
        #print(registers)
    elif operator.strip() == "-":
        output_line = "SUB " + str(op2) + "," + str(op1)
        renameReg(LHS,oper)
        #registers[op2] = LHS
    if(index==len(input_code)-1):
        output_line=output_line+("\nMOV "+op1+","+LHS)
        
    output_code.append(output_line)
for line in output_code:
    print(line)

"""
OUTPUT
MOV a,R0
ADD b,R0
MOV a,R1
SUB c,R1
ADD R1,R0
ADD R1,R0
MOV R0,d
"""
