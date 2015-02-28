#include "Misc/dma.h"

void DMA_Reset(unsigned int Channel)
{
	if (Channel > 14)
		return;

	*CS(Channel) = RESET;
	while(*CS(Channel) & RESET);
}

int DMA_Init(unsigned int Channel, ControlBlock* Block)
{
	if(Channel > 14)
		return 1;

	Block->TI |= DMA_TI_INTEN;
	Block->NextBlock = 1;

	dsb();
	*CONBLK_AD(Channel) = Block;
	*CS(Channel) = ACTIVE | END | INT;

	return 0;
}

ControlBlock Block __attribute__ ((__aligned__(32)));
void DMA_Copy_Async(int Channel, void* SourceAddr, void* DestAddr, unsigned int Size, unsigned int TI)
{
	Block.TI = TI;
	Block.SourceAddress = SourceAddr;
	Block.DestAddress = DestAddr;
	Block.TXFR_Len = Size;
	Block.Stride = 0;
	Block.NextBlock = 0;

	DMA_Init(0, &Block);
}

void DMA_Copy(int Channel, void* SourceAddr, void* DestAddr, unsigned int Size, unsigned int TI)
{	
	DMA_Copy_Async(Channel, SourceAddr, DestAddr, Size, TI);
	DMA_Wait(0);
}

int DMA_Wait(unsigned int Channel)
{
	if(Channel > 14)
		return 1;
	
	while((*CS(Channel) & (INT | ERROR)) == 0);
		if (*CS(Channel) & ERROR)
			return 2;
}

void DMA_Reset_All()
{
	int i;
	for(i=0 ; i<=14 ; ++i)
		*CS(i) = RESET;

	int Reset = 0;
	while (Reset != 0x7fff)
	{	
		for(i=0 ; i<= 14 ; ++i)
		{
			if(Reset & (1<<i))
				continue;
			if((*CS(i) & RESET) == 0)
				Reset |= (1<<i);
		}
	}
}
