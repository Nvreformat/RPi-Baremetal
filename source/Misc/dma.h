#ifndef DMA_H
#define DMA_H

#define DMA_BASE         (volatile void*)(0x20007000)
#define CS(x)            (volatile int*)(DMA_BASE + (x) * 0x100 + 0x00)
#define CONBLK_AD(x)     (volatile void**)(DMA_BASE + (x) * 0x100 + 0x04)
#define TI(x)            (volatile int*)(DMA_BASE + (x) * 0x100 + 0x08)
#define SOURCE_AD(x)     (volatile int*)(DMA_BASE + (x) * 0x100 + 0x0c)
#define DEST_AD(x)       (volatile int*)(DMA_BASE + (x) * 0x100 + 0x10)
#define TXFR_LEN(x)      (volatile int*)(DMA_BASE + (x) * 0x100 + 0x14)
#define STRIDE(x)        (volatile int*)(DMA_BASE + (x) * 0x100 + 0x18)
#define NEXTCONBK(x)     (volatile int*)(DMA_BASE + (x) * 0x100 + 0x1c)
#define DEBUG(x)         (volatile int*)(DMA_BASE + (x) * 0x100 + 0x20)
#define INT_STATUS       (volatile int*)(DMA_BASE + 0xfe0)
#define ENABLE           (volatile int*)(DMA_BASE + 0xff0)

#define dmb() __asm("mcr p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory")
#define dsb() __asm("mcr p15, 0, %0, c7, c10, 4" : : "r" (0) : "memory")

// CS Control and Status
#define ACTIVE  1<<0
#define END     1<<2
#define INT     1<<2
#define ERROR   1<<8
#define RESET   1<<31

#define IO_TO_BUS(x)     (void*)((unsigned int)(x) | 0x7e000000)
#define ARM_TO_BUS(x)    (void*)((unsigned int)(x) | 0xc0000000)

// Assigned channels
#define DMA_CHAN_FRAMEBUFFER  0

// Control block
typedef struct ControlBlock
{
	unsigned int TI;
	void *SourceAddress;
	void *DestAddress;
	unsigned int TXFR_Len;
	unsigned int Stride;
	void *NextBlock;
} ControlBlock;

// Transfer Information
#define DMA_TI_INTEN       1<<0
#define DMA_TI_WAIT_RESP   1<<3
#define DMA_TI_DEST_INC    1<<4
#define DMA_TI_DEST_WIDTH  1<<5
#define DMA_TI_DEST_DREQ   1<<6
#define DMA_TI_SRC_INC     1<<8
#define DMA_TI_SRC_WIDTH   1<<9
#define DMA_TI_SRC_DREQ    1<<10

#define DMA_TI_PERMAP_EMMC DMA_TI_PERMAP(11)
#define DMA_TI_PERMAP(x)   (x)<<16

void DMA_Reset(unsigned int);
void DMA_Copy(int, void*, void*, unsigned int, unsigned int);
void DMA_Copy_Async(int, void*, void*, unsigned int, unsigned int);
int DMA_Wait(unsigned int);
int DMA_Init(unsigned int, ControlBlock*);

#endif
