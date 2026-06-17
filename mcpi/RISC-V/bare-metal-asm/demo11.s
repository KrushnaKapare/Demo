.section .text
.global _start

_start:
    # Initialize stack
    la sp, _stack_top    # Load stack pointer with the top of the stack

main:
    # Set up the trap handler
    la t0, trap_handler   # Load address of trap handler
    csrw mtvec, t0        # Write trap handler base address to mtvec
    li t1, 0x8            # Enable global interrupts
    csrs mstatus, t1      # Set global interrupts enable in mstatus

    # Simulate a memory access exception while accessing 0xFFFFFFFF
    li t0, -1               # Load an invalid memory address
    lw t1, 0(t0)           # Attempt to read from invalid memory (triggers exception)

exit:
    j exit

trap_handler:
    # Read trap cause from mcause
    csrr t0, mcause
    li t1, 5               # Cause code for load access fault (5)
    beq t0, t1, handle_load_access_fault

    # Handle other exceptions
    j other_exception

handle_load_access_fault:
    # Handle load access fault (e.g., invalid memory access)
    # You could log or recover here
    j trap_exit

other_exception:
    # Handle any other exception
    j trap_exit

trap_exit:
    # Update mepc to skip the faulting instruction
    csrr t0, mepc         # Read mepc
    addi t0, t0, 4        # Increment to skip the faulting instruction
    csrw mepc, t0         # Update mepc
    mret                  # Return from trap to next instruction

