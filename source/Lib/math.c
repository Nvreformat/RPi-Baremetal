#include <Lib/math.h>

uint32_t Random()
{
	static uint32_t NextSeed;
	
	NextSeed = NextSeed * 1103515245 + 12345;
    return (uint32_t)(NextSeed / 65536) % 32768;
}

int64_t ABS(int64_t Number)
{
	if (Number < 0)
	{
		return Number - Number - Number;
	}
	else
	{
		return Number;
	}
}

int SGN(int x)
{
    return ((unsigned)-x >> 31) - ((unsigned)x >> 31);
}