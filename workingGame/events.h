#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"
#include "bool.h"
#include "types.h"


/****ANSYNCHRONOUS EVENTS****/

void moveRequest(Snowboarder *player, char x);
void quit(long sysCall);

/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/
void spawnSkier(NPCskier *skier, int yInit);

void moveSkier(NPCskier *skier);

/*Tree events*/
void spawnTree(Tree *tree, int initialYpos);

void moveTree(Tree *tree);

/*****CONDITION-BASED EVENTS*****/


void resetTree(Tree *tree); /*to be implemented*/
void resetSkier(NPCskier *skier);

/*Collisions*/
bool checkColEdge(Snowboarder *player);
bool checkCollisionObs(Snowboarder *player, Tree *tree);
bool checkCollisionSkier(Snowboarder *player, NPCskier *skier);

void collisionObs(Lives *lives, Snowboarder *player);
void collisionSkier(ScoreCounter *score, SkierCounter *counter, 
                    UINT32 *lastUpdateTime, UINT32 timeCurr);

/*position reset*/
void decreaseLife(Lives *lives);
void resetPos(Snowboarder *player);

/*Skier Collision*/
void scoreUpdates(ScoreCounter *playerScore, UINT32 *lastUpdateTime,
                     UINT32 timeCurr, bool skierHit);

/*Game ends*/
void gameOver();

#endif