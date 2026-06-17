
# global variables

.data
# num1 = 11
num1:   .word 11
# num2 = 22
num2:   .word 22

.bss
# num3
num3:   .skip 4

.text
.global main
main:
    # t4 = &num1
    la t4, num1
    # t1 = *t4
    lw t1, 0(t4)
    # t5 = &num2
    la t5, num2
    # t2 = *t5
    lw t2, 0(t5)
    # t0 = t1 + t2
    add t0, t1, t2
    # t6 = &num3
    la t6, num3
    # *t6 = t0
    sw t0, 0(t6)
exit:                   # _exit(t0);
    mv a0, t0
    li a7, 93
    ecall
