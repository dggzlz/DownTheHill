#include <stdio.h>
#include <osbind.h> 
#include "raster.h"
#include "types.h"
#include "bitmaps.h"

int main() {

    UINT8 *base = Physbase();
        

    clearScreen((UINT32 *)base);
    printf("Starting raster graphics test program with user inputs...\n");


    printf("testing getTime\n");

    printf("time: %ld\n", getTime());
    printf("time: %ld\n", getTime());
    printf("time: %ld\n", getTime());
    printf("time: %ld\n", getTime());
    printf("PRESS ENTER TO CONTINUE\n");
    getchar();


    /******************** Test plotPixel **********************/
    printf("Testing plotPixel...\n");
    printf("x: %d, y: %d\n", 288, 50);
    plotPixel(base, 288, 50);
    printf("PRESS ENTER TO CONTINUE\n");
    getchar(); 

    printf("x: %d, y: %d\n", 50, 60);
    plotPixel(base, 50, 60);
    printf("PRESS ENTER TO CONTINUE\n");
    getchar(); 
    
    printf("x: %d, y: %d\n", 360, 300);
    plotPixel(base, 360, 300);
    printf("PRESS ENTER TO CONTINUE\n");
    getchar(); 
    
    printf("x: %d, y: %d\n", 620, 10);
    plotPixel(base, 620, 10);
    printf("PRESS ENTER TO CONTINUE\n");
    getchar(); 
    
    clearScreen((UINT32 *)base);
    
    /************** Test algoBresenham*******************************/
    printf("\nTesting algoBresenham...\n");
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 20, 20, 100, 100);
    algoBresenham(base, 20, 20, 100, 100);  

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/  
    
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 1, 0, 1, 200);
    algoBresenham(base, 1, 0, 1, 200);  

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/ 
    
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 0, 0, 639, 399);
    algoBresenham(base, 0, 0, 639, 399);  

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/
    
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 388, 50, 399, 300);
    algoBresenham(base, 388, 50, 399, 300); 

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/
    
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 0, 50, 399, 50);
    algoBresenham(base, 0, 50, 399, 50); 

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/
    
    printf("x1: %d, y1: %d, x2: %d, y2: %d\n", 288, 0, 288, 399);
    algoBresenham(base, 288, 0, 288, 399); 

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();/* Wait for user input to continue*/
    
    /* Clear the screen before drawing bitmaps to ensure visibility*/
    printf("\nClearing screen for bitmap tests...\n");
    clearScreen((UINT32 *)base);
    
    /********** Test plotBitmaps *****************/
    printf("\nTesting plotBitmaps...\n");
    
    /*test plotbitmap16*/
    printf("16x16 bitmaps\n");
    plotBitmap16((UINT16 *)base, 0, 64, numZeroBM, 16);
    plotBitmap16((UINT16 *)base, 16, 64, numOneBM, 16);
    plotBitmap16((UINT16 *)base, 32, 64, numTwoBM, 16);
    plotBitmap16((UINT16 *)base, 48, 64, numThreeBM, 16);
    plotBitmap16((UINT16 *)base, 64, 64, numFourBM, 16);
    plotBitmap16((UINT16 *)base, 80, 64, numFiveBM, 16);
    plotBitmap16((UINT16 *)base, 96, 64, numSixBM, 16);
    plotBitmap16((UINT16 *)base, 112, 64, numSevenBM, 16);
    plotBitmap16((UINT16 *)base, 128, 64, numEightBM, 16);
    plotBitmap16((UINT16 *)base, 144, 64, numNineBM, 16);
    printf("\nPRESS ENTER TO CONTINUE\n");
    while (getchar() != '\n');/*clear buffer*/
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);
    
   

    /*** Test plotBitmap32 ***/
    printf("\n32x32 bitmaps...\n");
    plotBitmap32((UINT32 *)base, 0, 128, heartLifeBM, 32);
    plotBitmap32((UINT32 *)base, 40, 128, skierCounterBM, 32);
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    while (getchar() != '\n');/*clear buffer*/
    clearScreen((UINT32 *)base);
    
    /*test plot bitmaps 64*/
    printf("\nTesting plotBitmap64...\n");
    plotBitmap64((UINT32 *)base, 0, 64, treeBM, 128);
    plotBitmap64((UINT32 *)base, 70, 64, rightSnowBoarderBM, 128);
    plotBitmap64((UINT32 *)base, 140, 64, leftSnowBoarderBM, 128);
    plotBitmap64((UINT32 *)base, 300, 64, rightSkierBM, 128);
    plotBitmap64((UINT32 *)base, 370, 64, leftSkierBM, 128);
    plotBitmap64((UINT32 *)base, 440, 64, angelBM, 128);
    plotBitmap64((UINT32 *)base, 510, 64, grimReaperBM, 128);
    

    printf("\nPRESS ENTER TO CONTINUE\n");
    while (getchar() != '\n');/*clear buffer*/
    getchar(); /* Wait for user input to continue*/
    clearScreen((UINT32 *)base);

    /* Clear the screen before drawing a rectangle*/
    printf("\nClearing screen for rectangle test...\n");
    clearScreen((UINT32 *)base);
    
    /*** Test plotRect ***/
    printf("\nTesting plotRect...\n");
    
    printf("x: %d, y: %d, length: %d, width: %d\n", 0, 0, 64, 64);
    plotRect(base, 0, 0, 64, 64);
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    
    printf("x: %d, y: %d, length: %d, width: %d\n", 0, 0, 128, 128);
    plotRect(base, 0, 0, 128, 128);
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    
    printf("x: %d, y: %d, length: %d, width: %d\n", 300, 200, 32, 64);
    plotRect(base, 300, 200, 32, 64);
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    
    printf("x: %d, y: %d, length: %d, width: %d\n", 200, 10, 100, 200);
    plotRect(base, 200, 10, 100, 200);
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue*/
    
    clearScreen((UINT32 *)base);

    printf("\nRaster graphics test program completed.\n");

    return 0;
}


