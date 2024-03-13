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


/*SKIER BEHAVIOURS*/
NPCskier newSkier(){
    NPCskier newSkier = {0, 0, 0, 0};
    return newSkier;
}


/*TREE BEHAVIOURS*/

Tree newTree(unsigned int x) /*for now returning a copy of the struct*/
{
    Tree newTree = {0, 0, 0};
    return newTree;
}

/*SCORE BEHAVIOURS*/
ScoreCounter newScore()
{
    ScoreCounter score = {0, 0, 0};
    return score;
}



/*LIVES COUNTER BEHAVIOURS*/
Lives newLife()
{
    Lives newLife = {3, 576, 3};
    return newLife;
}



/*SKIER HIT BEHAVIOURS*/
SkierCounter newCounter()
{
    SkierCounter counter = {0, 0, 0, 0};
    return counter;
}





