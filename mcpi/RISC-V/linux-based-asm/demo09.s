
# System calls
#   SysCall number: a7
#   Arguments: a0, a1, a2, a3
#   Return Value: a0
# RISC-V Linux System Call Table: https://jborza.com/post/2021-05-11-riscv-linux-syscalls/

# Library functions

.text
.global main
main:
    # write(1, "Hello, DESD!\n", 13);   // syscall 64
    li a0, 1
    la a1, hello_msg
    li a2, 13
    li a7, 64
    ecall

    # printf("Number = %d\n", 123);
    la a0, num_msg
    li a1, 123
    call printf

    # _exit(0);     // syscall 93
exit:
    addi a0, zero, 0
    addi a7, zero, 93
    ecall


.data
hello_msg:  .asciz "Hello, DESD!\n"
num_msg:    .asciz "Number = %d\n"
