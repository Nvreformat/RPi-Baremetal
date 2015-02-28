#include <Lib/itoa.h>

static char buf[12];

char* ltoa(int64_t val)
{
	char *p;
	int flg = 0;
	
	if( val < 0 ) { flg++; val= -val; }
	
	p = ultoa(val);
	if(flg) *--p = '-';
	return p;
}

char* ultoa(uint64_t val)
{
	char *p;
		 
	p = buf+sizeof(buf);
	*--p = '\0';
		 
	do
	{
		*--p = '0' + val%10;
		val/=10;
	}
	while(val);
	
	return p;
}

char* itoa(int32_t val)
{
	char *p;
	int flg = 0;
	
	if( val < 0 ) { flg++; val= -val; }
	
	p = uitoa(val);
	if(flg) *--p = '-';
	return p;
}

char* uitoa(uint32_t val)
{
	char *p;
		 
	p = buf+sizeof(buf);
	*--p = '\0';
		 
	do
	{
		*--p = '0' + val%10;
		val/=10;
	}
	while(val);
	
	return p;
}