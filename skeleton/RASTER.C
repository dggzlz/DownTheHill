#include "raster.h"

typedef unsigned long long UINT64;

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

void plot_line()
{

}



void plot_bitmap_64(UINT64 *base, 
					int x, int y,
					const UINT64 *bitmap,
					unsigned int height)
{

}