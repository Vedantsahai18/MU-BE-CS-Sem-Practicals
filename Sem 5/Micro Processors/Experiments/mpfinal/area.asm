.8086
.model small

.data
l db 02h
b db 03h
as dw ?
ar dw ?

.code
        arect proc near
                mov al,l
                mov bl,b
                mul bl
                ret
        arect endp 
        asq proc near
                mov al,l
                mov bl,l
                mul bl
                ret
        asq endp        

start:
        mov ax,@data
        mov ds,ax
        mov al,l
        call arect
        mov ar,ax
        mov al,l
        call asq
        mov as,ax
        int 03h
        mov ah,4ch
        int 21h
end start

OUTPUT:
ds:[0002]=04    //Square
ds:[0006]=06    //Rectangle
