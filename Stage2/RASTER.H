#ifndef RASTER_H
#define RASTER_H

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

#include "types.h"

extern void clearScreen(UINT32 *base);
/*void clearScreen(UINT32 *base);*/
void plotPixel(UINT16 *base, int x, int y);
void plotHorizontal(UINT32 *base, int y, int x1, int x2);
void plotVertical(char *base, int x, int y1, int y2);
void plotBitmap32(UINT32 *base, 
				  int x, int y,
				  const UINT32 *bitmap,
				  unsigned int height);
void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height);

#endif
