#include <Misc/time.h>
#include <stddef.h>
#include <stdint.h>

uint64_t GetTimestamp()
{
	volatile uint64_t* TimestampAddr = (uint64_t*)0x20003004;
	
	return *(TimestampAddr);
}

void Sleep(uint32_t MS)
{
	Sleepu(MS * 1000);
}

void Sleepu(uint32_t US)
{
	uint64_t Wait = GetTimestamp() + US;
	
	while (GetTimestamp() < Wait);
}