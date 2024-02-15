#include <model.h>

/*behaviour functions to add:

********************************snowBoarder
- moveSnowboarder
- snowBoarderCollidesSkier
- snowBoarderCollidesObstacle

********************************skier
- moveSkier
- snowBoarderCollidesSkier
- skierCollidesObstacles
- skierSpawns
- skierDissapears like my fourth wife

*********************************scoreCounter
-scoreIncrease

*********************************finalScore
- calculateFinalScore //in game score + (#skiersHit * 3)//


*********************************skiersHit
- countIncrease

*********************************tree
- moveTree
- spawnTree



/*Snowboarder BEHAVIOURS*/
void moveSnowboarder(Snowboarder *player, int newPosX)
{
    player->x += (player->deltaX = newPosX);
}


/*SKIER BEHAVIOURS*/
void moveSkier(NPCskier *skier, int newPosX, int newPosY){ 

    skier->x += (skier->deltaX = newPosX);
    skier->y += (skier->deltaY = newPosY);
}

void skierSpawn(NPCskier *skier){
    skier->y = 399; 
    skier->x = 200;
}

void skierDisappears();

/*TREE BEHAVIOURS*/
void moveTree(Tree *tree)
{
    tree->y += -4;
}

void spawnTree(Tree *tree)
{
    skier->y = 399; 
    skier->x = 400; /*we should design a proper pattern*/
}

void treeDissapears(); /* not sure if this is events as well*/

/*SCORE BEHAVIOURS*/
void scoreUpdates();

/*LIVES COUNTER BEHAVIOURS*/
void liveUpdates();

/*SKIER HIT BEHAVIOURS*/
void countIncrease();




