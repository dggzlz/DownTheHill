#include "model.h"
#include "events.h"

/* NAME: moveSnowboarder
 * PURPOSE: changes the x-coordinate of the snowboarder object
 *  
 * DETAILS: 
 * 
 * INPUTS:
 *        - Snowboarder *player 
 *          a sno
 *
 * - x (int): an integer that represent the x-coordinate of the pixel by value
 * 
 * - y (int): an integer that represent the y-coordinate of the pixel by value
 * 
 * OUTPUTS: 
 *  - None
 * 
 * ASSUMPTIONS: 
 * - This function assumes the resolution is exactly 640 x 400 
 *   pixels. 
 * - The frame buffer pointer base must be a unsigned int (UINT16) value.
 * 
 */



 
/***INITIALIZE SNOWBOARDER ***/
/*
Name:
        snowboarderSet
Purpose:
        Assignes initial values to the attributes
        of a Snowboarder object. i
Inputs:
       
Outputs: 
        
Assumptions and Limitations: 
        
*/
void snowboarderSet(Snowboarder *player)
{
    player->x = 288;
    player->y = 100; 
    player->vel = 32;
    player->posture = 'r';
    player->invulnerableTimer = 0;
    player->counter = 0;
}

/*SCORE BEHAVIOURS*/
/*ect
            which is the player of the game./*** ***/
/*
Name:
      None  
Purpose:
        
Inputs:
        This function a
       
Outputs: 
        
Assumptions and Limitations: 
        
*/
void newScore(ScoreCounter *score)
{
    score->scorePlayer = 0;
    score->x = 480;
    score->y = 4;
    score->counter = 0;
}

/*LIVES COUNTER BEHAVIOURS*/


/*** ***/
/*
Name:
        
Purpose:
        
Inputs:
       
Outputs: 
        
Assumptions and Limitations: 
        
*/
void newLife(Lives *life)
{
    life->numLives = 3;
    life->x = 620;
    life->y = 24;
    life->gameOver = false;
}

/*SKIER HIT BEHAVIOURS*/


/*** ***/
/*
Name:
        
Purpose:
        
Inputs:
       
Outputs: 
        
Assumptions and Limitations: 
        
*/
void newCounter(SkierCounter *counter)
{
    counter->hitCounter = 0;
    counter->x = 40;
    counter->y = 4;
}

/*SET INITIAL MODEL*/


/*** ***/
/*
Name:
        
Purpose:
        
Inputs:
       
Outputs: 
        
Assumptions and Limitations: 
        
*/
void setModel(Model *model)
{
    int yInitPositions[6] = {400, 400, 544, 544, 688, 688}; /*making use of virtual screen*/
    int i;
    snowboarderSet(&(model->snowboarder));
    newScore(&(model->score));
    newLife(&(model->hearts));
    newCounter(&(model->skierCounter));

    for(i = 0; i < numOfTrees; i++)
    {
        spawnTree(&(model->trees[i]), yInitPositions[i]);
    }
    for(i = 0; i < numOfSkiers; i++)
    {
        spawnSkier(&(model->skiers[i]), yInitPositions[i]);
    }

}



