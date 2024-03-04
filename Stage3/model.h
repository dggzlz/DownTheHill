#ifndef MODEL_H
#define MODEL_H


/*STRUCTURES*/

typedef struct
{
    unsigned int x;
    unsigned int y;
    int deltaX;
    /*unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

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
	unsigned int scorePlayer;	/*score of the player*/
	unsigned int x, y;	/*coordinates for the score bitmap*/
} ScoreCounter; 


typedef struct
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
    Snowboarder snowboarder;
    NPCskier skiers[4];
	Tree trees[2];
    Lives hearts;
    SkierCounter skierCounter;

} Model;


/**************BEHAVIOURS FUNCTIONS*******/

/*SNOWBOARDER BEHAVIOURS*/
Snowboarder snowboarderSet();

/*SKIER BEHAVIOURS*/
NPCskier newSkier();

/*TREE BEHAVIOURS*/
Tree newTree();

/*SCORE BEHAVIOURS*/
ScoreCounter newScore();

/*LIVES COUNTER BEHAVIOURS*/
Lives newLife();
void updatesLives(Lives *lives);

/*SKIER HIT BEHAVIOURS*/
SkierCounter newCounter();

void skierHitCountIncrease();

#endif

