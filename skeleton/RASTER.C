#include "raster.h"

typedef unsigned long UINT32;

void clear_screen()
{

}

void plot_pixel(char *base, int x, int y)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);
}

void plot_vline()
{

}

void plot_hline()
{

}

void plot_line(unsigned short x1, unsigned short y1,
               unsigned short x2, unsigned short y2,
               short style, short mode)
{

	X1 = x1;
	Y1 = y1;
	X2 = x2;
	Y2 = y2;
	LNMASK = style;
	WMODE = mode;
	LSTLIN = 0;
	linea3();
}



void plot_bitmap_32(UINT32 *base, 
					int x, int y,
					const UINT32 *bitmap,
					unsigned int height)
{
	while (x < height){
		*(base + x * 20) = bitmap[x];
		x++;
	}
}