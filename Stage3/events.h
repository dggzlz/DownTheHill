#ifndef EVENTS_H
#define EVENTS_H

/****ANSYNCHRONOUS EVENTS****/

void moveRequest(); /*triggered by the left or right arrows from keyboard*/
void quit();        /*triggered by the key Esc from keyboard*/

/****SYNCHRONOUS TIMED EVENTS*****/

skierSpawn(); /*every 5 seconds*/
skierMoves(); /*every 2 seconds*/
skierMovesUp(); /*every 2 seconds*/
treeSpawn(); /*every second*/
treeMoves(); /*every 0.5 seconds*/

/*****CONDITION-BASED EVENTS*****/

/*Collisions*/
obsCollision(); /*Obstacle collision event triggered by the player hitting the obstacle*/
edgeCollision();/* triggered when the player touches either vertical edge*/
topCollision(); /* triggered when the obstcale or the skier hits the top edge*/

/*position reset*/
invincible(); /*triggered by the Obstacle collision or the edge collision*/
blink(); /*triggered by the Obstacle collision or the edge collision*/
decreaseLife(); 
backToCentre();

/*Skier Collision*/
skierCollision();
increaseCounter();

/*Game ends*/
gameOver();


#endif