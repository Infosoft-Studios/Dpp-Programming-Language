section .Load:
  MOV EAX, 3
  MOV RDX, 3
  section .Load:
    MOV EAX, 3
    int 0x00005fd;
    ret 0;
  mov eax, 3;

section .Load:
  ret 0;
