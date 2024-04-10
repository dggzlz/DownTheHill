#ifndef RASTER_H
#define RASTER_H

#define screenWidth 640
#define screenHeight 400

#include "types.h"

extern void clearScreen(UINT32 *base);
long getTime();
void setScreen(UINT8 *buffer);
UINT16* getVideoBase();
void plotPixel(UINT8 *base, int x, int y);
void algoBresenham(UINT8 *base, int x1, int y1, int x2, int y2);
void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height);
void plotBitmap32(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height);
void plotBitmap16(UINT16 *base, 
                  int x, int y,
                  const UINT16 *bitmap,
                  unsigned int height);
void plotRect(UINT8 *base, int x, int y, int length, int width);

#endif