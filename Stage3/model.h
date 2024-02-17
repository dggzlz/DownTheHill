#ifndef MODEL_H
#define MODEL_H

#include "Stage3/model.c"
#include "Stage2/raster.h"
#include "Stage2/raster.c"
#include "BitMap Arrays/BitMapArrays.h"
#include <osbind.h>

/**************BEHAVIOURS FUNCTIONS*******/

/*SNOWBOARDER BEHAVIOURS*/
void moveSnowboarder();

/*SKIER BEHAVIOURS*/
void moveSkier();
void skierSpawn();
void skierDissapears();

/*TREE BEHAVIOURS*/
void moveTree();
void spawnTree();

/*SCORE BEHAVIOURS*/
void scoreUpdates();

/*LIVES COUNTER BEHAVIOURS*/
void updateLives();

/*SKIER HIT BEHAVIOURS*/
void skierHitCountIncrease();

typedef unsigned long UINT32;


/***********STRUCTURES************/
typedef struct
{
    UINT32 bitmap[128];

} Bitmap64;

typedef struct
{
    UINT32 bitmap[32];
} Bitmap32;

typedef struct
{
    Bitmap64 snowBoarder;
    int lives;
    unsigned int x;
    int deltaX;
    const unsigned int y;
    unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

} Snowboarder;

typedef struct
{
    Bitmap64 npcSkier;
    unsigned int x, y;
    
    int deltaX; /*might have to be UINT32 unfortunatly*/
    int deltaY; /*might have to be UINT32 unfortunatly*/

} NPCskier;

typedef struct
{
    Bitmap64 tree;
    unsigned int x,y;
    int upwardSpeed; 

} Tree;

typedef struct
{
    bitmap16 score[7];
	unsigned int score;	/*score of the player*/
	unsigned int x, y;	/*coordinates for the score bitmap*/
} ScoreCounter; 


typedef  struct
{
    Bitmap32 heartsHealth;
    int numLives;
    unsigned int x, y;

} Lives;

typedef struct
{
    Bitmap32 number;
    unsigned int hitCounter;
    unsigned int scoreCounter;

    unsigned int x, y;

} SkierCounter;

typedef struct
{
    Snowboarder snowboarder;
    NPCskier skiers[10];
	Tree tree[10];
    Lives hearts[3];
    SkierCounter skierCounter;
} Model;

#endif

