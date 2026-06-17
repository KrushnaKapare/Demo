
.data
# array declare and initialized
arr:    .word 2
        .word 4
        .word 6
        .word 8
        .word 10

.text
.global main
main:
    # t0 = 0        result(sum)
    mv t0, zero
    # t2 = 1        loop var
    li t2, 1
    # t6 = arr      addr/pointer
    la t6, arr
    # t5 = 5        array size
    li t5, 5
loop:
    # t3 = *t6
    lw t3, 0(t6)
    # t6 = t6 + 4
    addi t6, t6, 4
    # t0 = t0 + t3
    add t0, t0, t3
    # t2 = t2 + 1
    addi t2, t2, 1
    # if t2 <= 5, repeat loop
    ble t2, t5, loop
exit:                   # _exit(t0);
    mv a0, t0
    addi a7, zero, 93
    ecall




