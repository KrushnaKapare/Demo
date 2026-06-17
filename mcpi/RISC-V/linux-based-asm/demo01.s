
# arithmetic operations
.text
.global main
main:
    # t1 = 22
    li t1, 22
    # t2 = 7
    li t2, 7
    # t0 = t1 + t2
    add t0, t1, t2

    # t3 = t1 - t2
    sub t3, t1, t2

    # t4 = t1 * t2
    mul t4, t1, t2

    # t5 = t1 / t2
    divu t5, t1, t2

exit:                   # _exit(0);
    addi a0, zero, 0
    addi a7, zero, 93
    ecall
    