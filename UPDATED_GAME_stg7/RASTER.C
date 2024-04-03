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
 * shapes (lines, shapes). They are meant to be called by other 
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
#include <osbind.h>
#include <stdio.h>

#define BASE_HI 0xFFFF8201
#define BASE_MI 0xFFFF8203

/*0xFF231200
/***plotting a pixel***/
/*
Name:
        plotPixel
Purpose:
        plots a pixel at a 
        specified x,y coordinate within the 
        frame buffer for the Atari ST.
Inputs: char *base:
                A character pointer to the 
                start of the frame buffer (0,0).
        int x, int y:
                X and Y coordinates of where 
                the pixel is to be plotted.
Outputs: 
        None
Calculations:
        base starts at (0,0) since it points 
        to a byte at a time, there are 80 bytes in 
        the width of the screen. Y*80 thus gets us 
        to the row specified by Y. Once on the correct
        row we determine the byte location of the x,y
        coordinate by shifting the x coordinate of the
        pixel to the right. A bitwise OR operation is
        then performed with 1 << ( (7-(x & 7)) to set 
        the pixel. (x & 7) tells us the location of 
        the pixel within the byte so we shift 1 which 
        is 00000001 to the left (7-(x & 7) times to get 
        the correct position for the bitwise OR operation.
Assumptions and Limitations: 
        The X,Y coordinate and base pointer parameters
        are meant for the Atari ST.
        The graphics are monochrome.
*/
void plotPixel(UINT8 *base, int x, int y)
{
    if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
        *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
    
}

long getTime()
{
    long oldssp; 
    long timeNow;
    long *timer = (long *) 0x462;

    oldssp = Super(0);
    timeNow = *timer;
    Super(oldssp);

   return timeNow;    
}

/****Get Video Base****/
UINT16* getVideoBase()
{
        UINT32 baseAddress;
        UINT8 *highByte = BASE_HI;
        UINT8 *midByte = BASE_MI;
        long oldSSP = Super(0);

        baseAddress = (UINT32) *highByte; 
        baseAddress = baseAddress << 8;
        baseAddress += (UINT32) *midByte;
        baseAddress = baseAddress << 8; 
        
        Super(oldSSP);
        return (UINT16 *) baseAddress;
}

/***plotting an arbitrary line***/
/*
Name:
        algoBresenham
Purpose:
        Plots a straight line between two pints using the 
        Bresenhams line drawing algorithm. It calls plotPixel 
        to plot a pixel at a specified X,Y coordinate 
        then loops plotting a pixel at either every
        X coordinate incremented or Y coordinate incremented based 
        on whether the slope of the line is greater than 1 or equal
        to or less than 1.
        
Inputs: char *base:
                A character pointer to the 
                start of the frame buffer (0,0).
        int x1, x2:
                X coordinates of the starting 
                and ending X coodninates of where 
                the pixel is to be plotted.
        int y1, y2:
                Y coordinates of the starting 
                and ending Y coordninates of where 
                the pixel is to be plotted.
Outputs: 
        None
Calculations:
        dx is the change in the x and dy is the change
        in the y and both are used to calculate the decision 
        variables initial value. 
        Bresenhams algorithm is based on a decision variable 
        "p" which determines the next pixels position to 
        minimize the error between the actual line and the rasterized line.
        p has an initial value 
        and is then adjusted according the decision of 
        previous decisions for pixels.
        The if and else statements are identical except one 
        is in terms of x since we know we will increment
        x everytime and the other in terms of y as y will then be
        incremented everytime for a slope <= 1 and slope > 1 respectively.
        
Assumptions and Limitations: 
        The X and Y coordinates and base pointer parameters
        are meant for the Atari ST.
        The graphics are monochrome.
        The implemented algorithm only plots lines from left to right
        and top to bottom, therefore the parameter passed must meet the 
        following criteria:
        y2 >= y1 && x2 >= x1 
        Cannot plot lines bottom left to top right yet.
*/
void algoBresenham(UINT8 *base, int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = x2-x1;
    int dy = y2-y1;
    int p;

    if(dy <= dx)/*slope is less than or equal to one*/
    {
        p = 2 * dy - dx;/*decision variable*/
        while(x<=x2)
        {
            plotPixel(base, x, y);
            x++;
            if(p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                p += (2 * dy - 2 * dx);
                y++;
            }
        }
    }
    else/*slope greater than 1*/
    {
        p = 2 * dx - dy;/*decision variable*/
        while(y<=y2)
        {
            plotPixel(base, x, y);
            y++;
            if(p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                p += (2 * dx - 2 * dy);
                x++;
            }
        }
    }
}

                        
 
