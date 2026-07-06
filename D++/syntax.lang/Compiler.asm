section .Data:
    mov rax, 2
    mov cl0, 2
    int 0x00045f

    mov eax, 2
    mov rdx, 2

section .LoadComp:
    mov rdx, 32
    D001: db 0x00032
    D012: equ$- D001

ret 0

