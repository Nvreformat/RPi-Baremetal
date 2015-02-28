#include <stddef.h>
#include <stdint.h>
#include <Lib/itoa.h>
#include <Lib/led.h>
#include <Graphics/graphics.h>
#include <Misc/time.h>
#include <Misc/mmu.h>

unsigned int a = 100;
int LedState = 0;

extern void SetLedState();

void KernelMain()
{
    SetupMemory();
	
	while(1)
	{	
		Frame_Start();
		
		DrawText(uitoa(GetFPS()), 1000, 10, 20);
		DrawText(ultoa(a), 400, 800, 40);
		DrawText("ABCDEFGHIJKLMNOPQRSTUVWXYZ\0", 200, 200, 12);
		DrawText("ABCDEFGHIJKLMNOPQRSTUVWXYZ\0", 200, 250, 15);
		
		Frame_End();
	
		SetLedState(LedState);
		LedState = !LedState;		
	}
}

void C_IRQ_Handler()
{
	// Clear SMI (VSync) interrupt
	
	uint32_t* smi = (uint32_t*)0x20600000;
	*smi = 0;
	a = a + 1;
}

void C_SWI_Handler(uint32_t Code)
{
	
}

