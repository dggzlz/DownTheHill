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
#include "sync.h"
#include <osbind.h>
#include <stdio.h>
 
#define BUFFER_SIZE 32000
#define JUMP 'j'
#define REPTILIA 'r'
#define LEFT 'l'
#define RIGHT 'r'
#define SPACE_BAR ' '

UINT8 backBuffer[BUFFER_SIZE + 256];


bool startGame(Model *model);
UINT8* alignAdress(UINT32 address);
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer);

int main()
{
    char key = '\n'; /*variable to check input from user*/
    int i, j; /*i used in loops*/
              
    /*Clock variables*/
    UINT32 timeThen, timeNow, timeElapsed;
    
    /*model object*/
    Model model;
    bool quit = false;/*has the player press ESC?*/
    bool isGameOver = false;
    bool donePlaying = false;

    /*Double Buffering var*/
    UINT8 *origBuffer = (UINT8*)getVideoBase();
    UINT8 *mainBuffer = (UINT8*)getVideoBase();
    UINT8 *secondBuffer = backBuffer;
    
    timeNow = getTime();
    timeThen = timeNow;
    model.score.timer = timeNow;

    /*aligning the buffer 256 bytes */
    secondBuffer = alignAdress((UINT32)secondBuffer);

    clearScreen((UINT32*)mainBuffer);
    renderSplashScr(splash, (UINT32*)mainBuffer); /*splash screen*/
    startMusic(JUMP); /*music for the splash screen*/
    
    timeElapsed = timeNow - timeThen;

    /*loop for the splash screen*/
    while (key != SPACE_BAR && !quit)
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
            stopCursor();       
            updateMusic(timeElapsed, JUMP);
        }
    }
    clearScreen((UINT32*)mainBuffer);
    stopSound();

    setModel(&(model));
    startMusic(REPTILIA);
    renderModel(&model, (UINT32 *)mainBuffer);
    renderModel(&model, (UINT32 *)secondBuffer);


    timeNow = getTime();
    timeThen = timeNow;
    /*timeElapsed = timeNow - timeThen;
    
    /*main loop*/
 
    while (!quit && !donePlaying)
    {  
        /*quit = startGame(&model);*/
        if (hasInput())
        {
            key = input();
            if (key == ESC)
            {
                quit = true;
            } 
            else if (key == LEFT_ARROW)
            {
                moveRequest(&model.snowboarder, LEFT);
            }
            else if (key == RIGHT_ARROW)
            {
                moveRequest(&model.snowboarder, RIGHT);
            }
        }

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 0)
        {
            timeNow = getTime();
            timeThen = timeNow;

            syncEdge(&model);
            /*if (checkColEdge(&(model.snowboarder)))
                collisionObs(&(model.hearts), &(model.snowboarder));*/
            
            syncTree(&model);    
            syncSkier(&model, timeNow);

            /*JD FUNCTION*/
            for(i = 0; i < numOfTrees; i++)
            { 
                for(j = 0; j < numOfSkiers; j++)
                    hasSkierColWithTree(&model.skiers[j], &model.trees[i]);
            }

            scoreUpdates(&model.score, timeNow, false);
            /*scoreUpdates(&(model.score), false);*/
            updateMusic(timeElapsed, REPTILIA);
            isGameOver = checkGameOver(&model.hearts);

            if(isGameOver)
            {
                gameOver(&model.score, &model.skierCounter);
            }

            Vsync();
            stopCursor();
            clearScreen((UINT32 *)secondBuffer);
            renderModel(&model, (UINT32 *)secondBuffer);
            flipBuffers(&mainBuffer, &secondBuffer); 
        }  

        if (isGameOver)
        {
            stopSound();
            clearScreen((UINT32*)mainBuffer);
            playRescueChopper();
            renderGameOver(&model, (UINT32 *)mainBuffer);
            key = '\n';

            while (key != SPACE_BAR && !quit)
            {
                if (hasInput())
                {      
                    key = input();

                    if (key == ESC)
                        quit = true;
                    else if (key == SPACE_BAR)
                        donePlaying = false;
                }
            }

            if (!donePlaying)
            {
                setModel(&(model));
                startMusic(REPTILIA);
                renderModel(&model, (UINT32 *)mainBuffer);
                renderModel(&model, (UINT32 *)secondBuffer);
            }
        }
    }
/*
    stopSound();
    clearScreen((UINT32*)mainBuffer);
    playRescueChopper();
    renderGameOver(&model, (UINT32 *)mainBuffer);
    key = '\n';

    while (key != SPACE_BAR && !quit)
    {
        if (hasInput())
        {   
            key = input();

            if (key == ESC)
                quit = true;
            else if (key == SPACE_BAR)
                donePlaying = true;
        }
    }
*/  
    stopSound();
    clearScreen((UINT32*)origBuffer);
    setScreen(origBuffer);
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

    setScreen(*frontBuffer);
}

/*
bool startGame(Model *model)
{
    int i, j;
    bool quit = false,
         isGameOver = false;
    char key = '\n';

    UINT32 timeThen, timeNow, timeElapsed;

    UINT8 *origBuffer = (UINT8*)getVideoBase();
    UINT8 *mainBuffer = (UINT8*)getVideoBase();
    UINT8 *secondBuffer = backBuffer;   

    if (hasInput())
    {
        key = input();
        if (key == ESC)
        {
            quit = true;
        } 
        else if (key == LEFT_ARROW)
        {
            moveRequest(&model->snowboarder, LEFT);
        }
        else if (key == RIGHT_ARROW)
        {
            moveRequest(&model->snowboarder, RIGHT);
        }
    }

    timeNow = getTime();
    timeElapsed = timeNow - timeThen;

    if (timeElapsed > 0)
    {
        timeNow = getTime();
        timeThen = timeNow;

        syncEdge(&model);
        /*if (checkColEdge(&(model.snowboarder)))
            collisionObs(&(model.hearts), &(model.snowboarder));
        
        syncTree(&model);    
        syncSkier(&model, timeNow);

        /*JD FUNCTION
        for(i = 0; i < numOfTrees; i++)
        { 
            for(j = 0; j < numOfSkiers; j++)
                hasSkierColWithTree(&model->skiers[j], &model->trees[i]);
        }

        scoreUpdates(&model->score, timeNow, false);
        /*scoreUpdates(&(model.score), false);
        updateMusic(timeElapsed, REPTILIA);
        isGameOver = checkGameOver(&model->hearts);

        if(isGameOver)
        {
            gameOver(&model->score, &model->skierCounter);
        }

        Vsync();
        stopCursor();
        clearScreen((UINT32 *)secondBuffer);
        renderModel(&model, (UINT32 *)secondBuffer);
        flipBuffers(&mainBuffer, &secondBuffer); 
    }  
    return quit;
}
/*
void splashLoop()
void gameLoop()
void gameOverLoop()
*/