#include "events.h"
#include "model.h"
#include <osbind.h>


/****ANSYNCHRONOUS EVENTS****/

void moveRequest(long sysCall, Snowboarder *player){

    switch(sysCall) {
        case KEY_LEFT:
            player->x += (player->deltaX = -5);
            break;
        case KEY_RIGHT:
            player->x += (player->deltaX = 5);
            break;
    }
}

void quit(long sysCall){
    /*if (sysCall == ESC)
    /*To put code to kill the program*/

}/*triggered by the key Esc from keyboard*/


/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier){
    skier->x = 0;
    skier->y = 399;
}

void moveSkier(NPCskier *skier){ 
    skier->y += (skier->deltaY = -2);
}

/*Tree events*/
void spawnTree(Tree *tree){
    tree->x = 200;
    tree->y = 399;
}

void moveTree(Tree *tree){
    tree->y += (tree->upwardSpeed = -5);
} 

/*****CONDITION-BASED EVENTS*****/
void checkCollision(Snowboarder *player, NPCskier *skier, Tree *tree)
{
    /*leave it for later*/
}
/*Collisions*/
void collision(Lives *lives, Snowboarder *player){
    decreaseLife(lives);
    resetPos(player);
}/*Obstacle collision event triggered by the player hitting the obstacle*/


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
