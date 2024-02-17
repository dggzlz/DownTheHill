/* File: raster.c 
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose: This file is part of the raster library (stage 2 of the project), 
 * and it contains the definitions for the functions prototypes defined on the 
 * raster.h module.
 * 
 * The functions of this library are of "low-level". They only plots basic 
 * shapes (lines, shapes, polygons). They are meant to be called by other 
 * libraries to help make more complex shapes.
 * 
 * Assumptions: 
 * - the screen used is a 640 x 400 resolution.    
 * 
 * - the base pointer parameter is of many sizes. It is assumed that the 
 *   base has the Physbase() assigned to its value. Physbase() is used to point 
 *   to the memory that writes to the screen. The sizes denoted are 
 *   the following:
 * 
 *   unsigned byte = char
 *   unsigned word = UINT16
 *   unsigned longword = UINT32
 *   **For 64 bitmap use UINT32**
 */

#include "raster.h"
/***CLEAR SCREEN******/
/*
 PURPOSE: It clears the screen by setting each pixel to 0
 
 INPUTS:
 
base (UINT32 Pointer): A pointer to the address in frame 
 buffer in longword. The purpose is to pass to the function 
 the address of the Physbase function which points to the 
 frame buffer on the screen to get access to set pixels in the screen.

 OUTPUTS: None

 ASSUMPTIONS: 
 This function assumes the resolution is exactly 640 x 400 
 pixels. This function also assumes that the framebuffer 
 base pointer base will be passed as a UINT32.
*/

void clearScreen(UINT32 *base) 
{
    int i, j;

    for(j = 0; j < 400; j++){
        for(i = 0; i < 20; i++){
            *(base + (j * 20) + i) &= 0x00000000;
        }
   }
}

/*******************PLOT PIXEL*******************/
/*
 * PURPOSE: Plots a pixel using Bresenham's Algorithm. The algorithm uses 
 * bitwise, and basic arithmetic operations to accomplish the plotting of a 
 * pixel. It also uses a unsigned word size base pointer to plot the pixel. 
 * Coordinates are also given to the function. the function checks the 
 * coordinates given by making sure it is within the screen boundaries, 
 * i.e. between 0 and 639 for x, and between 0 and 399 for y. 
 *  
 * 
 * INPUTS:
 * - base (UINT16 Pointer): A pointer to the address in frame  buffer in word. 
 *   The purpose is to pass to the function the address of the Physbase 
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 *
 * - x (int): an integer that represent the x-coordinate of the pixel by value
 * 
 * - y (int): an integer that represent the y-coordinate of the pixel by value
 * 
 * OUTPUTS: 
 *  - None
 * 
 * ASSUMPTIONS: 
 * - This function assumes the resolution is exactly 640 x 400 
 *   pixels. 
 * - The frame buffer pointer base must be a unsigned int (UINT16) value.
 * 
 */

void plotPixel(UINT16 *base, int x, int y)
{
    /*SCREEN_WIDTH & SCREEN_HEIGHT both defined inside of raster.h*/    
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT){
            /*Bresenham's Algorithm*/
            *(base + y * 40 + (x >> 4)) |= 1 << (15 - (x & 15)); 
        
    }
}

/********************PLOT HORINZONTAL*******************/
/* 
 * PURPOSE: Plots a horizontal line between x1 and x2. 
 * 
 * INPUTS:
 * - base (UINT32 Pointer):A pointer to the address in frame buffer in longword. 
 *   The purpose is to pass to the function the address of the Physbase()
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 * 
 * - y (int): an integer that represent the y-coordinate by value where the it 
 *  is desired to draw (i.e the row where the line will be drawn). it is 
 *  assumed that y is a value between 0 and 399 
 * 
 * - x1 (int): an integer that represent the x1-coordinate by value where the it 
 *  is desired to draw. x1 is where the function will start drawing the line.
 *  it is assumed that x1 is a value between 0 and x2. 
 * 
 * - x2 (int): an integer that represent the x2-coordinate by value where the it 
 *  is desired to draw. x2 is where the function will finisg drawing the line.
 *  it is assumed that x2 is a value between x1 and 639. 
 * 
 * OUTPUT: None
 * 
 * LIMITATIONS:
 * lowest line it will print is 383
*/

void plotHorizontal(UINT32 *base, int y, int x1, int x2)
{
    int count = x2 - x1;
    
    while(count > 0){
      *(base + y * 20 + (20 - count)) = 0xFFFFFFFFF;
      count--;
   }
}

