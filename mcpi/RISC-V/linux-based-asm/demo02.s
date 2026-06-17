
# logical operations
.text
.global main
main:
    # t1 = 5
    li t1, 5
    # t2 = 9
    li t2, 9
    # t0 = t1 & t2 = 0101 & 1001 = 0001 (1)
    and t0, t1, t2

    # t3 = t1 | t2 = 0101 | 1001 = 1101 (13)
    or t3, t1, t2

    # t4 = t1 ^ t2 = 0101 ^ 1001 = 1100 (12)
    xor t4, t1, t2

    # t5 = 22
    li t5, 22   
    # t6 = ~t5          (-23)
    not t6, t5
    # t6 = t6 + 1       (-22)
    addi t6, t6, 1
    # a6 = -t5          (-22)
    neg a6, t5

    # for testing a bit use and operation
    
exit:                   # _exit(0);
    addi a0, zero, 0
    addi a7, zero, 93
    ecall
    