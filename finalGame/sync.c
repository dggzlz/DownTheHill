/* File: sync.c
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose:  
 *  This file contains all the functions that Call for synchronous events.
 */
#include "model.h"
#include "events.h"
#include "types.h"
#include "bool.h"

/*
Name:
    syncTree
Purpose:
    This function is in charge of running the synchronous events 
    of the tree objects. the events are move the tree, and check their collision
Inputs:
    (Model *) model: a pointer pointing to the model of the game.
Outputs: 
    None
Details:
    it uses a for loop to go through the array of trees to move and check 
    collision.    
*/
void syncTree(Model *model)
{
    int i;

    for(i = 0; i < numOfTrees; i++)
    {
        moveTree(&model->trees[i]);

        if(checkCollisionObs(&model->snowboarder, &model->trees[i]))
            collisionObs(&model->hearts, &model->snowboarder); 
    }
}

/*
Name:
    syncSkier
Purpose:
    This function is in charge of running the synchronous events 
    of the skier objects. The events are "move the skie"r, and "check their collision"
Inputs:
    (Model *) model: a pointer pointing to the model of the game.
Outputs: 
    None
Details:
    it uses a for loop to go through the array of skiers to move and 
    check collision.        
*/
void syncSkier(Model *model, UINT32 timeNow)
{
    int i;
    for(i = 0; i < numOfSkiers; i++)
    {
        moveSkier(&model->skiers[i]);

        if (checkCollisionSkier(&model->snowboarder, &model->skiers[i]))  
            collisionSkier(&model->score, &model->skierCounter, timeNow);
    }
}

/*
Name:
    syncEvents
Purpose:
    This function do synchronous events.
Inputs:
    (Model*) model: the model of the videogame
    (UINT32) timeNow: the current time that the clock has ticked.
Outputs: 
    None.
Details:
    This function also call for syncTree and syncSkier to do the synchronous events
    for both the skiers and trees. it also check for the collision of the 
    snowboarder in respect with the edges. finally, it updates the score base on
    time and if there was a skier hit.        
*/
void syncEvents(Model *model, UINT32 timeNow)
{
    syncTree(model);    
    syncSkier(model, timeNow);

    if (checkColEdge(&model->snowboarder))
        collisionObs(&model->hearts, &model->snowboarder);

    scoreUpdates(&model->score, timeNow, false);
}
