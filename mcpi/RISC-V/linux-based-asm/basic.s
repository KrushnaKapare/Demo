
.text
.global main
main:

exit:                   # _exit(7);
    addi a0, zero, 7
    addi a7, zero, 93
    ecall
