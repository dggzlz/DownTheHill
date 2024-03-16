#include "input.h"
#include "..\stage4\renderer.h"
#include "..\stage2\types.h"
#include "..\stage2\RASTER.H"
#include "..\stage3\model.h"
#include "..\stage3\events.h"


long getTime();

int main(){

    int keyPressed = input();
    UINT32 timeThen = 0, timeNow, timeElapsed;
    timeNow = getTime();

    Model model;

    timeElapsed = timeNow - timeThen;

    while (keyPressed != ESC)
    {   
        
        if (Cconin() == 0xFFFF){ 
            if (keyPressed == LEFT_ARROW)
                moveSnowboarder(-1);
            else if (keyPressed == RIGHT_ARROW);
                moveSnowboarder(1);
        }


        if (timeElapsed > 0){
            /*PUT SYNCHRONUIS EVENTS I.E TREES AND SKIERS*/
            spawnTree(&(model.trees[0]));
            spawnSkier(&(model.skiers[0]));

            timeThen = timeNow;
        }

        
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