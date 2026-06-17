# max of two Numbers

.text
.global main
main:
    # t1 = 22
    li t1, 22
    # t2 = 23
    li t2, 23

    # if t1 >= t2, then jump to max_t1
    bge t1, t2, max_t1
max_t2:
    # t3 = t2
    mv t3, t2
    j max_end
max_t1:
    # t3 = t1
    mv t3, t1
max_end:

exit:                   # _exit(t3);
    mv a0, t3
    addi a7, zero, 93
    ecall
    
