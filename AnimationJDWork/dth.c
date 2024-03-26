#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include <osbind.h>
#include <stdio.h>
 
 UINT8 newScreen[32256]; 


long getTime();

UINT8* findEvenAddress(UINT8 newScreen[]);

int main(){

    

    UINT32 timeThen, timeNow, timeElapsed;
      UINT8* base2 = findEvenAddress(newScreen);
    UINT8 *frameBuff2 = setScreen(-1, base2, -1); /*need to use vertical sync*/
    UINT32 *base = Physbase();
    char key; 
    int i;
    Model model;
    bool treeCol = false, skierCol = false, quit = false;
    
    timeNow = getTime();
    timeThen = timeNow;
   

    setModel(&(model));
    
    /*renderModel(&(model), base);*/

   



    printf("newscreen is at %p \n", base2);
    printf("FB is at %p \n", frameBuff2);
    
    timeElapsed = timeNow - timeThen;
    
    /*
    while (!quit)
    {  
        if (hasInput())
        {
            key = input();
            if (key == ESC)
            {
                quit = true;
            } 
            else if (key == LEFT_ARROW)
            {
                model.snowboarder.posture = 'l';
                moveRequest(&(model.snowboarder), -5);
            }
            else if (key == RIGHT_ARROW)
            {
                model.snowboarder.posture = 'r';
                moveRequest(&(model.snowboarder), 5);
            }
        }


        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 3){
            
            for(i = 0; i < numOfTrees; i++)
            {
                moveTree(&(model.trees[i]));

                if (checkCollisionObs(&(model.snowboarder), &(model.trees[i])))
                    treeCol = true;
            }

            for(i = 0; i < numOfSkiers; i++)
            {
                moveSkier(&(model.skiers[i]));

                if (checkCollisionSkier(&(model.snowboarder), &(model.skiers[i])))
                    skierCol = true;
            }

            if (checkColEdge(&(model.snowboarder)) || treeCol)
                collisionObs(&(model.hearts), &(model.snowboarder));
            
            if (skierCol)
                collisionSkier(&(model.score), &(model.skierCounter));

            clearScreen(base);
            renderModel(&(model), base);

           
            timeThen = timeNow;
            treeCol = false;
            skierCol = false;
        }  
      
    }*/
    return 0;
}

long getTime()
{
    long oldssp; 
    long timeNow;
    long *timer = (long *) 0x462;

    oldssp = Super(0);
    timeNow = *timer;
    Super(oldssp);

    return timeNow;    
}


UINT8* findEvenAddress(UINT8 array[])
{
    int i;
    UINT8* base2;
    for(i = 0; i < 32256; i++)
    {
        printf("array is %p\n", &array[i]);
        if( ( (UINT32) &array[i] ) % 256 == 0)
        {
        base2 = &array[i];
        return base2;
        }
    }
    return 0;
}