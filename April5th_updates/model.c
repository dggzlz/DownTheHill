#include "model.h"
#include "events.h"

#define PLAYER_Y 100

#define SCORE_X 480
#define SCORE_Y 4

#define LIVES_X 620
#define LIVES_Y 24

#define COUNTER_X 40
#define COUNTER_Y 4


/***INITIALIZE SNOWBOARDER***/

/*
Name:
    snowboarderSet  
Purpose:
    The purpose of this function is to initialize the attributes of the 
    snowboarder object.
Inputs: 
    Snowboarder *player
       A pointer to the Snowboarder object that represents the player
Outputs: 
    None     
Details and Calculations:
    This function uses pointers to access the attributes 
    of the Snowboarder object and sets each one.         
*/
void snowboarderSet(Snowboarder *player)
{
    player->x = SCREEN_CENTER_X;
    player->y = PLAYER_Y; 
    player->vel = 32;
    player->posture = POSTURE_R;
    player->invulnerableTimer = 0;
    player->counter = 0;
}

/***INITIALIZE SCORE****/
/*
Name:
    newScore  
Purpose:
    The purpose of this function is to initialize the attributes of the 
    ScoreCounter object.    
Inputs: 
    ScoreCounter *score
        A pointer to the ScoreCounter object that represent the 
        score of the player.
Outputs: 
    None        
Details and Calculations:
     This function uses pointers to access the attributes 
    of the ScoreCounter object and sets each one.          
*/
void newScore(ScoreCounter *score)
{
    score->scorePlayer = 0;
    score->x = SCORE_X;
    score->y = SCORE_Y;
    score->counter = 0;
}

/***INITIALIZE LIVES***/
/*
Name:
    newLife  
Purpose:
    The purpose of this function is to initialize the attributes of the 
    Lives object.     
Inputs:
    Lives *lives
        A pointer to the ScoreCounter object that represent the 
        lives of the player.
Outputs: 
    None    
Details and Calculations:
    This function uses pointers to access the attributes 
    of the Lives object and sets each one.       
*/
void newLife(Lives *life)
{
    life->numLives = 3;
    life->x = LIVES_X;
    life->y = LIVES_Y;
    life->gameOver = false;
}

/***INITIALIZE SKIER HIT COUNTER ***/

/*
Name:
    newCounter   
Purpose:
    The purpose of this function is to initialize the attributes of the 
    SkierCounter object.     
Inputs:
    SkierCounter *counter
        A pointer to the SkierCounter object that represent the 
        number of skiers the player has hit.
Outputs: 
    None
        
Details and Calculations:
    This function uses pointers to access the attributes 
    of the SkierCounter object and sets each one.    
*/
void newCounter(SkierCounter *counter)
{
    counter->hitCounter = 0;
    counter->x = COUNTER_X;
    counter->y = COUNTER_Y;
}

/***SET INITIAL MODEL***/

/*
Name:
    setModel   
Purpose:
    The purpose of this function is to initialize all the objects of
    the game model.    
Inputs:
    Model *model
        A pointer to the Model object 
Outputs: 
    None
Details and Calculations:
    yInitPositions are the initial row locations of the trees and skiers.
    These locations make use of the virtual screen to generate a spacing 
    between the trees that will be maintained throughout the game. Each 
    attribute of the model which are objects are passed into their respective
    initialization functions.   
*/
void setModel(Model *model)
{
    int yInitPositions[6] = {400, 400, 544, 544, 688, 688}; /*making use of virtual screen*/
    int i,j;
    snowboarderSet(&(model->snowboarder));
    newScore(&(model->score));
    newLife(&(model->hearts));
    newCounter(&(model->skierCounter));

    for(i = 0; i < numOfTrees; i++)
    {
        spawnTree(&model->trees[i], yInitPositions[i]);
        /*j = &model->trees[i]->x;
        j = j >> 6;
        &model->trees[i][j];*/
    }
    
    for(i = 0; i < numOfSkiers; i++)
    {
        spawnSkier(&(model->skiers[i]), yInitPositions[i]);
    }

}



