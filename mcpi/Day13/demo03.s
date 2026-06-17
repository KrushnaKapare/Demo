/* *************************************************************************
**  Target      : Cortex-M3
**  Environment : GNU Tools
*************************************************************************
*/
.syntax unified

.global pfnVectors
.global Default_Handler
.global _start
.equ Top_Of_Stack, 0x20002000    /* end of 8K RAM */

.global sdata
.global edata
.global etext
.global sbss
.global ebss

.section .vectors
vectors:
	.word Top_Of_Stack          @ msp = 0x20002000
	.word _start                @ Starting Program address
	.word Default_Handler	    @ NMI_Handler
	.word Default_Handler	    @ HardFault_Handler
	.word Default_Handler	    @ MemManage_Handler
	.word Default_Handler	    @ BusFault_Handler
	.word Default_Handler	    @ UsageFault_Handler
	.word 0                     @ 7
	.word 0                     @ To
	.word 0                     @ 10 
	.word 0                     @ Reserved
	.word Default_Handler	    	@ SVC_Handler
	.word Default_Handler	    @ DebugMon_Handler
	.word 0                     @ Reserved
	.word Default_Handler	    @ PendSV_Handler
	.word Default_Handler	    @ SysTick_Handler
	.word Default_Handler	    @ IRQ_Handler
	.word Default_Handler	    @ IRQ_Handler

.section .rodata


.section .data


.section .bss


.section .text

.thumb
/**
 * This is the code that gets called when the processor first
 * starts execution following a reset. 
*/
.type _start, %function
_start:                              @ _start label is required by the linker

	//init .data section
	ldr r7, =etext
	ldr r6, =sdata
	ldr r5, =edata
	mov r4, #0
data_init:
	cmp r6, r5
	beq data_init_end
	ldrb r4, [r7], #1
	strb r4, [r6], #1
	b data_init
data_init_end:

	//clear .bss section
	ldr r6, =sbss
	ldr r7, =ebss
	mov r4, #0
bss_init:
	cmp r6, r7
	beq bss_init_end
	strb r4, [r6], #1
	b bss_init
bss_init_end:

	bl main
	stop:   b stop

/***************************************************************/
.global main
.type main, %function
main:                              
	// problem: r0 = MAX(r1, r2)

	/*
	// conditional execution of instruction -- movgt, movle, addeq, sublt, ...
	// feature of ARM instruction set -- works in Cortex-A
	mov r1, #23
	mov r2, #25
	cmp r1, r2		//; (r1 - r2) --> NZCV flags
	movgt r0, r1	//; r0 = r1	if r1 > r2
	movle r0, r2	//; r0 = r2	if r1 <= r2
	*/

	/*
	// supported in thumb/thumb-2 instruction set
	mov r1, #23
	mov r2, #21
	cmp r1, r2		//; (r1 - r2) --> NZCV flags
	bgt max_r1		//; conditional branching
//max_r2:
	mov r0, r2
	b max_end
max_r1:
	mov r0, r1
max_end:
	*/

	// if-then instruction
	// supported in thumb-2 instruction set
	mov r1, #23
	mov r2, #25
	cmp r1, r2		//; (r1 - r2) --> NZCV flags
	ite gt			//; if-then-else (ite)
	movgt r0, r1	//; r0 = r1	if r1 > r2
	movle r0, r2	//; r0 = r2	if r1 <= r2

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

