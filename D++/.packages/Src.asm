section .MainData:
  mov rdx, 2
  mov eax, 2
  int 0x0000000043f

section .retdt:
  ret 0
