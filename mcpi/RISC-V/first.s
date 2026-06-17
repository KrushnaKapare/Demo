.text
.global _start

_start:
	# _exit(7);
	addi a0, zero, 7	# _exit() syscall arg = 7
	addi a7, zero, 93	# _exit() syscall number = 93
	ecall				# software interrupt
