section .Token:
  mov rax, 2
  mov edx, 3
  int 0x0000045f

section .spaces:
  D03:  db "$/#"
  equ $- D03
  
