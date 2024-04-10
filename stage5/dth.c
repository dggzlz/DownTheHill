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

#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include "sync.h"
#include <osbind.h>
#include <stdio.h>
 
int main()
{
    char key = '\n'; /*variable to check input from user*/
    int i, j; /*i and j used in loops*/
              
    /*Clock variables*/
    UINT32 timeThen, timeNow, timeElapsed;
    
    /*model object*/
    Model model;
    bool quit = false;/*has the player press ESC?*/
    bool isOver = false;

    /*Double Buffering var*/
    UINT8 *mainBuffer = (UINT8*)getVideoBase();

    clearScreen((UINT32*)mainBuffer);
    
    timeNow = getTime();
    timeThen = timeNow;
    timeElapsed = timeNow - timeThen;

    /*setting the initial state of the game*/
    setModel(&model);
    renderModel(&model, (UINT32 *)mainBuffer);
    
    /*checking the clock*/
    timeNow = getTime();
    timeThen = timeNow;
    timeElapsed = timeNow - timeThen;
    model.score.timer = timeNow;
    
    /*main loop*/
    while (!quit && !isOver)
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
                moveRequest(&model.snowboarder, 'l');
            }
            else if (key == RIGHT_ARROW)
            {
                moveRequest(&model.snowboarder, 'r');
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

            /*checking if the player has lost all its lives*/
           if (model.hearts.numLives == 0)  
                isOver = true;

            /*update screen*/
            Vsync();
            stopCursor();
            clearScreen((UINT32 *)mainBuffer);
            renderModel(&model, (UINT32 *)mainBuffer);    
        }  
    }
    return 0;
}

