#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"

#define KEY_LEFT 0x004B00000 
#define KEY_RIGHT 0x004D0000
#define ESC 0x0001001B

/****ANSYNCHRONOUS EVENTS****/

void moveRequest(long sysCall, Snowboarder *player);
void quit(long sysCall);

/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier);

void moveSkier(NPCskier *skier);

/*Tree events*/
void spawnTree(Tree *tree);

void moveTree(Tree *tree);

/*****CONDITION-BASED EVENTS*****/
void checkCollision(Snowboarder *player, NPCskier *skier, Tree *tree);
/*Collisions*/
void collision(Lives *lives, Snowboarder *player);

/*position reset*/

void decreaseLife(Lives *lives);
void resetPos(Snowboarder *player);
/*Skier Collision*/
void scoreUpdates(ScoreCounter *playerScore);
void skierHitCountIncrease(SkierCounter *count);
/*Game ends*/
void gameOver();

#endif