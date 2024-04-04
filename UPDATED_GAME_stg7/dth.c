#include "music.h"
#include "effects.h"
#include "psg.h"
#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include "splash.h"
#include <osbind.h>
#include <stdio.h>
 
#define BUFFER_SIZE 32000
#define splashHeight 8000

UINT8 backBuffer[BUFFER_SIZE + 256];



UINT8* alignAdress(UINT32 address);
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer);


int main()
{
    char key = '\n'; /*variable to check input from user*/
    char endKey = '\n';
    int i, j, counter = 0; /*i used in loops*/
                        /*counter used to keep track of time*/

    /*Clock variables*/
    UINT32 timeThen, timeNow, timeElapsed, lastUpdateTime;
    
    /*model object*/
    Model model;
    bool  quit = false;/*has the player press ESC?*/
    bool GameOver = false;

    /*Double Buffering var*/
    UINT32 *base = (UINT32*)getVideoBase();
    UINT8 *origBuffer = (UINT8*)getVideoBase();
    UINT8 *mainBuffer = (UINT8*)getVideoBase();
    UINT8 *secondBuffer = backBuffer;
    
    timeNow = getTime();
    timeThen = timeNow;
    lastUpdateTime = timeNow;

    /*aligning the buffer 256 bytes */
    secondBuffer = alignAdress((UINT32)secondBuffer);

    clearScreen(base);
    renderSplashScr(splash, base); /*splash screen*/
    startMusic('j'); /*music for the splash screen*/
    
    timeElapsed = timeNow - timeThen;

    /*loop for the splash screen*/
    while (key != ' ' && !quit)
    {
        if (hasInput())
        {   
            key = input();

            if (key == ESC)
                quit = true;
        }

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0)
        {
            timeNow = getTime();
            timeThen = timeNow;
            updateMusic(timeElapsed, 'j');
        }
    }
    
    clearScreen(base);
    stopSound();

    setModel(&(model));
    startMusic('r');
    renderModel(&model, (UINT32 *)mainBuffer);
    renderModel(&model, (UINT32 *)secondBuffer);

    timeElapsed = timeNow - timeThen;
    
    /*main loop*/
    while (!quit && !GameOver)
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

            /*if (checkColEdge(&(model.snowboarder)))
                collisionObs(&(model.hearts), &(model.snowboarder));*/

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
        

        /*JD FUNCTION*/
            for(i = 0; i < numOfTrees; i++)
            { 
                for(j = 0; j < numOfSkiers; j++)
                areSkierTreeSameColumn(&(model.skiers[j]), &(model.trees[i]));
            /*checkSkierCollideWithTree(&(model.skiers[j]), &(model.trees[i]));*/
            }

            if (checkColEdge(&(model.snowboarder)))
                collisionObs(&(model.hearts), &(model.snowboarder));

            scoreUpdates(&(model.score), &lastUpdateTime, timeNow, false);
            /*scoreUpdates(&(model.score), false);*/
            updateMusic(timeElapsed, 'r');

            GameOver = checkGameOver(&(model.hearts));
            if(GameOver)
            {
                gameOver(&(model.score), &(model.skierCounter));
            }
            Vsync();
            clearScreen((UINT32 *)secondBuffer);
            renderModel(&model, (UINT32 *)secondBuffer);
            flipBuffers(&mainBuffer, &secondBuffer); 



            /*model.snowboarder.counter++;
            model.score.counter+=70;
            printf("%d\n",model.snowboarder.counter);
            
            for (i = 0; i < numOfSkiers; i++)
                model.skiers[i].counter+=70;*/
        }  
        
    }
    stopSound();
    Setscreen(-1, origBuffer, -1);
   clearScreen(base);
   renderGameOver(&model, (UINT32 *)origBuffer);

   while (endKey != ' ' && !quit)
    {
        if (hasInput())
        {   
            endKey = input();

            if (endKey == ESC)
                quit = true;
        }
    }
    clearScreen(base);
    return 0;
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
