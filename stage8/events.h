#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"
#include "bool.h"
#include "types.h"

#define SCREEN_CENTER_X 288 /*since sprites are 64x64, (640/2)-(64/2) is the center*/
#define LEFT_EDGE 0
#define RIGHT_EDGE 640
#define UPPER_EDGE 0
#define BOTTOM_EDGE 400

/****ASYNCHRONOUS EVENTS****/
void moveRequest(Snowboarder *player, char ch);

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

/***Collisions***/
/*Checking if there are collisions*/
bool checkColEdge(Snowboarder *player);
bool checkCollisionObs(Snowboarder *player, Tree *tree);
bool checkCollisionSkier(Snowboarder *player, NPCskier *skier);
void hasSkierColWithTree(NPCskier *skier, Tree *tree);

/***Collision Events***/
void collisionObs(Lives *lives, Snowboarder *player);
void collisionSkier(ScoreCounter *score, SkierCounter *counter, UINT32 timeCurr);

/***Position Reset***/
void decreaseLife(Lives *lives);
void resetPos(Snowboarder *player);

void scoreUpdates(ScoreCounter *playerScore, UINT32 timeCurr, bool skierHit);
bool isPlayerInvulnerable(Snowboarder *player);

/*Game ends*/
bool checkGameOver(Lives *lives);
void gameOver(ScoreCounter *score, SkierCounter *hitCount);

#endif