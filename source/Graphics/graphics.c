#include <stddef.h>
#include <stdint.h>
#include <Misc/dma.h>
#include <Misc/mailbox.h>
#include <Misc/time.h>
#include <Graphics/graphics.h>

char* Framebuffer;
char* DisplayBuffer;
char* ClearBuffer;
int BaseAddress;
int Offset = 0;

FrameBuferDescription FramebufferInfo __attribute__ ((__aligned__(64))) = {0};

extern void start_l1cache();
extern void stop_l1cache();

int InitialiseFrameBuffer() 
{
	FramebufferInfo.Width = 1920;
	FramebufferInfo.Height = 1080;
	FramebufferInfo.VirtualWidth = 1920;
	FramebufferInfo.VirtualHeight = 3242;
	FramebufferInfo.Pitch = 0;
	FramebufferInfo.BitDepth = 24;
	FramebufferInfo.X = 0;
	FramebufferInfo.Y = Offset;
	FramebufferInfo.Pointer = 0;
	FramebufferInfo.Size = 0;
	
	MailboxWrite((uint32_t)(&FramebufferInfo) | 0x40000000, 1);
	
	return MailboxRead(1);
}

int FPS = 0;
int CurrentFPS = 0;

void Frame_Start()
{
	static uint64_t LastTime = 0;
	
	if (GetTimestamp() > LastTime)
	{
		LastTime = GetTimestamp() + 1000000;
		FPS = CurrentFPS;
		CurrentFPS = 0;
	}
	
	InitialiseFrameBuffer();
	
	BaseAddress = (int) FramebufferInfo.Pointer;
	
	char* Buffer1 = (char*)(BaseAddress);
	char* Buffer2 = (char*)(BaseAddress + (1920 * 1080 * 3));
	char* Buffer3 = (char*)(BaseAddress + ((1920 * 1080 * 3) * 2));
	
	if (Offset == 0)
	{
		DisplayBuffer = Buffer1;
		Framebuffer = Buffer2;
		ClearBuffer = Buffer3;
		Offset = 1080;
	}
	else if (Offset == 1080)
	{
		DisplayBuffer = Buffer2;
		Framebuffer = Buffer3;
		ClearBuffer = Buffer1;
		Offset = 2160;
	}
	else
	{
		DisplayBuffer = Buffer3;
		Framebuffer = Buffer1;
		ClearBuffer = Buffer2;
		Offset = 0;
	}
	
	DMA_Copy_Async(DMA_CHAN_FRAMEBUFFER, Buffer3 + (1920 * 1080 * 3), ClearBuffer, 1920 * 1080 * 3, DMA_TI_DEST_INC | DMA_TI_DEST_WIDTH | DMA_TI_SRC_WIDTH);
}

void Frame_End()
{
	DMA_Wait(DMA_CHAN_FRAMEBUFFER);
	
	++CurrentFPS;
}

int GetFPS()
{
	return FPS;	
}
