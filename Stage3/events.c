#include "events.h"
#include "model.h"
#include <osbind.h>


/****ANSYNCHRONOUS EVENTS****/

void moveRequest(long sysCall, Snowboarder *player){

    switch(sysCall) {
        case KEY_LEFT:
            moveSnowboarder(player, -5);
            break;
        case KEY_RIGHT:
            moveSnowboarder(player, 5);
            break;
    }
}

void quit(long sysCall){
    /*if (sysCall == ESC)
        /*To put code to kill the program*/

}        /*triggered by the key Esc from keyboard*/


/****SYNCHRONOUS TIMED EVENTS*****/

NPCskier newSkier(){
    NPCskier newSkier = {0, 0, 0, 0};
    return newSkier;
}



void treeMoves(Tree *tree){
    tree->y += -5;
} 

/*****CONDITION-BASED EVENTS*****/

/*Collisions*/
void collision(){
    /*decreaseLife();
    backToCentre();*/
} /*Obstacle collision event triggered by the player hitting the obstacle*/


/*position reset*/

void decreaseLife(Lives *lives){
    updatesLives(lives);
} 

void backToCentre(Snowboarder *player){
    player->x = 320;
}

/*Skier Collision*/
void skierCollision(NPCskier *skier, SkierCounter *counter){
    skierHitCountIncrease(counter);
}

/*Game ends*/
void gameOver(){
    /*code to end the game*/
}
