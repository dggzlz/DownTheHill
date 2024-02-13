/*FILE: RASTER.C*/

#include "raster.h"

/***************CLEAR SCREEN******************

 PURPOSE: It clears the screen by setting each pixel to 0
 
 INPUTS:
 - base (UINT32 Pointer): A pointer to the address in frame 
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
            *(base + (j * 20) + i) &= 0x00000000; /*instead of setting to zero could perform a clear mask*/
        }
   }
}


/************PLOT PIXEL**********************

 PURPOSE: Plots a pixel
 INPUTS:
 - base (UINT16 Pointer):
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in words
        
 - x (int):
        The purpose is to pass the x-coordinate of
        the pixel
        
 - y (int):
        The purpose is to pass the y-coordinate of
        the pixel
               
Outputs: 
        None
Assumptions:
        This function assumes the resolution is
        exactly 640 x 400 pixels. This function
        also assumes that the framebuffer base pointer
        base, will be passed as a UINT16.
        Also assumes a type def is made for UINT16.
*/

void plotPixel(UINT16 *base, int x, int y)
{
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT){
                *(base + y * 40 + (x >> 4)) |= 1 << (15 - (x & 15)); 
                /* got this to work but still struggling to visualize sometimes/effort */
        }
}

/*
/////////////PLOT HORIZONTAL////////////////////////////////
*/

/*************************BUGS
Name:    
        plotHorizontal
Purpose:
        Plots a horizontal line across the screen
Inputs:
        UINT32 *base:
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in longs
        
        int row:
        The purpose is to pass the y-coordinate of
        the line 
Outputs: 
        None
Assumptions:
        This function assumes the resolution is
        exactly 640 x 400 pixels.
        Also assumes a type def is made for UINT32.
        This function assumes you want to draw a line
        across the entire screen.
Known Bugs:
        lowest line it will print is 383
*/

void plotHorizontal(UINT32 *base, int row)
{
    int count = 20;
    
    while(count > 0){
      *(base + row * 20 + (20 - count)) = 0xFFFFFFFFF;
      count--;
   }
}

/*
/////////////PLOT VERTICAL////////////////////////////////
*/

/************************BUGS
Name:    
        plotVertical
Purpose:
        Plots a vertical line down the screen
Inputs:
        char *base:
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in bytes
        
        int col:
        The purpose is to pass the x-coordinate of
        the line 
Outputs: 
        None
Assumptions:
        This function assumes the resolution is
        exactly 640 x 400 pixels.
        Also assumes a type def is made for UINT32.
        This function assumes you want to draw a line
        down the entire screen.
Known Bugs:
        When vertical and horizontal line intersect
        the 
*/

void plotVertical(char *base, int col)
{
    int i = 0;

    while(i < 400){
        *(base + i * 80 + (col >> 3)) = 0x80;
        i++;
    }
}

/*
/////////////PLOT 16x16 bitmap////////////////////////////////
*/

/*
Name:    
        plotBitmap16
Purpose:
        Plots a 16x16 bitmap
Inputs:
        UINT16 *base:
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in words
        
        int x:
        The purpose is to pass the x-coordinate of
        the start
        
        int y:
        The purpose is to pass the y-coordinate of
        the start
        
        const UINT16 *bitmap:
        The purpose is to pass the address of the
        bitmap array with elements that are size word 
        
        unsigned int height:
        The purpose is to pass the height of the bitmap 
Outputs: 
        None
Assumptions:
        This function assumes the resolution is
        exactly 640 x 400 pixels.
        This function only works for a 16x16 bitmap 
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

/*PLOT_BITMAP_32*/
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

/*PLOT BITMAP 64*/
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

