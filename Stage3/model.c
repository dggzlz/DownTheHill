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
Snowboarder createSnowboarder()
{
    
}

void moveSnowboarder(Snowboarder *player, int deltaPosX)
{
    player->x += (player->deltaX = deltaPosX);
}

/*SKIER BEHAVIOURS*/
void moveSkier(NPCskier *skier, int deltaPosX, int deltaPosY){ 

    skier->x += (skier->deltaX = deltaPosX);
    skier->y += (skier->deltaY = deltaPosY);
}

void skierSpawn(NPCskier *skier){
    skier->y = 399; 
    skier->x = 200;
    /*hardcoded for now*/
}

/*TREE BEHAVIOURS*/
void moveTree(Tree *tree)
{
    tree->y += -10;
}

Tree createTree(unsigned int x) /*for now returning a copy of the struct*/
{
    Tree newTree = {tree,x,400,-10};
    return newTree;
}

Lives createLife()
{
    Lives newLife = {heartsHealth,3,576,3};
    return newLife;
}

/*SCORE BEHAVIOURS*/
void scoreUpdates(ScoreCounter *playerScore)
{
    playerScore->score += 1000;
}

/*LIVES COUNTER BEHAVIOURS*/
void updateLives(Lives *lives)
{
    lives->numLives -= 1;
    if(lives->numLives == 0)
    {
        printf("gameOver()\n");
    }
}

/*SKIER HIT BEHAVIOURS*/
void skierHitCountIncrease(SkierCounter *count)
{
    count->hitCounter += 1;
    count->scoreCounter += 3000;
}




