section .Data:
    mov rax, 2
    mov cl0, 3
    int 0x000456fd

section end:
    ret 0
