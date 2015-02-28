#include <stddef.h>
#include <stdint.h>
#include <Misc/mmu.h>

#define MMUTABLEBASE 0x01000000

unsigned int MapMemory(unsigned int VirtAddress, unsigned int PhyAddress, unsigned int Flags)
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    ra = PhyAddress >> 20;
    rb = MMUTABLEBASE | (ra << 2);
    ra = VirtAddress >> 20;
    rc = (ra << 20) | Flags | 2;
    PUT32(rb, rc);
    return 0;
}

void SetupCache()
{
	uint32_t ControlRegister;
	asm volatile("MRC p15, 0, %0, c1, c0, 0" : "=r" (ControlRegister));
	ControlRegister |= 0x1800; 
	asm volatile("MCR p15, 0, %0, c1, c0, 0" :: "r" (ControlRegister));	
}

void StartMMU(unsigned int Table, unsigned int Flags)
{
	asm volatile("mov r2, #0");
	asm volatile("mcr p15, 0, r2, c7, c7, 0");
	asm volatile("mcr p15, 0, r2, c8, c7, 0");
	asm volatile("mvn r2, #0");
	asm volatile("mcr p15, 0, r2, c3, c0, 0");
	asm volatile("mcr p15, 0, %0, c2, c0, 0" :: "r" (Table));
	asm volatile("mcr p15, 0, %0, c2, c0, 1" :: "r" (Table));
	asm volatile("mrc p15, 0, r2, c1, c0, 0");
	asm volatile("orr r2, r2, %0" :: "r" (Flags));
	asm volatile("mcr p15, 0, r2, c1, c0, 0");
}

void SetupMemory()
{
	unsigned int Address;
    for (Address = 0; Address < 0xEFFFFFFF; Address += 0x100000)
    {
		MapMemory(Address, Address, 0x0000);
    }
	
	MapMemory(0x00000000, 0x00000000, 0x0000|8|4);
	
    StartMMU(MMUTABLEBASE, 0x00800001);
	SetupCache();
}