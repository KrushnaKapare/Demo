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
	mov r1, #5	//; r1=5	=	00000000 00000000 00000000 00000101
	mov r2, #9	//; r2=9	=	00000000 00000000 00000000 00001001
	and r0, r1, r2	//;	r0	=	00000000 00000000 00000000 00000001	= 1

	mov r1, #5	//; r1=5	=	00000000 00000000 00000000 00000101
	mov r2, #9	//; r2=9	=	00000000 00000000 00000000 00001001
	orr r0, r1, r2	//;	r0	=	00000000 00000000 00000000 00001101	= 13

	mov r1, #5	//; r1=5	=	00000000 00000000 00000000 00000101
	mov r2, #9	//; r2=9	=	00000000 00000000 00000000 00001001
	eor r0, r1, r2	//;	r0	=	00000000 00000000 00000000 00001100	= 12

	mov r3, #5		//;	00000000 00000000 00000000 00000101		
	mov r4, #(1<<2)	//;	00000000 00000000 00000000 00000100
	tst r3, r4		//;	00000000 00000000 00000000 00000100 --> Z=0
					//; tst discards result but change xpsr flags

	mov r3, #9		//;	00000000 00000000 00000000 00001001		
	mov r4, #(1<<2)	//;	00000000 00000000 00000000 00000100
	tst r3, r4		//;	00000000 00000000 00000000 00000000 --> Z=1
					//; tst discards result but change xpsr flags

	mov r1, #0xffffffff	//;r1=11111111 11111111 11111111 11111111
	mov r2, #(1<<3)		//;r2=00000000 00000000 00000000 00001000
	bic r1, r2	//; r1 &= ~r2	11111111 11111111 11111111 11110111

	mov pc, lr

/***************************************************************/

.type Default_Handler, %function
Default_Handler:
	halt: b halt

.end

