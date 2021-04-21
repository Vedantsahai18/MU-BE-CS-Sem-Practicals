.8086
.model small
.data
arr db 09h, 04h, 06h, 03h, 02h
.code
start:
    mov ax, @data
    mov ds, ax
    mov ch, 05h
outl:mov cl, 05h
    lea si, arr
inl:mov al, [si]
    mov ah, [si+1]
    cmp al, ah
    jc nxt
    mov [si], ah
    mov [si+1], al 
nxt:inc si
    dec cl
    jnz inl
    dec ch
    jnz outl    
    mov ah, 4ch
    int 21h
end start