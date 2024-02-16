#include "model.h"



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
void moveSnowboarder(Snowboarder *player, int deltaPosX){

    player->x += (player->deltaX = deltaPosX);
}

/*SKIER BEHAVIOURS*/
void moveSkier(NPCskier *skier, int deltaPosX, int deltaPosY){ 

    skier->x += (skier->deltaX = deltaPosX);
    skier->y += (skier->deltaY = deltaPosY);
}

void skierSpawn(UINT32 *base){

    NPCskier newSkier = {skier,50,399,-5}; /*fixed coordinates for now*/
    plotBitMap64(base, newTree->x,newTree->y,newSkier->skier,128);
    /*hardcoded for now*/
}

/*TREE BEHAVIOURS*/
void moveTree(Tree *tree)
{
    tree->y += -4;
}

void spawnTree(UINT32 *base)
{
    Tree newTree = {tree,50,399,-5};/*fixxed x for now*/
    plotBitMap64(base, newTree->x, newTree->y, newTree->tree, 128);
}

/*SCORE BEHAVIOURS*/
void scoreUpdates(ScoreCounter *playerScore)
{
    playerScore->score += 1000;
}

/*LIVES COUNTER BEHAVIOURS*/
void updateLives(Lives *lives)
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




