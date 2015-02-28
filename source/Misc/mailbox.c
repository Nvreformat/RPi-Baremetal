#include <stddef.h>
#include <stdint.h>
#include <Lib/rpi.h>
#include <Misc/mailbox.h>

void MailboxWrite(uint32_t Data, uint8_t Channel)
{
	uint32_t* MailboxAddr = (uint32_t*)MAIL_BASE;
	
	Data &= 0xfffffff0;
	Channel &= 0xf;
	uint32_t Value = Data | Channel;	
	
	while (*(MailboxAddr + 6) & MAIL_FULL);
	
	*(MailboxAddr + 8) = Value;
}

uint32_t MailboxRead(uint8_t Channel)
{
	uint32_t* MailboxAddr = (uint32_t*)0x2000B880;
		
	Channel &= 0xf;
	
	while(1)
	{
		while (*(MailboxAddr + 6) & MAIL_EMPTY);
		
		if (Channel == (*MailboxAddr & 0x0000000f))
		{
			return *MailboxAddr & 0x0000000f;
		}
	}
	
	return 0;
}