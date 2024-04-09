/* File: dth.c
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose:  
 *  This file contains the main loop game. dth stands for Down The Hill.
 *  This file is part of stage 5 of the project, and it adds up to the rest of 
 *  stages after stage 5.
 */
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

UINT8 backBuffer[BUFFER_SIZE + 256];

UINT8* alignAdress(UINT32 address);
void flipBuffers(UINT8 **frontBuffer, UINT8 **backBuffer);

int main()
{
    char key = '\n'; /*variable to check input from user*/
    int i, j; /*i and j used in loops*/
              
    /*Clock variables*/
    UINT32 timeThen, timeNow, timeElapsed;
    
    /*model object*/
    Model model;
    bool quit = false;/*has the player press ESC?*/
    bool isGameOver = false;

    /*Double Buffering var*/
    UINT8 *origBuffer = (UINT8*)getVideoBase();
    UINT8 *mainBuffer = (UINT8*)getVideoBase();
    UINT8 *secondBuffer = backBuffer;

    /*aligning the buffer 256 bytes */
    secondBuffer = alignAdress((UINT32)secondBuffer);

    clearScreen((UINT32*)mainBuffer);
    renderSplashScr(splash, (UINT32*)mainBuffer); /*splash screen*/
    startMusic(JUMP); /*music for the splash screen*/
    
    timeNow = getTime();
    timeThen = timeNow;
    timeElapsed = timeNow - timeThen;

    /*loop for the splash screen*/
    while (key != SPACE_BAR && !quit)
    {
        /*has the player pressed any key?*/
        if (hasInput())
        {   
            /*check its input*/
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

    /*setting the initial state of the game*/
    setModel(&model);
    startMusic(REPTILIA);
    renderModel(&model, (UINT32 *)mainBuffer);
    renderModel(&model, (UINT32 *)secondBuffer);/*a snapshot*/

    /*checking the clock*/
    timeNow = getTime();
    timeThen = timeNow;
    timeElapsed = timeNow - timeThen;
    model.score.timer = timeNow;
    
    /*main loop*/
    while (!quit)
    {  
        /*has the player pressed any keys?*/
        if (hasInput())
        {
            /*check its input*/
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

            /*updating the model*/
            syncEvents(&model, timeNow);
            
            /*Checking if skiers hit any trees*/
            for(i = 0; i < numOfTrees; i++)
            { 
                for(j = 0; j < numOfSkiers; j++)
                    hasSkierColWithTree(&model.skiers[j], &model.trees[i]);
            }

            updateMusic(timeElapsed, REPTILIA);
            /*checking if the player has lost all its lives*/
            isGameOver = checkGameOver(&model.hearts);

            /*update screen*/
            Vsync();
            stopCursor();
            clearScreen((UINT32 *)secondBuffer);
            renderModel(&model, (UINT32 *)secondBuffer);
            flipBuffers(&mainBuffer, &secondBuffer); 
        }  

        /*has the player lost all its lives?*/
        if (isGameOver)
        {   
            /*set the game over screen*/
            gameOver(&model.score, &model.skierCounter);
            stopSound();
            clearScreen((UINT32*)mainBuffer);
            /*playRescueChopper(); unfortunately it's not working for no clear reasons*/
            renderGameOver(&model, (UINT32 *)mainBuffer);
            key = '\n';

            /*awaiting for input from player*/
            while (key != SPACE_BAR && !quit)
            {
                if (hasInput())
                {      
                    key = input();

                    if (key == ESC)
                        quit = true;
                }
            }

            /*if player wants to play again*/
            if (key == SPACE_BAR)
            {
                setModel(&(model));
                startMusic(REPTILIA);
                renderModel(&model, (UINT32 *)mainBuffer);
                renderModel(&model, (UINT32 *)secondBuffer);
            }
        }
    } 
    /*player is done playing*/
    stopSound();
    clearScreen((UINT32*)origBuffer);
    setScreen(origBuffer);
    return 0;
}

/*
Name:
   alignAddress   
Purpose:
    align the second buffer to an divisible by 256 address
Inputs: 
    (UINT32) address: memory address to be align
Outputs:
    An byte pointer that points to a 256 divisible address
Details:
    The address starts at the beginning of the array. and then check for that
    address to be a multiple of 256. once it finds one address, it returns the 
    pointer to it. since the array is 32256, it is garantueed that there is at least
    one address muiltple of 256.
*/
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