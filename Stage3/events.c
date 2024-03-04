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

/*Skier events*/
void spawnSkier(NPCskier *skier){
    skier->x = location();
    skier->y = 399;
}

void moveSkier(NPCskier *skier){ 
    skier->y += (skier->deltaY = -2);
}

/*Tree events*/
void spawnTree(){
    tree->x = location();
    tree->y = 399;
}

void treeMoves(Tree *tree){
    tree->y += (tree->deltaY = -5);
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
