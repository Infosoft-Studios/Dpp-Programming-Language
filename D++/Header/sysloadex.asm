section .maindata:
  mov rdx, 3
  mov cl0, 2
  mov eac, 2
  section .retdat:
    mov eax, 32
    mov rdx, 3
    int 0x000032f
  mov edx, 3
  mov rdx, 2

section .retdata:
  D01: db 0x0000045fd
  equ $- D01
  ret 0;
