.8086
.model small
.data
arr db 01h, 02h, 03h, 04h, 05h
ec db 00h
oc db 00h
.code
start:
    mov ax, @data
    mov ds, ax
    mov cl, 05h
    lea si, arr
bck:mov al, [si]
    ror al,01h
    jc odd
    inc ec
    jmp dwn
odd:inc oc
dwn:inc si
    dec cl
    jnz bck
    mov ah, 4ch
    int 21h
end start