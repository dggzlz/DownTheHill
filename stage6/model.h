/* File: model.h
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose:  
 *  This file is part of stage 3 of the project, being the one that contains 
 *  the structures of the videogame.
 *  
 *  - x and y in all structures represents coordinates for the objects 
 */

#ifndef MODEL_H
#define MODEL_H

#include "bool.h"
#include "types.h"

#define numOfTrees 6
#define numOfSkiers 3

#define POSTURE_R 'r'
#define POSTURE_L 'l'

/*STRUCTURES*/
/*This Struct is used to check collision boxes*/
typedef struct 
{
    int minX;
    int maxX;
    int minY;
    int maxY;
} BoundingBox;

/*vel: speed that the player move on the x-axis
  posture: posture that the player moves, l for left, and r for right 
  invulnerableTimer: timer to set how long the playe rcan be invulnerable when 
    it hits and obstacle*/
typedef struct
{
    int x, y; 
    int vel;
    char posture;
    UINT32 invulnerableTimer;
} Snowboarder;

/*deltaY: speed that skiers goes at
  pos: posture that the skier goes at, 0 for left, and 1 for right
  timer: inner timer for the skier
  toDraw: states whether the skier should be drawn or not*/
typedef struct
{
    int x, y;
    int deltaY; 
    int pos;
    UINT32 timer;
    bool toDraw;
} NPCskier;

typedef struct
{
    int x,y;
    int upwardSpeed; /*speed that trees goes at*/
} Tree;

typedef struct
{
	int x, y;	     
	int scorePlayer; /*score of the player*/
    UINT32 timer; /*inner timer for the score*/
} ScoreCounter; 

/*numLives: amount of lives the player has.
  gameOver: boolean that states if the player lost or not*/
typedef struct
{
    int x, y;
    int numLives;
    bool gameOver;
} Lives;

/*hitCounter: amount of skier hit by the player*/
typedef struct
{
    int x, y;
    int hitCounter;
} SkierCounter;

/*this structure contains the model of the game.*/
typedef struct
{
    Snowboarder snowboarder;
    NPCskier skiers[numOfSkiers];
	Tree trees[numOfTrees];
    ScoreCounter score;
    Lives hearts;
    SkierCounter skierCounter;
} Model;

/********BEHAVIOURS FUNCTIONS*******/

/*SNOWBOARDER BEHAVIOURS*/
void snowboarderSet(Snowboarder *player);

/*SCORE BEHAVIOURS*/
void newScore(ScoreCounter *score);

/*LIVES COUNTER BEHAVIOURS*/
void newLife(Lives *life);

/*SKIER HIT BEHAVIOURS*/
void newCounter(SkierCounter *counter);

/*SETTING OF MODEL*/
void setModel(Model *model);

#endif

