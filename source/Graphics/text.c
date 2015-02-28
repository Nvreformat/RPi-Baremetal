#include <Graphics/graphics.h>

const int CellSizeX = 1;
const int CellSizeY = 2;

void __attribute__((optimize("O3"))) DrawChar(char Character, int X, int Y, int Size, int Stroke)
{
	int SizeX = Size * CellSizeX;
	int SizeY = (Size - (Size / 4)) * CellSizeY;
	
	int MiddleX = SizeX / 2;
	int MiddleY = SizeY / 2;

	int Top = Y;
	int Bottom = Y + SizeY;
	int Left = X;
	int Right = X + SizeX;
	
	if (Character == 'A')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
	}
	else if (Character == 'B')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top + (MiddleY / 2), Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + (MiddleY / 2), Stroke);
		DrawLine(Left, Bottom, Right, Bottom - (MiddleY / 2), Stroke);
		DrawLine(Left, Bottom - MiddleY, Right, Bottom - (MiddleY / 2), Stroke);
	}
	else if (Character == 'C')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == 'D')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Bottom, Right - (MiddleX / 2), Bottom, Stroke);
		DrawLine(Left, Top, Right - (MiddleX / 2), Top, Stroke);
		DrawLine(Right, Bottom - (MiddleY / 2), Right, Top + (MiddleY / 2), Stroke);
		DrawLine(Right - (MiddleX / 2), Top, Right, Top + (MiddleY / 2), Stroke);
		DrawLine(Right - (MiddleX / 2), Bottom, Right, Bottom - (MiddleY / 2), Stroke);
	}
	else if (Character == 'E')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == 'F')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
	}
	else if (Character == 'G')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Right, Bottom, Right, Top + MiddleY, Stroke);
		DrawLine(Right, Top + MiddleY, Right - MiddleX, Top + MiddleY, Stroke);
	}
	else if (Character == 'H')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
	}
	else if (Character == 'I')
	{
		DrawLine(Left + MiddleX, Top, Left + MiddleX, Bottom, Stroke);
	}
	else if (Character == 'J')
	{
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Left, Bottom, Left, Bottom - (MiddleY / 2), Stroke);
	}
	else if (Character == 'K')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Left, Top + MiddleY, Stroke);
		DrawLine(Right, Bottom, Left, Top + MiddleY, Stroke);
	}
	else if (Character == 'L')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == 'M')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Left + MiddleX, Top + MiddleY, Stroke);
		DrawLine(Right, Top, Left + MiddleX, Top + MiddleY, Stroke);
	}
	else if (Character == 'N')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Bottom, Stroke);
	}
	else if (Character == 'O')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == 'P')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Right, Top, Right, Top + MiddleY, Stroke);
	}
	else if (Character == 'Q')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Left + MiddleX, Bottom, Right, Bottom + (MiddleY / 2), Stroke);
	}
	else if (Character == 'R')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Right, Top, Right, Top + MiddleY, Stroke);
		DrawLine(Right - MiddleX, Top + MiddleY, Right, Bottom, Stroke);
	}
	else if (Character == 'S')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Left, Top, Left, Top + MiddleY, Stroke);
		DrawLine(Right, Top + MiddleY, Right, Bottom, Stroke);
	}
	else if (Character == 'T')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left + MiddleX, Top, Left + MiddleX, Bottom, Stroke);
	}
	else if (Character == 'U')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == 'V')
	{
		DrawLine(Left, Top, Left + MiddleX, Bottom, Stroke);
		DrawLine(Right, Top, Left + MiddleX, Bottom, Stroke);
	}
	else if (Character == 'W')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Bottom, Left + MiddleX, Top + MiddleY, Stroke);
		DrawLine(Right, Bottom, Left + MiddleX, Top + MiddleY, Stroke);
	}
	else if (Character == 'X')
	{
		DrawLine(Left, Top, Right, Bottom, Stroke);
		DrawLine(Right, Top, Left, Bottom, Stroke);
	}
	else if (Character == 'Y')
	{
		DrawLine(Left + MiddleX, Top + MiddleY, Left + MiddleX, Bottom, Stroke);
		DrawLine(Left, Top, Left + MiddleX, Top + MiddleY, Stroke);
		DrawLine(Right, Top, Left + MiddleX, Top + MiddleY, Stroke);
	}
	else if (Character == 'Z')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Right, Top, Left, Bottom, Stroke);
	}
	else if (Character == '0')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == '1')
	{
		DrawLine(Left + MiddleX, Top, Left + MiddleX, Bottom, Stroke);
	}
	else if (Character == '2')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Right, Top, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Top + MiddleY, Left, Bottom, Stroke);
	}
	else if (Character == '3')
	{
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == '4')
	{
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Top, Left, Top + MiddleY, Stroke);
	}
	else if (Character == '5')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Left, Top, Left, Top + MiddleY, Stroke);
		DrawLine(Right, Top + MiddleY, Right, Bottom, Stroke);
	}
	else if (Character == '6')
	{
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
		DrawLine(Right, Bottom, Right, Top + MiddleY, Stroke);
	}
	else if (Character == '7')
	{
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Right, Top, Left, Bottom, Stroke);
	}
	else if (Character == '8')
	{
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Top, Left, Bottom, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == '9')
	{
		DrawLine(Right, Top, Right, Bottom, Stroke);
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
		DrawLine(Left, Top, Left, Top + MiddleY, Stroke);
		DrawLine(Left, Top, Right, Top, Stroke);
		DrawLine(Left, Bottom, Right, Bottom, Stroke);
	}
	else if (Character == ',')
	{
		DrawLine(Left + MiddleX, Bottom - (MiddleY / 2), Left, Bottom + (MiddleY / 2), Stroke);
	}
	else if (Character == '-')
	{
		DrawLine(Left, Top + MiddleY, Right, Top + MiddleY, Stroke);
	}
}

void DrawText(const char* Text, int X, int Y, int Size)
{
	int i = 0;
	int Spacing = (Size / 4) + 1;
	int Stroke = (Size / 10) + 1;
	
	while(1)
	{
		char Character = Text[i];
		
		if (Character == '\0')
		{
			break;
		}
		
		DrawChar(Character, X + (((CellSizeX * Size) + Spacing) * i), Y, Size, Stroke);
		
		i++;
	}
	
}
