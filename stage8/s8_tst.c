#include "raster.h"
#include <osbind.h>
#include <stdio.h>
#include "renderer.h"
#include "splash.h"
#include <unistd.h> /*got from online used for pauses*/

#define delay 3
#define BUFFER_SIZE 32000

UINT8 backBuffer[BUFFER_SIZE + 256];

UINT8* alignAdress(UINT32 address);
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer);


int main()
{
    UINT8* base = Physbase();

    /*Double Buffering var*/
    UINT8 *origBuffer = (UINT8*)getVideoBase();
    UINT8 *mainBuffer = (UINT8*)getVideoBase();
    UINT8 *secondBuffer = backBuffer;

    /*aligning the buffer 256 bytes */
    secondBuffer = alignAdress((UINT32)secondBuffer);

    printf("starting test drive\n");
    printf("testing getVideoBase...\n");
    printf("Physbase pointer: %p\n", base);
    printf("getVideoBase pointer: %p\n", getVideoBase());

    if (base == (UINT8*)getVideoBase())
        printf("They are equal\n");

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();

    printf("Testing setScreen\n");
    sleep(delay);
    flipBuffers(&mainBuffer, &secondBuffer); 
    sleep(delay);
    setScreen(origBuffer);

    printf("showing the splash screen\n");
    sleep(delay);
    clearScreen((UINT32*)origBuffer);
    renderSplashScr(splash, (UINT32*)origBuffer); /*splash screen*/
    sleep(5);
    clearScreen((UINT32*)origBuffer);

    return 0;
}

UINT8* alignAdress(UINT32 address)
{
    while (address % 256 != 0)
        address++;

    return (UINT8*) address;
}

/*
Name:
   flipBuffers   
Purpose:
    change between buffers.
Inputs: 
    (UINT8 **) frontbuffer: a pointer to a pointer to the current buffer to the video base
    (UINT8 **) backbuffer: a pointer to a pointer to the buffer being drawn
Outputs:
    none      
Details:
    this function swap the pointers that the video base is pointing, and then call
    setScreen to set the screen to the video base register.
*/
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer)
{
    UINT8 *swap = *frontBuffer;
    *frontBuffer = *backBuffer;
    *backBuffer = swap;

    setScreen(*frontBuffer);
}