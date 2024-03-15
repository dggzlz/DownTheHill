#ifndef MODEL_H
#define MODEL_H

short numOfTrees = 6;
short numOfSkiers = 3;

/*STRUCTURES*/
typedef struct {
        int minX;
        int maxX;
        int minY;
        int maxY;
} BoundingBox;

typedef struct
{
    unsigned int x;
    unsigned int y;
    int deltaX;
    char posture;
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
    NPCskier skiers[3];
	Tree trees[2];
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

#endif

