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
 * The functions of this library are of "low-level" routines. most of them plots basic 
 * shapes (lines, shapes). They are meant to be called by other 
 * libraries to help make more complex shapes.
 * 
 * Assumptions: 
 * - the screen used is a 640 x 400 resolution.    
 * 
 * - the base pointer parameter is of many sizes. It is assumed that the 
 *   base has the pointer to the video base register assigned to its value. getVideoBase is used to point 
 *   to the memory that writes to the screen. 
 * 
 * - The sizes denoted are the following:
 * 
 *   unsigned byte = char
 *   unsigned word = UINT16
 *   unsigned longword = UINT32
 *   **For 64 bitmap use UINT32**
 */

#include "raster.h"
#include <osbind.h>
#include <stdio.h>

/*Addresses that holds the video base address*/
#define BASE_HI 0xFFFF8201 
#define BASE_MI 0xFFFF8203

/*from RAST_ASM*/
/*extern void setVideoBase(UINT8 * buffer);

/*** get the time***/
/*
Name:
      getTime 
Purpose: 
        The function reads periodically the content of the address 0x462.
        the address contains a timer that keeps track of the internal clock 
        by being incremented 70 times per second.
        
Inputs: 
        None
Outputs: 
        A longword that has the value of the current time of the internal clock
            
Assumptions and Limitations:
        The function enter Supervisor mode. if Supervisor mode is not on, the 
        function won't be able to read the timer at the address.
        
*/
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

/***set the screen***/
/*
Name:
        setScreen
Purpose:
        this function is wrapper function that calls the ASL subroutine 
        setVideoBase. This fucntion mainly works just to go into supervisor mode.
Inputs: 
        The buffer desired to set the screen at. This buffer is an unsigned
        byte pointer, which point to the start address of the buffer.
Outputs: 
        none    

Details:
        For more details about how the screen is set, please refer to the file,
        RASTER_ASM.S, which contain the subroutine call setVideoBase.
*/
void setScreen(UINT8 * buffer)
{
    long oldSSP = Super(0);
    /*setVideoBase(buffer);*/
    Super(oldSSP);
}

/***Get Video Base****/
/*
Name:
        getVideoBase
Purpose:
        This function returns a pointer to the address of the video base 
        register as unsigned word. The address of the video base are in the 
        LSByte of the addresses BASE_HI and BASE_MI. These are constants 
        defined at the top of the file. 
Inputs: 
        none
Outputs: 
        An unsigned word pointer with the address of the video base register.

Details and Calculations:
        This function works the same as Physbase() system call. 
        First, it points to the low byte from both BASE_HI and BASE_MI.
        Then, the value that highByte points at is casted as a UINT32 
        into baseAddress. then bitshifted to the left 8 times. the same process
        is done with the midByte. this in turn, gives us the viode base address.
        the function then returns a casted video base address as a UINT16
        pointer.    

        videoBaseAddr + highByte = 0x0000hh
        videoBaseAddr << 8       = 0x00hh00
        videoBaseAddr + midByte  = 0x00hhmm
        videoBaseAddr << 8       = 0xhhmm00

Details:
        The variable highByte refers to the byte in the 24 bit address of the 
        video register, and the midByte refers to the middle one.

        Example:
                0xhhmm00 where hh is highByte and mm is midByte. the rest of the
                address are 0 as those bits are not use.

Assumptions and Limitations: 
        The video base register is protected and therefore when doing the 
        operations, it must be in Supervisor mode. Otherwise the function 
        won't be able to access the values in the given addresses. 
*/
UINT16* getVideoBase()
{
        UINT32 vidBaseAddr; /*video base address*/
        UINT8 *highByte = BASE_HI;
        UINT8 *midByte = BASE_MI;
        long oldSSP = Super(0);

        vidBaseAddr = (UINT32) *highByte; 
        vidBaseAddr = vidBaseAddr << 8;
        vidBaseAddr += (UINT32) *midByte;
        vidBaseAddr = vidBaseAddr << 8; 
        
        Super(oldSSP);
        return (UINT16 *) vidBaseAddr;
}

/***plotting a pixel***/
/*
Name:
        plotPixel
Purpose:
        plots a pixel at a 
        specified x, y coordinate within the 
        frame buffer for the Atari ST.
Inputs: UINT8 *base:
                A unsigned byte pointer to the 
                start of the frame buffer (0,0).
        int x, int y:
                X and Y coordinates of where 
                the pixel is to be plotted.
Outputs: 
        None
Calculations:
        base is equal to the start of the frame buffer. Since it points 
        to a byte at a time, there are 80 bytes in 
        the width of the screen. Y*80 thus gets us 
        to the row specified by Y. Once on the correct
        row we determine the byte location of the x,y
        coordinate by shifting the x coordinate of the
        pixel to the right. A bitwise OR operation is
        then performed with 1 << (7-(x & 7)) to set 
        the pixel. (x & 7) tells us the location of 
        the pixel within the byte so we shift 1 which 
        is 00000001 to the left (7-(x & 7)) times to get 
        the correct position for the bitwise OR operation.
Details:
        Plot pixel operates on the frame buffer of the Atari ST 
        which has 32000 bytes on the screen and takes into account 
        the fact that there are 80 bytes per row. To plot a pixel 
        at the specified (x,y) coordinate, the function calculates the 
        byte index by shifting the x-coordinate by 3 bits which is the same
        as dividing the x coordinate by 8 and then adds it to the offset of
        the y coordinate. Once in the proper byte, the appropriate bit is set
        by using a bitwise or with the calculated correct position of the bit.

Assumptions and Limitations: 
        The X,Y coordinate and base pointer parameters are meant for the 
        Atari ST. The graphics are monochrome.
*/
void plotPixel(UINT8 *base, int x, int y)
{
    if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
        *(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));
    
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
Details and Calculations:
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

