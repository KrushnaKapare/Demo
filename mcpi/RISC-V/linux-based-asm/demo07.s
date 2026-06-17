
# function
.text

.global addition
addition:
    # result (a0) = arg1 (a0) + arg2 (a1)
    add a0, a0, a1

    # return from function
    ret

.global main
main:
    # t0 = addition(22, 7)
    li a0, 22
    li a1, 7
    call addition
    mv t0, a0

exit:                   # _exit(t0);
    mv a0, t0
    addi a7, zero, 93
    ecall
