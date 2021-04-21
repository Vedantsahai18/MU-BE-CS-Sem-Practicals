PALINDROME
.8086
.model small
.data

s db "madam$"
s1 db "Not Palindrome $"
s2 db "Palindrome $"
.code  
start:
mov ax,@data
mov ds,ax
mov es,ax
lea si,s
lea di,s
mov cl,00h
mov ah,'$'
label1 : inc di
inc cl
cmp [di],ah
jnz label1
dec di
dec cl
jz lb3
jmp lb2

lb2: lea dx,s1
mov ah,09h
int 21h
jmp last

lb3: lea dx,s2
mov ah,09h
int 21h

last: int 3h
end start

OUTPUT
case1 :'madam'
	=> Palindrome
case2 :'mada'
	=> Not palindrome