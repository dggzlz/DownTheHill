#include "model.h"
#include "events.h"
#include "types.h"

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

void syncEdge(Model *model)
{
    if (checkColEdge(&model->snowboarder))
        collisionObs(&model->hearts, &model->snowboarder);
}

