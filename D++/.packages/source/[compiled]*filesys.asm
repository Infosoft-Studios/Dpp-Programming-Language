section getdata:
  MOV RDX, 3
  mov eax, 3
  int 0x0000079f
  section .filetrans:
    int 0x0000456f;
    FILE: db 0x000045
    equ $-FILE
    ret 0

section .rndata:
  MOV RDX, 3
  ret 0
