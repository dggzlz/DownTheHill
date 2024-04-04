#ifndef MODEL_H
#define MODEL_H

#include "bool.h"

#define numOfTrees 6
#define numOfSkiers 3

/*STRUCTURES*/
typedef struct {
        int minX;
        int maxX;
        int minY;
        int maxY;
} BoundingBox;

typedef struct
{
    int x;
    int y;
    int vel;
    char posture;
    unsigned long invulnerableTimer;
    int counter; 
} Snowboarder;

typedef struct
{
    int x, y;
    int deltaY; /*might have to be UINT32 unfortunatly*/
    int pos;
    unsigned long timer;
    bool toDraw;
} NPCskier;

typedef struct
{
    int x,y;
    int upwardSpeed; 
} Tree;

typedef struct
{
	int scorePlayer;	/*score of the player*/
	int x, y;	/*coordinates for the score bitmap*/
    int counter;
} ScoreCounter; 

typedef struct
{
    int numLives;
    int x, y;
    bool gameOver;
} Lives;

typedef struct
{
    int hitCounter;
    int x, y;
} SkierCounter;

typedef struct
{
    Snowboarder snowboarder;
    NPCskier skiers[numOfSkiers];
	Tree trees[numOfTrees];
    ScoreCounter score;
    Lives hearts;
    SkierCounter skierCounter;
} Model;


/**************BEHAVIOURS FUNCTIONS*******/

/*SNOWBOARDER BEHAVIOURS*/
void snowboarderSet(Snowboarder *player);

/*SCORE BEHAVIOURS*/
void newScore(ScoreCounter *score);

/*LIVES COUNTER BEHAVIOURS*/
void newLife(Lives *life);

/*SKIER HIT BEHAVIOURS*/
void newCounter(SkierCounter *counter);

void setModel(Model *model);

#endif

