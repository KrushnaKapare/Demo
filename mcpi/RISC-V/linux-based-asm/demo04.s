
# factorial

.text
.global main
main:
    # t1 = 5    (num)
    li t1, 5
    # t0 = 1    (result)
    li t0, 1
    # t2 = 1    (loop var)
    li t2, 1

loop:
    # t0 = t0 * t2
    mul t0, t0, t2
    # t2 = t2 + 1
    addi t2, t2, 1
    # if t2 <= 5, repeat loop
    ble t2, t1, loop

exit:                   # _exit(t0);
    mv a0, t0
    addi a7, zero, 93
    ecall
    
