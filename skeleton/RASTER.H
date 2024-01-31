#ifndef RASTER_H
#define RASTER_H


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

#include "types.h"

typedef unsigned long long UINT64;

void clear_screen();
void plot_pixel(char *base, int x, int y);
void plot_vline();
void plot_hline();
void plot_line();
void plot_sq();
void plot_tr();
void plot_cr();
void plot_pl();
void plot_bitmap_64(UINT64 *base, 
					int x, int y,
					const UINT64 *bitmap,
					unsigned int height);

#endif
