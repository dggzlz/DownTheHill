#ifndef MODEL_H
#define MODEL_H

#include "model.c"


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
    int lives;
    unsigned int x;
    int deltaX;
    const unsigned int y;
    unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

} Snowboarder;

typedef struct
{
    unsigned int x, y;
    
    int deltaX; /*might have to be UINT32 unfortunatly*/
    int deltaY; /*might have to be UINT32 unfortunatly*/

} NPCskier;

typedef struct
{
    unsigned int x,y;
    int upwardSpeed; 

} Tree;

typedef struct
{
	unsigned int score;	/*score of the player*/
	unsigned int x, y;	/*coordinates for the score bitmap*/
} ScoreCounter; 


typedef  struct
{
    int numLives;
    unsigned int x, y;

} Lives;

typedef struct
{
    unsigned int hitCounter;
    unsigned int scoreCounter;

    unsigned int x, y;

} SkierCounter;

typedef struct
{
    NPCskier skiers[10];
	Tree tree[10];
    Lives hearts[3];
    SkierCounter skierCounter;
} Model;

#endif