NOTE: 
Reference for the algorithms was taken from this youtube video
https://youtu.be/RGB-wlatStc?si=o5XHFcXK1CKShLOs 
*/    
void algoBresenham(UINT8 *base, int x1, int y1, int x2, int y2)
{
    int x = x1;
    int y = y1;
    int dx = x2-x1; /*change in x*/
    int dy = y2-y1; /*change in y*/
    int p; /*decision variable*/

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
Details:
        Unfortunately the Atari ST does not allow for the long long access of memory thus 32bit,
        (a long) is the largest size we can use and so since there are two longs per row for 
        a 64x64 bitmap, each iteration in the while loop accesses two elements of the bitmap array
        before offseting into the next row. There are 20 longs per row and the row is determined by
        multiplying the Y coordinate by 20 and then finding the byte to index by shifting x to the 
        right by 5 which is the same as dividing x by 32. The function checks that the desired (x,y)
        coordinate is on the screen. The long to be written to in the frame buffer is then bitwise 
        OR with the appropriate element in the bitmap.   

Assumptions and Limitations: 
        Assumes the bitmap is exactly 64x64 pixels in size.
        Designed for monochrome graphics on the Atari ST. 
        It also assumes that the coordinates for plotting
        are size aligined.
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
Details:
        There are 20 longs per row and the row is determined by
        multiplying the Y coordinate by 20 and then finding the byte to index by shifting x to the 
        right by 5 which is the same as dividing x by 32. The function checks that the desired (x,y)
        coordinate is on the screen. The long to be written to in the frame buffer is then bitwise 
        OR with the appropriate element in the bitmap. 
Assumptions and Limitations: 
        Assumes the bitmap is exactly 64x64 pixels in size.
        Designed for monochrome graphics on the Atari ST.
        It also assumes that the coordinates for plotting
        are size aligined.
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
            *(base + offset) |= bitmap[i];
            offset += 20;
            i+=1;
	}
    }
}

/***plotting a 16x16 pixel bitmap***/
/*
Name:
        plotBitmap16
Purpose:
        Plots a 16x16 pixel bitmap at a specified x,y coordinate on the screen. 
        This function directly manipulates the frame buffer to draw a bitmap image 
        by copying bitmap data to the screen's memory, starting at the given coordinates. 
Inputs:
        UINT16 *base:
                A pointer to the frame buffer's start address, allowing direct pixel manipulation.
        int x, int y:
                The top-left corner coordinates where the bitmap will begin to be plotted.
        const UINT16 *bitmap:
                A pointer to the 16x16 bitmap array to be drawn on the screen. 
        unsigned int height:
                The height of the bitmap to be plotted, expected to be 16 pixels 
                for this function. This parameter defines how many elements of the bitmap 
                array will be drawn.
Outputs: 
        None
Details:
        There are 40 words per row and the row is determined by
        multiplying the Y coordinate by 40 and then finding the byte to index by shifting x to the 
        right by 4 which is the same as dividing x by 16. The function checks that the desired (x,y)
        coordinate is on the screen. The long to be written to in the frame buffer is then bitwise 
        OR with the appropriate element in the bitmap. 
Assumptions and Limitations: 
        Assumes the bitmap is exactly 16x16 pixels in size.
        Designed for monochrome graphics on the Atari ST.
        It also assumes that the coordinates for plotting
        are size aligined.
*/
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
            *(base + offset) |= bitmap[i];
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
Details and Calculations:
        This function passes all four lines of a rectangle
        to the algoBresenham function to plot each individually.
        It calculates all the (x,y) coordinates to pass by 
        offsetting from the top y coordinate and left x coordinate
        by the width and length of the rectangle respectivly.  
        
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

    if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight 
       && rowBot < screenHeight && colRight < screenWidth)
   {
        algoBresenham(base, colLeft, rowTop, colRight, rowTop);/*top horizontal line*/
        algoBresenham(base, colRight, rowTop, colRight, rowBot);/*right vertical line*/
        algoBresenham(base, colLeft, rowTop, colLeft, rowBot );/*left vertical line*/
        algoBresenham(base, colLeft, rowBot, colRight, rowBot);/*bottom horizontal line*/
   }
}