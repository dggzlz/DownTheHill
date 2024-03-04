#include "input.h"
#include ".\stage4\bitmaps.h"
#include "types.h"
#include "raster.h"
#include "model.h"


long getTime();

int main(){

    int keyPressed = input();
    UINT32 timeThen = 0, timeNow, timeElapsed;
    timeNow = getTime();

    Model model = {
        snowboarderSet(),
        .skiers = {
            newSkier(),
            newSkier(),
            newSkier(),
            newSkier()
        },
        .trees = {
            createTree(),
            createTree()
        },
        .hearts = {
            createLife(),
            createLife(),
            createLife()
        },
        .skierCounter = {0, 0, 0, 0}
    };

    timeElapsed = timeNow - timeThen;

    while (keyPressed != 3)
    {   
        
        if (Cconin() == 0xFFFF){ 
            if (keyPressed == 1)
                moveSnowboarder(-1);
            else if (keyPressed == 2);
                moveSnowboarder(1);
        }

        if (timeElapsed > 0)
            /*PUT SYNCHRONUIS EVENTS I.E TREES AND SKIERS*/
            timeThen = timeNow;

        keyPressed = input();
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