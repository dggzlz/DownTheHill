#ifndef MODEL_H
#define MODEL_H

#include RASTER_H

typedef struct
{
    UINT32 bitmap[128];

} bitmap64;

typedef struct
{
    bitmap64 snowBoardPlayer;
    int lives = 3;
    unsigned int x;
    int xDelta;
    const unsigned int y = 200;
    unsigned int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/

} snowboarder;

typedef struct
{
    bitmap64 NPCskier;
    unsigned int x, y;
    
    int sidewaysSpeed; /*might have to be UINT32 unfortunatly*/
    int upwardsSpeed; /*might have to be UINT32 unfortunatly*/

} NPCskier;

typedef struct
{
    bitmap64 tree;
    unsigned int x,y;
    int upwardSpeed; 

} tree;

typedef struct
{
    bitmap16 score[7];
	unsigned int score;	/*score of the player*/
	unsigned int x, y;	/*coordinates for the score bitmap*/
} scoreCounter; 



typedef  struct
{
    bitmap32 heartsHealth;
    int lives;
    unsigned int x, y;

} healthBar;

typedef struct
{
	tree tree;
    healthBar hearts;
    NPCskier skiers[10];
    snowboarder snowboarder;
} Model;

#endif

