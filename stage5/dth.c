#include "input.h"
#include "renderer.h"
#include "types.h"
#include "RASTER.H"
#include "model.h"
#include "events.h"
#include <osbind.h>


long getTime();

int main(){

    UINT32 timeThen = 0, timeNow, timeElapsed;
    UINT32 *base = Physbase();
    char key = input();
    int i;
    Model model;
    
    timeNow = getTime();

    setModel(&(model));
    
    renderModel(&(model), base);
    
    timeElapsed = timeNow - timeThen;

    while (key != ESC)
    {     
        if (hasInput()){ 
            if (input() == LEFT_ARROW)
                moveRequest(&(model.snowboarder), -5);
            else if (input() == RIGHT_ARROW);
                moveRequest(&(model.snowboarder), 5);
        }
        
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;

  

        if (timeElapsed > 1){
            
            for(i = 0; i < 6; i++)
            {
                moveTree(&(model.trees[i]));
            }

            clearScreen(base);
            renderModel(&(model), base);

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