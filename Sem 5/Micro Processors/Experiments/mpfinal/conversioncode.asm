#Conversions
 
.8086
.model  small
.data
num   db  37h
num1  db 35h
num2  db 22h
num3  db  35h

res  db  ?
res1  db  ?
res2 db  ?
result   db  ?

msg2  db  'option 1: Ascii  to BCD  [ascii  value is  37 ] $'
msg3  db  'option 2: BCD  to Ascii  [ascii  value is  35 ] $'
msg4 db  'option 3: Hex  to BCD  [ascii  value is  22 ] $'
msg5  db  'option 4: BCD  to Hex  [ascii  value is  35 ] $'
msg1 db  'Enter  option  $'

.code
Start:
mov  ax,@data
mov  ds,  ax

lea dx,msg2
mov  ah,09h
int 21h

lea dx,msg3
mov  ah,09h
int 21h

lea dx,msg4
mov  ah,09h
int 21h

lea dx,msg5
mov  ah,09h
int 21h

lea dx,msg1
mov  ah,09h
int 21h

mov  ah,08h
int  21h

cmp   al,31h
jnz   next
;AsciiToBCD
	mov al, num
	sub al, 30h
	mov res ,al
	jmp exit
next :cmp  al,32h
jnz  next1

;BCDtoAscii
	mov al,num1
	and al,0F0h
	ror al, 4
	add al,30h
	mov bl,num1
	and bl,0Fh
	add bl,30h
	mov res1, al
	mov res2, bl
	jmp exit
next1:cmp  al,33h
jnz next2

;HextoBCD
	mov al,num2
	mov ah,00h
	mov bl,0Ah
	div bl
	ror al,04h
	add al,ah
	jmp exit

next2:cmp  al,34h
;BCDtoHEX
	mov al,num3
	mov dl,00h
	mov bl,al
	and bl, 0F0h
	mov cl,04h
	ror bl,cl
	back: add dl, 0Ah
	          dec bl
	          jnz  back
	and al,0Fh
	add dl,  al
	mov result ,dl
	jmp exit

exit:int  3h
end  start

 


OUTPUT:
Option 1: Ascii  to  BCD [ascii  value  is 37] 
Option  2:BCD  to Ascii  [bcd  value is 35]   
Option 3:Hex   to BCD  [hex  value  is 22]
Option  4:BCD to  Hex  [bcd  value  is  35] Enter  option
1=>ax  0707
2=>ax  0733 bx  0035
3=>ax  0434
4=>ax  0023
