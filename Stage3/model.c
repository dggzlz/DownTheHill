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

Snowboarder snowboarderSet(){
    Snowboarder newPlayer = {320, 200, 0};
    return newPlayer;
}

void moveSnowboarder(Snowboarder *player, int deltaPosX){

    player->x += (player->deltaX = deltaPosX);
}

/*SKIER BEHAVIOURS*/
NPCskier newSkier(){
    NPCskier newSkier = {0, 0, 0, 0};
    return newSkier;
}


/*TREE BEHAVIOURS*/

Tree createTree(unsigned int x) /*for now returning a copy of the struct*/
{
    Tree newTree = {0, 0, 0};
    return newTree;
}

/*SCORE BEHAVIOURS*/
void scoreUpdates(ScoreCounter *playerScore)
{
    playerScore->scorePlayer += 1000;
}

/*LIVES COUNTER BEHAVIOURS*/
Lives createLife()
{
    Lives newLife = {3,576,3};
    return newLife;
}

void updatesLives(Lives *lives)
{
    lives->numLives += -1;
    if(lives->numLives == 0)
    {
        gameOver();
    }
}

/*SKIER HIT BEHAVIOURS*/
void skierHitCountIncrease(SkierCounter *count)
{
    count->hitCounter += 1;
    count->scoreCounter += 3000;
}