/********************PLOT VERTICAL********************/
/*
 * PURPOSE: Plots a vertical line between y1 and y2. 
 * 
 * INPUTS:
 * - base (char Pointer):A pointer to the address in frame buffer in longword. 
 *   The purpose is to pass to the function the address of the Physbase()
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 * 
 * - x (int): an integer that represent the x-coordinate by value where the it 
 *  is desired to draw (i.e the column where the line will be drawn). it is 
 *  assumed that x is a value between 0 and 639. 
 * 
 * - y1 (int): an integer that represent the y1-coordinate by value where the it 
 *  is desired to draw. y1 is where the function will start drawing the line.
 *  It is assumed that y1 is a value between 0 and y2.
 * 
 * - y2 (int): an integer that represent the y2-coordinate by value where the it 
 *  is desired to draw. y2 is where the function will finish drawing the line.
 *  It is assumed that y2 is a value between y1 and 399.
 * 
 * OUTPUT: None
 * 
 * LIMITATIONS:
 * - When vertical and horizontal line intersect
 */

void plotVertical(char *base, int x, int y1, int y2)
{
    int line,
        counter = y2-y1, 
        offset = x / 8 + y1,
        pattern = 1 << (7 -(7 & x));

    for (line = 0; line < counter; line ++)
        *(base + offset + 80 * line) = pattern;
}

/*********************PLOT BITMAP 16*********************/
/* 
 * PURPOSE: Plots a given 16x16 bitmap array
 * 
 * INPUTS:
 * - base (char Pointer): A pointer to the address in frame buffer in longword. 
 *   The purpose is to pass to the function the address of the Physbase()
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 * 
 * - x (int): an integer that represent the x-coordinate by value where the it 
 *  is desired to plot the bitmap.  
 * 
 * - y (int): an integer that represent the y1-coordinate by value where the it 
 *  is desired to plot the bitmap.
 * 
 * - bitmap (const pointer UINT16): this is the bitmap to be plotted. it is pass 
 *   as a pointer. Since it is passed as a pointer, it is possible to pass 
 *   arrays. You can only pass bitmaps of 16x16.
 * 
 * - height (unsigned int): the maximum height that the function will plot. this
 *   also represent the size of the array. 
 * 
 * OUPUTS: None
 *
 */
void plotBitmap16(UINT16 *base, 
		          int x, int y, 
                  const UINT16 *bitmap, 
		          unsigned int height)
{
    int i = 0; 
   
    while (i < height){
	*(base + i * 40) = bitmap[i];
        i++;
    }
}

/*********************PLOT BITMAP 32*********************/
/* 
 * PURPOSE: Plots a given 32x32 bitmap array
 * 
 * INPUTS:
 * - base (UINT32 Pointer): A pointer to the address in frame buffer in longword. 
 *   The purpose is to pass to the function the address of the Physbase()
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 * 
 * - x (int): an integer that represent the x-coordinate by value where the it 
 *  is desired to plot the bitmap.  
 * 
 * - y (int): an integer that represent the y-coordinate by value where the it 
 *  is desired to plot the bitmap.
 * 
 * - bitmap (const pointer UINT32): this is the bitmap to be plotted. it is pass 
 *   as a pointer. Since it is passed as a pointer, it is possible to pass 
 *   arrays. You can only pass bitmaps of 32x32.
 * 
 * - height (unsigned int): the maximum height that the function will plot. this
 *   also represent the size of the array. 
 * 
 * OUPUTS: None
 *
 */
void plotBitmap32(UINT32 *base, 
                    int x, int y,
                    const UINT32 *bitmap,
                    unsigned int height)
{	
	int i = 0;
	while (i < height){
		*(base + i * 20) = bitmap[i];
		i++;
	}
}

/*********************PLOT BITMAP 64*********************/
/* 
 * PURPOSE: Plots a given 64x64 bitmap array
 * 
 * INPUTS:
 * - base (UINT32 Pointer): A pointer to the address in frame buffer in longword. 
 *   The purpose is to pass to the function the address of the Physbase()
 *   function which points to the frame buffer on the screen to get access 
 *   to set pixels in the screen. 
 * 
 * - x (int): an integer that represent the x-coordinate by value where the it 
 *  is desired to plot the bitmap.  
 * 
 * - y (int): an integer that represent the y-coordinate by value where the it 
 *  is desired to plot the bitmap.
 * 
 * - bitmap (const pointer UINT32): this is the bitmap to be plotted. it is pass 
 *   as a pointer. Since it is passed as a pointer, it is possible to pass 
 *   arrays. You can only pass bitmaps of 64x64.
 * 
 * - height (unsigned int): the maximum height that the function will plot. this
 *   also represent the size of the array. 
 * 
 * OUPUTS: None
 */
void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height)
{
    int i = 0;
    int offset = 0;

    while (i < height){
        *(base + offset) = bitmap[i];
        *(base + (offset + 1)) = bitmap[i + 1];
        offset += 20;
        i+=2;
    }
}

