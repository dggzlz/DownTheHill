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

void snowboarderSet(Snowboarder *player){
    player->x = 320;
    player->y = 200; 
    player->deltaX = 0;
    player->posture = 'r';
}



/*SCORE BEHAVIOURS*/
void newScore(ScoreCounter *score)
{
    score->scorePlayer = 0;
    score->x = 0;
    score->y = 0;
}



/*LIVES COUNTER BEHAVIOURS*/
void newLife(Lives *life)
{
    life->numLives = 3;
    life->x = 620;
    life->y = 0;
}

/*SKIER HIT BEHAVIOURS*/
void newCounter(SkierCounter *counter)
{
    counter->hitCounter = 0;
    counter->scoreCounter = 0;
    counter->x = 0;
    counter->y = 0;
}

/*SET INITIAL MODEL*/
void setModel(Model *model)
{
    snowboarderSet(&(model->snowboarder));
    newScore(&(model->score));
    newLife(&(model->hearts));
    newCounter(&(model->skierCounter));
}



