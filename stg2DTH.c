/* code for stage 2 */

/*
/////////////CLEAR SCREEN////////////////////////////////
*/
#include <osbind.h>
#define screenHeight 400
#define screenWidth 640
#define bitMapsize16 16

typedef unsigned long UINT32;
typedef unsigned int UINT16;

void clearScreen(UINT32 *base);
void plotPixel(UINT16 *base, int x, int y);
void plotHorizontal(UINT32 *base, int row);
void plotVertical(char *base, int col);
void plotBitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap,unsigned int height);

int main()
{
        UINT32 *base32 = Physbase(); 
        UINT16 *base16 = Physbase();  
        char *base8 = Physbase();
        int x = 0;
        int y = 0;
        int row = 200;
        int col = 320;

        UINT16 invaderBitmap[bitMapsize16] =
        {
                0x0000,
                0x0810,
                0x0810,
                0x0420,
                0x0240,
                0x1FF8,
                0x2004,
                0x4662,
                0x4002,
                0x43C2,
                0x2424,
                0x1008,
                0x0FF0,
                0x0240,
                0x0000
        };

        /*plotPixel(base16, x, y);*/
        plotHorizontal(base32, row);
        /*plotVertical(base8, col);*/
        /*plotHorizontal(base32, 383);*/
        plotBitmap16(base16, 0, 0, invaderBitmap, bitMapsize16);
        clearScreen(base32);

        return 0;
}

/*
NAME:    
        clearScreen
PURPOSE:
        Clears the screen
INPUTS:
        UINT32 *base: 
        A pointer to the address in frame buffer in longword
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in longs
               
OUTPUTS: 
        None

ASSUMPTIONS:
        This function assumes the resolution is
        exactly 640 x 400 pixels. This function
        also assumes that the framebuffer base pointer
        base will be passed as a UINT32.
        Also assumes a type def is made for UINT32.
*/

void clearScreen(UINT32 *base)
{
        int i, j = 0;
        
        while (i < 8000){
                *(base + (i *20)) &= 0x00000000;  
        }
        
       /* for(j = 0; j< 400; j++)
        {
                for(i = 0; i < 20; i++)
                {
                *(base + (j * 20) + i) = 0x00000000; instead of setting to zero could perform a clear mask
                }
                
        }*/
}

/*
/////////////PLOT PIXEL////////////////////////////////
*/

/*
Name:    
        plotPixel 
Purpose:
        Plots a pixel
Inputs:
        UINT16 *base:
        The purpose is to pass to the function
        the location of the top left corner of the 
        screen and access the pixels in words
        
        int x:
        The purpose is to pass the x-coordinate of
        the pixel
        
        int y:
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
        if(x >= 0 && x < screenWidth && y >= 0 && y < screenHeight)
        {
                *(base + y * 40 + (x >> 4)) |= 1 << (15 - (x & 15)); /* got this to work but still struggling to visualize sometimes/effort */
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
        
        while(count > 0)
        {
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
        
        while(i < 400)
        {
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

void plotBitmap16(UINT16 *base, int x, int y, const UINT16 *bitmap,unsigned int height)
{
    int i = 0; 
    base += x; 
    base +=(y * 40);
    
    while (i<height)
    {
 
        *(base + i * 40) = bitmap[i];
     
        if(x >= 0 && x< screenWidth && y >= 0 && y < screenHeight)
        {
            *(base + y * 40 + (x >> 4)) |= 1 << 15 - (x & 15);
        };
        i++;
     
    }
}
