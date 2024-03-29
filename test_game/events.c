#include "events.h"
#include "model.h"
#include "bool.h"
#include "keys.h"
#include <osbind.h>
#include <stdlib.h>



/****ANSYNCHRONOUS EVENTS****/

void moveRequest(Snowboarder *player, int newDelta)
{
    player->x += (player->deltaX = newDelta); 
}

void quit(long sysCall){
    /*if (sysCall == ESC)
    /*To put code to kill the program*/

}/*triggered by the key Esc from keyboard*/


/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier){
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    skier->x = newPosition * 64;
    skier->y = 399;
    skier->deltaX = 0;
    skier->deltaY = 0;
}

void moveSkier(NPCskier *skier)
{ 
    skier->y += (skier->deltaY = -2);
}

/*Tree events*/
void spawnTree(Tree *tree)
{
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    tree->x = newPosition * 64;
    tree->y = 399;
    tree->upwardSpeed = -5;
}

void moveTree(Tree *tree)
{
    tree->y += tree->upwardSpeed;
} 

/*****CONDITION-BASED EVENTS*****/
bool checkColEdge(Snowboarder *player)
{
    bool isCollision = false;

    if (player->x == 0 || (player->x + 64) == 639)
        isCollision = true;

    return isCollision;
}

bool checkCollisionObs(Snowboarder *player, Tree *tree)
{
    bool isCollision = true;

    BoundingBox playerBox;
    BoundingBox treeBox;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    treeBox.maxX = tree->x + 64; 
    treeBox.minX = tree->x;
    treeBox.maxY = tree->y + 64;
    treeBox.minY = tree->y;

    /* Check if player and tree are intersecting along x-axis */
    if (playerBox.maxX < treeBox.minX || playerBox.minX > treeBox.maxX) {
        isCollision = false; /* No collision*/
    }

    /* Check if player and tree are intersecting along y-axis */
    if (playerBox.maxY < treeBox.minY || playerBox.minY > treeBox.maxY) {
        isCollision = false; /*No collision*/
    }

    /* If both x-axis and y-axis overlap, boxes are colliding*/
    return isCollision; 
}

bool checkCollisionSkier(Snowboarder *player, NPCskier *skier){
    
    bool isCollision = true;

    BoundingBox playerBox;
    BoundingBox skierBox;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    skierBox.maxX = skier->x + 64; 
    skierBox.minX = skier->x;
    skierBox.maxY = skier->y + 64;
    skierBox.minY = skier->y;

    /* Check if player and skier are intersecting along x-axis */
    if (playerBox.maxX < skierBox.minX || playerBox.minX > skierBox.maxX) {
        isCollision = false; /* No collision*/
    }

    /* Check if player and skier are intersecting along y-axis */
    if (playerBox.maxY < skierBox.minY || playerBox.minY > skierBox.maxY) {
        isCollision = false; /* No collision*/
    }

    return isCollision;
}

/*Collisions*/
void collisionObs(Lives *lives, Snowboarder *player){
    decreaseLife(lives);
    resetPos(player);
}/*Obstacle collision event triggered by the player hitting the obstacle*/

void collisionSkier(ScoreCounter *score, SkierCounter *counter){
    scoreUpdates(score);
    skierHitCountIncrease(counter);
}

/*position reset*/

void decreaseLife(Lives *lives){
    lives->numLives += -1;

    if(lives->numLives == 0)
    {
        gameOver();
    }
} 

void resetPos(Snowboarder *player){
    player->x = 320;
}

/*Skier Collision*/

void scoreUpdates(ScoreCounter *playerScore)
{
    playerScore->scorePlayer += 1000;
}


void skierHitCountIncrease(SkierCounter *count)
{
    count->hitCounter += 1;
    count->scoreCounter += 3000;
}

/*Game ends*/
void gameOver(){
    /*code to end the game*/
}
