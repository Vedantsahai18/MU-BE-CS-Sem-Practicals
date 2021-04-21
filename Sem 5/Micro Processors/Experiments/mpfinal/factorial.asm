.8086
.model small
.stack 100

.data
a db 04h
result dw ?

FACTORIAL macro
    mov al,a
    mov ch,00
    mov ah,00
    mov cl,a
    dec cl

back:   mul cx
        dec cl
        jnz back

endm
.code
start:
        mov ax,@data
        mov ds,ax
        FACTORIAL
        mov result,ax
        int 03h
        mov ah,4ch
        int 21h

end start

OUTPUT:
ds:[0000]=04
ds:[0001]=18
