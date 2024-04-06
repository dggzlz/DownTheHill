#include "events.h"
#include "RASTER.H"
#include "model.h"
#include "bool.h"
#include "effects.h"
#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>



/****ANSYNCHRONOUS EVENTS****/
void moveRequest(Snowboarder *player, char ch)
{
    int i = 0;
    player->posture = ch;
    
    if(ch == POSTURE_L)
    {
        i = -1;
    }
    else if(ch == POSTURE_R)
    {
        i = 1;
    }

    player->x += player->vel * i; 
    
    if(isPlayerInvulnerable(player))
    {
        if(player->x > 576)
            player->x = 576;
        if(player->x < LEFT_EDGE)
            player->x = LEFT_EDGE;
    }

    
    /*
    if(checkCollisionObs(&(model.snowboarder), &(model.trees[i])))
        collisionObs(&(model.hearts), &(model.snowboarder));

    if (checkCollisionSkier(&(model.snowboarder), &(model.skiers[i])))
        collisionSkier(&(model.score), &(model.skierCounter), &lastUpdateTime, timeNow);

    if (checkColEdge(&(model.snowboarder)) || treeCol)
                collisionObs(&(model.hearts), &(model.snowboarder));
    */            
                
}

/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier, int yInit)
{
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    skier->x = newPosition * 64;
    skier->y = yInit;
    skier->pos = 1;
    skier->deltaY = -2;
    skier->timer = 0;
    skier->toDraw = true;
}

void moveSkier(NPCskier *skier)
{ 
    skier->y += skier->deltaY;
    
    if(getTime() >= skier->timer)
    {
        if (skier->pos == 1)
        {
            skier->pos = 0;
        }else 
        {
            skier->pos = 1;
        }
        skier->timer = getTime() + 2 * 70;
    }

    
    if (skier->y <= 31)
        resetSkier(skier);
}

/*Tree events*/
void spawnTree(Tree *tree, int yInit)
{   
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    tree->x = newPosition * 64;
    tree->y = yInit;
    tree->upwardSpeed = -3;
}

void moveTree(Tree *tree)
{
    tree->y += tree->upwardSpeed;
    
    if(tree->y <= 31)
        resetTree(tree);
} 

/*****CONDITION-BASED EVENTS*****/

void resetTree(Tree *tree) 
{
    tree->y = 400;
    tree->x = (rand() % 10) * 64; 
} 

void resetSkier(NPCskier *skier)
{
    skier->y = 400;
    skier->x = (rand() % 10) * 64;
    skier->toDraw = true;
}

bool checkColEdge(Snowboarder *player)
{
    bool isCollision = false;

    if (player->x < LEFT_EDGE || (player->x + 64) > RIGHT_EDGE)
        isCollision = true;

    return isCollision;
}

bool checkCollisionObs(Snowboarder *player, Tree *tree)
{
    
    BoundingBox playerBox;
    BoundingBox treeBox;
    bool isCollision = false;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    treeBox.maxX = tree->x + 64; 
    treeBox.minX = tree->x;
    treeBox.maxY = tree->y + 64;
    treeBox.minY = tree->y;

    if ((playerBox.maxY > treeBox.minY && playerBox.minY < treeBox.maxY)
        &&(playerBox.maxX > treeBox.minX && playerBox.minX < treeBox.maxX)) 
        isCollision = true;

    return isCollision; 
    
}

bool checkCollisionSkier(Snowboarder *player, NPCskier *skier)
{
    BoundingBox playerBox;
    BoundingBox skierBox;
    bool isCollision = false;

    if (skier->toDraw)
    {
        playerBox.maxX = player->x + 64;
        playerBox.minX = player->x;
        playerBox.maxY = player->y + 64;
        playerBox.minY = player->y;
        
        skierBox.maxX = skier->x + 64; 
        skierBox.minX = skier->x;
        skierBox.maxY = skier->y + 64;
        skierBox.minY = skier->y;

        if ((playerBox.maxY > skierBox.minY && playerBox.minY < skierBox.maxY)
            &&(playerBox.maxX > skierBox.minX && playerBox.minX < skierBox.maxX)) 
        {    
            isCollision = true;
            skier->toDraw = false;
        }
    }
    return isCollision; 
}

void hasSkierColWithTree(NPCskier *skier, Tree *tree)
{
    BoundingBox treeBox;
    BoundingBox skierBox;

    if(skier->x == tree->x)
    {
        if (skier->toDraw)
        {

            treeBox.maxX = tree->x + 64; 
            treeBox.minX = tree->x;
            treeBox.maxY = tree->y + 64;
            treeBox.minY = tree->y;
            
            skierBox.maxX = skier->x + 64; 
            skierBox.minX = skier->x;
            skierBox.maxY = skier->y + 64;
            skierBox.minY = skier->y;

            if ((treeBox.maxY > skierBox.minY && treeBox.minY < skierBox.maxY)
                &&(treeBox.maxX > skierBox.minX && treeBox.minX < skierBox.maxX)) 
            {    
                skier->toDraw = false;
            }
        }
    }
}

/*Collisions*/
void collisionObs(Lives *lives, Snowboarder *player)
{
    
    if(!isPlayerInvulnerable(player))
    {
        decreaseLife(lives);
        resetPos(player);
        player->invulnerableTimer = getTime() + 3 * 70;
        player->counter = 0;

    }

}/*Obstacle collision event triggered by the player hitting the obstacle*/

void collisionSkier(ScoreCounter *score, SkierCounter *counter,
                    UINT32 timeCurr)
{
    scoreUpdates(score, timeCurr, true);
    /*playSkierDeath();*/
    counter->hitCounter += 1;
}

/*position reset*/

void decreaseLife(Lives *lives)
{
    lives->numLives += -1;

    if (lives->numLives == 0)
    {
        lives->gameOver = true;
    }
} 

void resetPos(Snowboarder *player)
{
    player->x = 288;
}

/*Skier Collision*/

/*void scoreUpdates(ScoreCounter *playerScore, bool skierHit)*/
void scoreUpdates(ScoreCounter *score, UINT32 timeCurr, bool skierHit)
{   

    if((timeCurr - score->timer) >= 70 * 3) 
    {
        score->scorePlayer += 10;
        score->timer = timeCurr;
    }

    if(skierHit)
    {
        score->scorePlayer += 30;
    }
}

bool isPlayerInvulnerable(Snowboarder *player)
{
    bool isInvulnerable;
    
    if(getTime() < player->invulnerableTimer)
        isInvulnerable = true;
    else
        isInvulnerable = false;

    return isInvulnerable;
}

/*Game ends*/
bool checkGameOver(Lives *lives)
{
    bool isOver = false;
    if(lives->gameOver == true)
        isOver = true;

    return isOver;
}
void gameOver(ScoreCounter *score, SkierCounter *hitCount)
{
    score->x= 400;
    score->y=300;
    hitCount->x=400;
    hitCount->y=175;
}
