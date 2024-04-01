#include "events.h"
#include "model.h"
#include "bool.h"
#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>



/****ANSYNCHRONOUS EVENTS****/

void moveRequest(Snowboarder *player, char x)
{
    int i = 0;
   
        if(x == 'l')
        {
            i = -1;
            player->posture = 'l';
        }
        
        if(x == 'r')
        {
            i = 1;
            player->posture = 'r';
        }

        player->x += player->vel * i; 
}

void quit()
{   
     
}/*triggered by the key Esc from keyboard*/


/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier, int yInit)
{
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    skier->x = newPosition * 64;
    skier->y = yInit;
    skier->deltaX = 0;
    skier->deltaY = -2;
}

void moveSkier(NPCskier *skier)
{ 
    skier->y += skier->deltaY;

    if (skier->y <= -5)
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
    
    if(tree->y <= -5)
        resetTree(tree);
} 

/*****CONDITION-BASED EVENTS*****/

void resetTree(Tree *tree) /*need to implement properly*/
{
    tree->y = 400;
    tree->x = (rand() % 10) * 64; /*((tree->x + 64) % 640); random ass value to just change x temporary*/
} 

void resetSkier(NPCskier *skier)
{
    skier->y = 400;
    skier->x = (rand() % 10) * 64;
}

bool checkColEdge(Snowboarder *player)
{
    bool isCollision = false;

    if (player->x < 0 || (player->x + 64) > 640)
        isCollision = true;

    return isCollision;
}

bool checkCollisionObs(Snowboarder *player, Tree *tree)
{
    
    int length, width, length2, width2;
    BoundingBox playerBox;
    BoundingBox treeBox;
    unsigned char *base = Physbase();
    bool isCollision = false;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    treeBox.maxX = tree->x + 64; 
    treeBox.minX = tree->x;
    treeBox.maxY = tree->y + 64;
    treeBox.minY = tree->y;

/*for visual tests*/
    length = treeBox.maxX - treeBox.minX;
    width = treeBox.maxY - treeBox.minY;
    length2 = playerBox.maxX - playerBox.minX;
    width2 = playerBox.maxY - playerBox.minY;
    /*plotRect(base, treeBox.minX, treeBox.minY, length, width);
    plotRect(base, playerBox.minX, playerBox.minY, length2, width2 );
*/
    if ((playerBox.maxY > treeBox.minY && playerBox.minY < treeBox.maxY)&&(playerBox.maxX > treeBox.minX && playerBox.minX < treeBox.maxX)) 
        isCollision = true;

    return isCollision; 
    
}

bool checkCollisionSkier(Snowboarder *player, NPCskier *skier){


    int length, width, length2, width2;
    BoundingBox playerBox;
    BoundingBox skierBox;
    unsigned char *base = Physbase();
    bool isCollision = false;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    skierBox.maxX = skier->x + 64; 
    skierBox.minX = skier->x;
    skierBox.maxY = skier->y + 64;
    skierBox.minY = skier->y;

/*for visual tests*/
    length = skierBox.maxX - skierBox.minX;
    width = skierBox.maxY - skierBox.minY;
    length2 = playerBox.maxX - playerBox.minX;
    width2 = playerBox.maxY - playerBox.minY;
    /*plotRect(base, skierBox.minX, skierBox.minY, length, width);
    plotRect(base, playerBox.minX, playerBox.minY, length2, width2 );
*/
    if ((playerBox.maxY > skierBox.minY && playerBox.minY < skierBox.maxY)
    &&(playerBox.maxX > skierBox.minX && playerBox.minX < skierBox.maxX)) 
        isCollision = true;

    return isCollision; 
}

/*Collisions*/
void collisionObs(Lives *lives, Snowboarder *player)
{
    if(getTime() >= player->invulnerableTimer)
    {
        decreaseLife(lives);
        resetPos(player);
        player->invulnerableTimer = getTime() + 5 * 70;
    }

}/*Obstacle collision event triggered by the player hitting the obstacle*/

void collisionSkier(ScoreCounter *score, SkierCounter *counter,
                     UINT32 *lastUpdateTime, UINT32 timeCurr)
{
    scoreUpdates(score, lastUpdateTime, timeCurr, true);
    counter->hitCounter += 1;
}

/*position reset*/

void decreaseLife(Lives *lives)
{
    lives->numLives += -1;

    if (lives->numLives == 0)
    {
        gameOver(true);
    }
} 

void resetPos(Snowboarder *player)
{
    player->x = 320;
}

/*Skier Collision*/

void scoreUpdates(ScoreCounter *playerScore, UINT32 *lastUpdateTime,
                     UINT32 timeCurr, bool skierHit)
{
   
   if(timeCurr - *lastUpdateTime >= 70 * 3) 
   {
    playerScore->scorePlayer += 10;
    *lastUpdateTime = timeCurr;
   /* printf("Score Updated: %d\n", playerScore->scorePlayer);*/
   }
    if(skierHit == true)
    {
    playerScore->scorePlayer += 30;
   /* printf("SkierHit,Score Updated: %d\n", playerScore->scorePlayer);*/
    }

}

/*Game ends*/
void gameOver(){
    /*code to end the game*/
}
