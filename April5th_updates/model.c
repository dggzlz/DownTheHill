#include "model.h"
#include "events.h"

#define PLAYER_Y 100

#define SCORE_X 480
#define SCORE_Y 4

#define LIVES_X 620
#define LIVES_Y 24

#define COUNTER_X 40
#define COUNTER_Y 4
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
    player->x = SCREEN_CENTER_X;
    player->y = PLAYER_Y; 
    player->vel = 32;
    player->posture = POSTURE_R;
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
    score->x = SCORE_X;
    score->y = SCORE_Y;
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
    life->x = LIVES_X;
    life->y = LIVES_Y;
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
    counter->x = COUNTER_X;
    counter->y = COUNTER_Y;
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
    int i,j;
    snowboarderSet(&(model->snowboarder));
    newScore(&(model->score));
    newLife(&(model->hearts));
    newCounter(&(model->skierCounter));

    for(i = 0; i < numOfTrees; i++)
    {
        spawnTree(&model->trees[i], yInitPositions[i]);
        /*j = &model->trees[i]->x;
        j = j >> 6;
        &model->trees[i][j];*/
    }
    
    for(i = 0; i < numOfSkiers; i++)
    {
        spawnSkier(&(model->skiers[i]), yInitPositions[i]);
    }

}



