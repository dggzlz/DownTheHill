#include <model.h>

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




