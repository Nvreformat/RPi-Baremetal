#ifndef LED_H
#define LED_H

void SetLedState(uint32_t State)
{
	asm volatile("ldr r2,=0x20200000");
	asm volatile("mov r1,#1");
	asm volatile("lsl r1,#21");
	asm volatile("str r1,[r2,#16]");
	
	if (State)
	{
		asm volatile("mov r1,#1");
		asm volatile("lsl r1,#15");
		asm volatile("str r1,[r2,#32]");
	}
	else
	{
		asm volatile("mov r1,#1");
		asm volatile("lsl r1,#15");
		asm volatile("str r1,[r2,#44]");
	}
}

#endif
