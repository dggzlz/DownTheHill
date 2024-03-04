#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

#define KEY_LEFT 0x004B00000
#define KEY_RIGHT 0x004D0000
#define ESC 0x0001001B

/*ANSYNCHRONOUS EVENTS*/
void moveRequest(long sysCall, Snowboarder *player);/*triggered by the left or right arrows from keyboard*/
void quit(long sysCall); /*triggered by the key Esc from keyboard*/

/*SYNCHRONOUS TIMED EVENTS*/

NPCskier newSkier(); /*return the skier to be spawned, as well as the coordinates where it will spawn*/
void moveSkier(NPCskier *skier, int deltaPosX, int deltaPosY);
Tree newTree();
void treeMoves(Tree *tree);

/*CONDITION-BASED EVENTS*/

/*Collisions*/
void collision();/*Obstacle collision event triggered by the player hitting the obstacle*/

/*position reset*/

void decreaseLife(Lives *lives);
void backToCentre(Snowboarder *player);

/*Skier Collision*/
void skierCollision(NPCskier *skier, SkierCounter *counter);

/*Game ends*/
void gameOver();



#endif