#include <osbind.h>
#include <stdio.h> 
#include "model.h"
#include "events.h"
#include "types.h"
#include "input.h"
#include "RASTER.h"
#include "renderer.h"
#include "sync.h"
#include <unistd.h> /*got from online used for pauses*/


#define BUFFER_SIZE 32000
#define delay 3

UINT8 backBuffer[BUFFER_SIZE + 256];

void flipBuffers(UINT8 **frontBuffer, UINT8 **secondBuffer);
UINT8* alignAdress(UINT32 address);

int main()
{
    char key = '\n'; /*variable to check input from user*/
    int i, j; /*i and j used in loops*/

    UINT32 timeThen, timeNow, timeElapsed;
    UINT32 *base = Physbase();
    
    /*model object*/
    Model model;
    bool quit = false;/*has the player press ESC?*/
    bool isOver = false;

    /*Double Buffering var*/
    UINT8 *origBuffer = Physbase();
    UINT8 *mainBuffer = Physbase();
    UINT8 *secondBuffer = backBuffer;
    Model model;
    
    
    setModel(&(model));
    
    secondBuffer = alignAdress((UINT32)secondBuffer);
    
    printf("\nmain buffer: %p\n", mainBuffer);
    printf("flipping buffers now\n\n");
    flipBuffers(&mainBuffer, &secondBuffer);

    sleep(delay);
    Setscreen(-1, origBuffer, -1);
    printf("program terminated\n");
    
    return 0;
}


UINT8* alignAdress(UINT32 address)
{
    while (address % 256 != 0)
        address++;
    
    printf("found address %p\n", address);
    sleep(delay);

    return (UINT8*) address;
}

void flipBuffers(UINT8 **frontBuffer, UINT8 **secondBuffer)
{
    UINT8 *swap = *frontBuffer;
    printf("swap address: %p\n", swap);
    *frontBuffer = *secondBuffer;
    printf("front buffer: %p\n", *frontBuffer);
    *secondBuffer = swap;
    printf("back buffer address: %p\n", *secondBuffer);
    sleep(delay);

    Setscreen(-1, *frontBuffer, -1);
}
