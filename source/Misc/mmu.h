#ifdef MMU_H
#define MMU_H

#include <stddef.h>
#include <stdint.h>

#define MMUTABLEBASE 0x01000000

void StartMMU(unsigned int, unsigned int);
unsigned int MapMemory(unsigned int, unsigned int, unsigned int);
void SetupCache();
void SetupMemory();

#endif