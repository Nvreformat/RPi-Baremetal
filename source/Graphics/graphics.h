#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stddef.h>
#include <stdint.h>

typedef struct
{
	uint32_t Width;
	uint32_t Height;
	uint32_t VirtualWidth;
	uint32_t VirtualHeight;
	uint32_t Pitch;
	uint32_t BitDepth;
	uint32_t X;
	uint32_t Y;
	uint32_t* Pointer;
	uint32_t Size;
} FrameBuferDescription;

void Frame_Start();
void Frame_End();
void DrawPixel(int, int);
void SetColor(int);
void DrawChar(char, int, int, int, int);
void DrawText(const char*, int, int, int);
void DrawLine(int, int, int, int, int);
int InitialiseFrameBuffer();
int GetFPS();

#endif