/***plotting a 64x64 pixel bitmap***/
/*
Name:
        plotBitmap64
Purpose:
        Plots a 64x64 pixel bitmap at a specified x,y coordinate on the screen. 
        This function directly manipulates the frame buffer to draw a bitmap image 
        by copying bitmap data to the screen's memory, starting at the given coordinates. 
Inputs:
        UINT32 *base:
                A pointer to the frame buffer's start address, allowing direct pixel manipulation.
        int x, int y:
                The top-left corner coordinates where the bitmap will begin to be plotted.
        const UINT32 *bitmap:
                A pointer to the 64x64 bitmap array to be drawn on the screen. 
        unsigned int height:
                The height of the bitmap to be plotted, expected to be 128 pixels 
                for this function. This parameter defines how many elements of the bitmap 
                array will be drawn.
Outputs: 
        None
Assumptions and Limitations: 
        Assumes the bitmap is exactly 64x64 pixels in size.
        Designed for monochrome graphics on the Atari ST.
*/

void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height)
{
    int i = 0;
    int offset = (y * 20 + (x >> 5));
    
    if(x >= 0 && x <= (screenWidth - 64) && y >= 0 && y < screenHeight && height == 128)
    {
        while (i < height)
        {
            *(base + offset) |= bitmap[i];
            *(base + (offset + 1)) |= bitmap[i + 1];
            offset += 20;
            i+=2;
        }
    }
}

/***plotting a 32x32 pixel bitmap***/
/*
Name:
        plotBitmap32
Purpose:
        Plots a 32x32 pixel bitmap at a specified x,y coordinate on the screen. 
        This function directly manipulates the frame buffer to draw a bitmap image 
        by copying bitmap data to the screen's memory, starting at the given coordinates. 
Inputs:
        UINT32 *base:
                A pointer to the frame buffer's start address, allowing direct pixel manipulation.
        int x, int y:
                The top-left corner coordinates where the bitmap will begin to be plotted.
        const UINT32 *bitmap:
                A pointer to the 32x32 bitmap array to be drawn on the screen. 
        unsigned int height:
                The height of the bitmap to be plotted, expected to be 32 pixels 
                for this function. This parameter defines how many elements of the bitmap 
                array will be drawn.
Outputs: 
        None
Assumptions and Limitations: 
        Assumes the bitmap is exactly 64x64 pixels in size.
        Designed for monochrome graphics on the Atari ST.
*/

void plotBitmap32(UINT32 *base, 
                    int x, int y,
                    const UINT32 *bitmap,
                    unsigned int height)
{	
    int i = 0;
    int offset = (y * 20 + (x >> 5));

    if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight && height == 32)
    {
	while (i < height)
        {
            *(base + offset) = bitmap[i];
            offset += 20;
            i+=1;
	}
    }
}

void plotBitmap16(UINT16 *base, 
                    int x, int y,
                    const UINT16 *bitmap,
                    unsigned int height)
{	
    int i = 0;
    int offset = (y * 40 + (x >> 4));

    if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
    {
        while (i < 16)
        {
            *(base + offset) = bitmap[i];
            offset += 40;
            i+=1;
	}
    }
}


/***plotting a square or rectangle***/
/*
Name:
        plotRect
Purpose:
        Plots a rectangle of given size and 
        starting location to the frame buffer.
Inputs: char *base:
                A character pointer to the 
                start of the frame buffer (0,0).
        int x, int y:
                X and Y coordinates of where 
                the top left corner pixel of the 
                rectangle is.
        int length, int width:
                The length and width of the rectangle
                specified in pixels.
Outputs: 
        None
Calculations:
        
Assumptions and Limitations: 
        The X,Y coordinate and base pointer parameters
        are meant for the Atari ST.
        The graphics are monochrome.
        The line thickness is always the thickness of 
        a pixel.
        All lines are drawn either left to right or 
        top to bottom. 
*/

void plotRect(UINT8 *base, int x, int y, int length, int width)
{
        int rowTop = y; 
        int rowBot = y + width - 1; 
        int colLeft = x;
        int colRight = x + length - 1;
        
       
        if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight && rowBot < screenHeight && colRight < screenWidth)
        {
                algoBresenham(base, colLeft, rowTop, colRight, rowTop);/*top horizontal line*/
                algoBresenham(base, colRight, rowTop, colRight, rowBot);/*right vertical line*/
                algoBresenham(base, colLeft, rowTop, colLeft, rowBot );/*left vertical line*/
                algoBresenham(base, colLeft, rowBot, colRight, rowBot);/*bottom horizontal line*/
        }
}
                
                
                
                
              
                
            


  
        
        
        
        
        
        
        
       