#ifndef MODEL_H
#define MODEL_H

#include "raster.h"
#include "bitmap.h"


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
    Bitmap64 snowboardPlayer;
    int lives = 3;
    unsigned int x;
    int deltaX;
    const unsigned int y = 200;
    unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

} Snowboarder;

typedef struct
{
    Bitmap64 npcSkier = ;
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
    Bitmap16 score[7];
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
    NPCskier skiers[4];
	Tree tree[8];
    Lives hearts[3];
    SkierCounter skierCounter;

} Model;


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

#endif

