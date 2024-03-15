#ifndef MODEL_H
#define MODEL_H

/*STRUCTURES*/

typedef struct
{
    int x;
    int y;
    int deltaX;
    char posture;


} Snowboarder;

typedef struct
{
    int x, y;
    int deltaX; 
    int deltaY; 

} NPCskier;

typedef struct
{
    int x,y;
    /*int upwardSpeed; */

} Tree;

typedef struct
{
	int scorePlayer;	/*score of the player*/
	int x, y;	/*coordinates for the score bitmap*/
} ScoreCounter; 


typedef struct
{
    int numLives;
    int x, y;
} Lives;

typedef struct
{
    int hitCounter;
    int scoreCounter;
    int x, y;

} SkierCounter;

typedef struct
{
    Snowboarder player;
    NPCskier skiers[3];
	Tree trees[6];
    Lives lives;
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

