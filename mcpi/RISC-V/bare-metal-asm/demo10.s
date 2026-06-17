.section .text
.global _start

_start:
    # initialize stack
    la sp, _stack_top    # Load stack pointer with the top of the stack

    la t0, trap_handler   # Load address of trap handler
    csrw mtvec, t0        # Write to mtvec
    li t1, 0x8            # Enable global interrupts
    csrs mstatus, t1
    addi zero, zero, 0    # Dummy instruction (nop)

    # Simulate an exception (illegal instruction)
    .word 0xFFFFFFFF       # Illegal instruction to trigger exception

    addi zero, zero, 1    # Dummy instruction (nop)
    addi zero, zero, 2    # Dummy instruction (nop)
exit:
    j exit                 # Halt

trap_handler:
    csrr t0, mcause        # Read cause of the trap
    li t1, 2              # Cause code for illegal instruction
    beq t0, t1, handle_illegal_instruction
    j other_exception

handle_illegal_instruction:
    # Handle illegal instruction e.g. skip the illegal instruction
    csrr t0, mepc
    addi t0, t0, 4
    csrw mepc, t0

    mret

other_exception:
    # Handle other exceptions
    mret
