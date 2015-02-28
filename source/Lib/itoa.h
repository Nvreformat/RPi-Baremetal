#ifndef ITOA_H
#define ITOA_H

#include <stddef.h>
#include <stdint.h>

char* ltoa(int64_t);
char* ultoa(uint64_t);
char* itoa(int32_t);
char* uitoa(uint32_t);

#endif
