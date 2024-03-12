#include <stdio.h>
#include <osbind.h> 
#include "raster.h"
#include "types.h"
#include "bitmaps.h"

int main() {

    UINT8 *base = Physbase();
        
       /* Variables for user inputs*/
    int x1, y1, x2, y2, length, width;

    clearScreen((UINT32 *)base);
    printf("Starting raster graphics test program with user inputs...\n");

    /*** Test plotPixel ***/
    printf("Testing plotPixel...\n");
    printf("Enter x and y coordinates for the pixel (e.g., 10 10): ");
    scanf("%d %d", &x1, &y1);
    printf("Pixel plotted at (%d, %d). Check the screen.\n", x1, y1);
    plotPixel(base, x1, y1);
    while (getchar() != '\n');/*clear buffer*/
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);
    
    /*** Test algoBresenham ***/
    printf("\nTesting algoBresenham...\n");
    printf("Enter start coordinates x1 and y1 (e.g., 20 20): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter end coordinates x2 and y2 (e.g., 100 100): ");
    scanf("%d %d", &x2, &y2);
    printf("Line drawn. Check the screen.\n");
    algoBresenham(base, x1, y1, x2, y2);
    while (getchar() != '\n');/*clear buffer*/
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/
    clearScreen((UINT32 *)base);
    
    /* Clear the screen before drawing bitmaps to ensure visibility*/
    printf("\nClearing screen for bitmap tests...\n");
    clearScreen((UINT32 *)base);
    
    /*** Test plotBitmap64 ***/
    printf("\nTesting plotBitmap64...\n");
    printf("Enter top-left corner coordinates for the bitmap (e.g., 50 50): ");
    scanf("%d %d", &x1, &y1);
    printf("64x64 bitmap plotted. Check the screen.\n");
    plotBitmap64((UINT32 *)base, x1, y1, treeBM, 128);
    while (getchar() != '\n');/*clear buffer*/
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);
    
   

    /*** Test plotBitmap32 ***/
    printf("\nTesting plotBitmap32...\n");
    printf("Enter top-left corner coordinates for the bitmap (e.g., 150 150): ");
    scanf("%d %d", &x1, &y1);
    printf("32x32 bitmap plotted. Check the screen.\n");
    plotBitmap32((UINT32 *)base, x1, y1, heartLifeBM, 32);
    while (getchar() != '\n');/*clear buffer*/
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);
    
    

    /* Clear the screen before drawing a rectangle*/
    printf("\nClearing screen for rectangle test...\n");
    clearScreen((UINT32 *)base);
    
    /*** Test plotRect ***/
    printf("\nTesting plotRect...\n");
    printf("Enter top-left corner coordinates for the rectangle (e.g., 200 200): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter length and width for the rectangle (e.g., 50 30): ");
    scanf("%d %d", &length, &width);
    printf("Rectangle plotted. Check the screen.\n");
    plotRect(base, x1, y1, length, width);
    while (getchar() != '\n');/*clear buffer*/
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);

    printf("\nRaster graphics test program completed.\n");

    return 0;
}


