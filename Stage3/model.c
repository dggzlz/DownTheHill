#include model.h

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


void moveSnowboarder();
void snowboarderCollidesSkier();
void snowboarderCollidesObstacle();

/*SKIER BEHAVIOURS*/
void skierSpawn(NPCskier *skier){
    skier->y = 399; 
    skier->x = randint();

    skier->x += skier->deltaX;
    skier->y += -2; /*fixed rate that goes upward*/
}

void moveSkier(NPCskier *skier, int newPosX, int newPosY){

    skier->x += (skier->deltaX = newPosX);
    skier->y += (skier->deltaY = newPosY);
}

/*void snowboarderCollidesSkier();*/
void skierCollidesObstacle(){
    return;
}

void skierDissapears();

/*SCORE BEHAVIOURS*/
void scoreIncrease(scoreCounter *score){
    score->score += 1;
}

/*FINAL SCORE BEHAVIOURS*/
void calcFinalScore(scoreCounter *score, ){
    
}

/*SKIER HIT BEHAVIOURS*/
void countIncrease();

/*TREE BEHAVIOURS*/
void moveTree();
void spawnTree();








*/