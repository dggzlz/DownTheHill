#include "music.h"
#include "effects.h"
#include "psg.h"
#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include "RASTER.H"
#include <osbind.h>
#include <stdio.h>
 
#define BUFFER_SIZE 32000

UINT8 backBuffer[BUFFER_SIZE + 256];

long getTime();
UINT8* alignAdress(UINT32 address);
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer);

int main(){

    char key; 
    int i;

    UINT32 timeThen, timeNow, timeElapsed, lastUpdateTime;
    UINT32 *base = Physbase();

    Model model;
    bool treeCol = false, skierCol = false, quit = false;

    /*Double Buffering var*/
    UINT8 *origBuffer = Physbase();
    UINT8 *mainBuffer = Physbase();
    UINT8 *secondBuffer = backBuffer;
    Model snapshot;
    
    timeNow = getTime();
    timeThen = timeNow;
    lastUpdateTime = timeNow;

    secondBuffer = alignAdress((UINT32)secondBuffer);
    setModel(&(model));
    startMusic('r');
    renderModel(&model, (UINT32 *)mainBuffer);
    renderModel(&model, (UINT32 *)secondBuffer);
    /*
    printf("newscreen is at %p \n", base2);
    printf("FB is at %p \n", frameBuff2);
    */
    timeElapsed = timeNow - timeThen;
    
    while (!quit)
    {  
        if (hasInput())
        {
            key = input();
            if (key == ESC)
            {
                quit = true;
            } 
            else if (key == LEFT_ARROW)
            {
                moveRequest(&(model.snowboarder), 'l');
            }
            else if (key == RIGHT_ARROW)
            {
                moveRequest(&(model.snowboarder), 'r');
            }
        }

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0)
        {
            timeNow = getTime();
            timeThen = timeNow;
            for(i = 0; i < numOfTrees; i++)
            {
                moveTree(&(model.trees[i]));

                if(checkCollisionObs(&(model.snowboarder), &(model.trees[i])))
                    collisionObs(&(model.hearts), &(model.snowboarder));
            }

            for(i = 0; i < numOfSkiers; i++)
            {
                moveSkier(&(model.skiers[i]));

                if (checkCollisionSkier(&(model.snowboarder), &(model.skiers[i])))
                {
                    collisionSkier(&(model.score), &(model.skierCounter), &lastUpdateTime,
                                    timeNow);
                }
                    
            }

            if (checkColEdge(&(model.snowboarder)) || treeCol)
                collisionObs(&(model.hearts), &(model.snowboarder));

            scoreUpdates(&(model.score), &lastUpdateTime, timeNow, false);
            updateMusic(timeElapsed, 'r');
            
            Vsync();
            clearScreen((UINT32 *)secondBuffer);
            renderModel(&model, (UINT32 *)secondBuffer);
            flipBuffers(&mainBuffer, &secondBuffer); 
        }  
    }
    Setscreen(-1, origBuffer, -1);
    stopSound();
    return 0;
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

UINT8* alignAdress(UINT32 address)
{
    while (address % 256 != 0)
        address++;

    return (UINT8*) address;
}

void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer)
{
    UINT8 *swap = *frontBuffer;
    *frontBuffer = *backBuffer;
    *backBuffer = swap;

    Setscreen(-1, *frontBuffer, -1);
}

/*UINT8* findEvenAddress(UINT8 array[])
{
    int i;
    UINT8* base2;
    for(i = 0; i < 32256; i++)
    {
        printf("array is %p\n", &array[i]);
        if( ( (UINT32) &array[i] ) % 256 == 0)
        {
        base2 = &array[i];
        return base2;
        }
    }
    return 0;
}*/