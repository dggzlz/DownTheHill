#include "events.h"
#include "model.h"
#include <osbind.h>

#define KEY_LEFT 0x004B00000
#define KEY_RIGHT 0x004D0000
#define ESC 0x0001001B

/****ANSYNCHRONOUS EVENTS****/

void moveRequest(){
    long key = Cnecin();

    switch(key) {
        case KEY_LEFT:
            moveSnowboarder(player, -1);
            break;
        case KEY_RIGHT:
            moveSnowboarder(playaer, 1);
            break;
        default:
            break
    }
}

void quit(){
    if (Cnecin() == ESC)
        /*To put code to kill the program*/

}        /*triggered by the key Esc from keyboard*/

/****SYNCHRONOUS TIMED EVENTS*****/

void skierSpawn(){
    spawnSkier();
} /*every 5 seconds*/

void skierMoves(){

}
 /*every 2 seconds*/
void skierMovesUp(); /*every 2 seconds*/

void newTree(){
    spawnTree();
} /*every second*/

void treeMoves(){
    moveTree(tree);
} /*every 0.5 seconds*/

/*****CONDITION-BASED EVENTS*****/

/*Collisions*/
void collision(){
    invincible();
    blink();
    decreaseLife();
    backToCentre();
} /*Obstacle collision event triggered by the player hitting the obstacle*/

void topCollision(){

} /* triggered when the obstcale or the skier hits the top edge*/

/*position reset*/
void invincible(); /*triggered by the Obstacle collision or the edge collision*/
void blink(); /*triggered by the Obstacle collision or the edge collision*/

void decreaseLife(){
    updatesLives(lives);
} 

void backToCentre(SnowBoarder *player){
    player->x = 320;
    player->y = 200;
};

/*Skier Collision*/
void skierCollision();
void increaseCounter();

/*Game ends*/
void gameOver();
