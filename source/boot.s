.section .init

ldr pc, ResetAddr
ldr pc, UndefAddr
ldr pc, SWIAddr
ldr pc, PAbortAddr
ldr pc, DAbortAddr
ldr pc, UnusedAddr
ldr pc, IRQAddr
ldr pc, FIQAddr

ResetAddr:  .word ResetHandler
UndefAddr:  .word UndefHandler
SWIAddr:    .word SWIHandler
PAbortAddr: .word PAbortHandler
DAbortAddr: .word DAbortHandler
UnusedAddr: .word UnusedHandler
IRQAddr:    .word IRQHandler
FIQAddr:    .word FIQHandler
vectors_end:

ResetHandler:
	bl SetupIVT
	bl SetupModes
	
	/* Set up VSync interrupt */
	
	ldr r0, =0x2000B214
	ldr r1, =0x00010000
	str r1, [r0]
	
	bl EnableInterrupts	
	bl KernelMain
	b .

UndefHandler:
	b .
	
SWIHandler:
	push {lr}
	ldr r0,[lr,#-4]
	bl C_SWI_Handler
	pop {lr}
	movs pc, lr

PAbortHandler:
	b .

DAbortHandler:
	b .

UnusedHandler:
	b .

IRQHandler:
	push {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
	bl C_IRQ_Handler
	pop  {r0,r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,lr}
	subs pc,lr,#4

FIQHandler:
	b .

SetupIVT:
	mov r0,#0x8000
	mov r1,#0x0000
	ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
	stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
	ldmia r0!,{r2,r3,r4,r5,r6,r7,r8,r9}
	stmia r1!,{r2,r3,r4,r5,r6,r7,r8,r9}
	
	mov pc, lr
	
SetupModes:
	;@ (PSR_IRQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
	mov r0,#0xD2
	msr cpsr_c,r0
	mov sp,#0x8000

	;@ (PSR_FIQ_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
	mov r0,#0xD1
	msr cpsr_c,r0
	mov sp,#0x4000

	;@ (PSR_SVC_MODE|PSR_FIQ_DIS|PSR_IRQ_DIS)
	mov r0,#0xD3
	msr cpsr_c,r0
	mov sp,#0x8000000

	mov pc, lr
	
.globl PUT32
PUT32:
	str r1,[r0]
	bx lr

.globl GET32
GET32:
	ldr r0,[r0]
	bx lr

.globl EnableInterrupts
EnableInterrupts:
	mrs     r0, cpsr
	bic     r0, r0, #0x80
	msr     cpsr_c, r0

	mov     pc, lr

.globl DisableInterrupts
DisableInterrupts:
	mrs     r0, cpsr
	orr     r0, r0, #0x80
	msr     cpsr_c, r0

	mov     pc, lr
