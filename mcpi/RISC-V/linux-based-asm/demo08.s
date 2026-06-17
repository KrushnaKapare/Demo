
# Function calling convention

.text

.global main
main:

    # You may store caller saved registers here (t0-t6)

    # t0 = addition(22, 7)
    li a0, 22
    li a1, 7
    call addition
    mv t0, a0

    # You may restore caller saved registers here, if any

exit:       # _exit(t0);
    mv a0, t0
    addi a7, zero, 93
    ecall


.global addition
addition:
    # Function prologue
    addi sp, sp, -8
    sd ra, 0(sp)
    # You may additionally store callee saved registers here (s0-s11)

    # result (a0) = arg1 (a0) + arg2 (a1)
    add a0, a0, a1
    
    # Function epilogue
    # You may restore callee saved registers here (if any)
    ld ra, 0(sp)
    addi sp, sp, 8

    # return from function
    ret

