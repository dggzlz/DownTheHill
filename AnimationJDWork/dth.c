#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include <osbind.h>
#include <stdio.h>


long getTime();

int main(){

    UINT32 timeThen, timeNow, timeElapsed;
    UINT32 *base = Physbase();
    char key; 
    int i;
    Model model;
    
    timeNow = getTime();
    timeThen = timeNow;

    setModel(&(model));
    
    /*renderModel(&(model), base);*/
    
    timeElapsed = timeNow - timeThen;
    
    key = input();
    while (key != ESC)
    {  
      /*  if (hasInput())
        { */
            if (key == LEFT_ARROW)
            {
                model.snowboarder.posture = 'l';
                moveRequest(&(model.snowboarder), -5);
            }
            else if (key == RIGHT_ARROW)
            {
                model.snowboarder.posture = 'r';
                moveRequest(&(model.snowboarder), 5);
            }
        /*}*/
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

        if (timeElapsed > 1){
            
            for(i = 0; i < 6; i++)
            {
                moveTree(&(model.trees[i]));
            }

            clearScreen(base);
            renderModel(&(model), base);

            /*checkcollisions*/
            if(checkColEdge(&(model.snowboarder)) == true)
            collisionObs(&(model.hearts), &(model.snowboarder));

            timeThen = timeNow;
        }  
    
        key = input();      
    }
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