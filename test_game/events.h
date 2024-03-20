#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"
#include "bool.h"


/****ANSYNCHRONOUS EVENTS****/

void moveRequest(Snowboarder *player, int newDelta);
void quit(long sysCall);

/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier);

void moveSkier(NPCskier *skier);

/*Tree events*/
void spawnTree(Tree *tree);

void moveTree(Tree *tree);

/*****CONDITION-BASED EVENTS*****/

/*Collisions*/
bool checkColEdge(Snowboarder *player);
bool checkCollisionObs(Snowboarder *player, Tree *tree);
bool checkCollisionSkier(Snowboarder *player, NPCskier *skier);

void collisionObs(Lives *lives, Snowboarder *player);
void collisionSkier(ScoreCounter *score, SkierCounter *counter);

/*position reset*/
void decreaseLife(Lives *lives);
void resetPos(Snowboarder *player);

/*Skier Collision*/
void scoreUpdates(ScoreCounter *playerScore);
void skierHitCountIncrease(SkierCounter *count);

/*Game ends*/
void gameOver();

#endif