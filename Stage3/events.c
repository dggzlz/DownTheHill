#include "events.h"

/****ANSYNCHRONOUS EVENTS****/

void moveRequest(){
    char  = Cconin();

    if (ch == 0x1B){ /*ASCII code = left arrow*/
        moveSnowboarder(player, )
    }
    else if (ch == )
}
void quit();        /*triggered by the key Esc from keyboard*/

/****SYNCHRONOUS TIMED EVENTS*****/

void skierSpawn(); /*every 5 seconds*/
void skierMoves(); /*every 2 seconds*/
void skierMovesUp(); /*every 2 seconds*/
void treeSpawn(); /*every second*/
void treeMoves(); /*every 0.5 seconds*/

/*****CONDITION-BASED EVENTS*****/

/*Collisions*/
void obsCollision(); /*Obstacle collision event triggered by the player hitting the obstacle*/
void edgeCollision();/* triggered when the player touches either vertical edge*/
void topCollision(); /* triggered when the obstcale or the skier hits the top edge*/

/*position reset*/
void invincible(); /*triggered by the Obstacle collision or the edge collision*/
void blink(); /*triggered by the Obstacle collision or the edge collision*/
void decreaseLife(); 
void backToCentre();

/*Skier Collision*/
void skierCollision();
void increaseCounter();

/*Game ends*/
void gameOver();
