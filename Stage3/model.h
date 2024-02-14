#ifndef MODEL_H
#define MODEL_H

#include RASTER_H

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
void liveUpdates();

/*SKIER HIT BEHAVIOURS*/
void countIncrease();

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
    bitmap64 snowboardPlayer;
    int lives = 3;
    unsigned int x;
    int deltaX;
    const unsigned int y = 200;
    unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

} Snowboarder;

typedef struct
{
    bitmap64 npcSkier;
    unsigned int x, y;
    
    int deltaX; /*might have to be UINT32 unfortunatly*/
    int deltaY; /*might have to be UINT32 unfortunatly*/

} NPCskier;

typedef struct
{
    bitmap64 tree;
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
    bitmap32 heartsHealth;
    int lives;
    unsigned int x, y;

} Lives;

typedef struct
{
    bitmap32 number;
    unsigned int counter;
    unsigned int x, y;

} SkierCounter;

typedef struct
{
    Snowboarder snowboarder;
    NPCskier skiers[10];
	Tree tree;
    Lives hearts[3];
    SkierCounter skierCounter;
} Model;

#endif

