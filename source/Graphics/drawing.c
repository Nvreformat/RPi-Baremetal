#include <Graphics/graphics.h>
#include <Lib/math.h>

extern char* Framebuffer;
extern FrameBuferDescription FramebufferInfo;

int Color = 0xFFFFFF;
char R = 255;
char G = 255;
char B = 255;

void SetColor(int C)
{
	Color = C;
	
	R = ((Color) & 0xFF);
	G = ((Color >> 8) & 0xFF);
	B = ((Color >> 16) & 0xFF);
}

inline void __attribute__((optimize("O3"))) DrawPixel(int X, int Y)  
{
	int ArrayLocation = (FramebufferInfo.Pitch * Y) + (X * 3);
	
	Framebuffer[ArrayLocation] = R;
	Framebuffer[ArrayLocation + 1] = G;
	Framebuffer[ArrayLocation + 2] = B;
}

void __attribute__((optimize("O3"))) DrawLine(int x1, int y1, int x2, int y2, int Stroke)
{
	int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
		
	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	dxabs=ABS(dx);
	dyabs=ABS(dy);
	sdx=SGN(dx);
	sdy=SGN(dy);
	x=dyabs>>1;
	y=dxabs>>1;
	px=x1;
	py=y1;

	if (dxabs>=dyabs) /* the line is more horizontal than vertical */
	{
		for(i=0;i<dxabs;i++)
		{
			y+=dyabs;
			if (y>=dxabs)
			{
				y-=dxabs;
				py+=sdy;
			}
			px+=sdx;
			
			int str = Stroke;
			while (str)
			{
				int val = str / 2;
				if (str % 2 == 1)
					val *= -1;
				
				DrawPixel(px, py + val);
				
				--str;
			}
		}
	}
	else /* the line is more vertical than horizontal */
	{
		for(i=0;i<dyabs;i++)
		{
			x+=dxabs;
			if (x>=dyabs)
			{
				x-=dyabs;
				px+=sdx;
			}
			py+=sdy;
			
			int str = Stroke;
			while (str)
			{
				int val = str / 2;
				if (str % 2 == 1)
					val *= -1;
				
				DrawPixel(px + val, py);
				
				--str;
			}
		}
	}
}