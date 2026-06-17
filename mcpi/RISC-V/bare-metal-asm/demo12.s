.section .text
.global _start

_start:
    # Initialize stack
    la sp, _stack_top    # Load stack pointer with the top of the stack

main:
    la t0, trap_handler    # Load trap handler address
    csrw mtvec, t0         # Set trap vector base address
    li t1, 0x80            # Enable timer interrupt
    csrw mie, t1           # Write to mie to enable specific interrupts
    csrsi mstatus, 0x8     # Enable global interrupts (MIE)

    # need to set mtimecmp register. when mtime > mtimecmp, interrupt will raise
    # if mtime is not supported on processor, interrupt will not be generated.
    # Simulated workload
    loop:
        nop                # Do nothing
        j loop             # Infinite loop

trap_handler:
    csrr t0, mcause        # Read mcause to identify the interrupt
    li t1, 7              # Timer interrupt cause
    beq t0, t1, handle_timer_interrupt
    j default_handler

handle_timer_interrupt:
    # Handle timer interrupt
    mret                   # Return from interrupt

default_handler:
    # Handle other interrupts
    mret                   # Return from interrupt

