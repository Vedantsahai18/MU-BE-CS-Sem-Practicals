.8086
.model small
.data
arr db 01h, 02h, 03h, 04h, 05h
avg db ?
.code
start:
    mov ax, @data
    mov ds, ax
    lea si, arr
    mov cl, 05h
    mov ax, 0000h
bck:add al, [si]
    inc si
    dec cl
    jnz bck
    mov bl, 05h
    div bl
    mov avg, al
    mov ah, 4ch
    int 21h
end start
