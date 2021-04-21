FIND A CHARACTER
.8086
.model small 

.data
str db 'abcd'
char db 'c'
msg1 db "Founf$"
msg2 db "character not fopund$"


.code
start:
mov ax,@data
mov ds,ax
mov es,ax
mov cl,04h
lea di,str
mov al,char
cld
repne scasb
je found
lea dx,msg2
mov ah,09h
int 21h
jmp last
found:
	lea dx,msg1
	mov ah,09h
	int 21h
last: int 3h
end start

OUTPUT
Case 1 @char='m'
	=> Character not found
Case 2 @char='c'
	=> Found character

