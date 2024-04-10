#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <osbind.h>


#define true 1
#define false 0

typedef unsigned int bool;

long getTime();
bool hasInput();

int main() 
{   
    UINT32 timeThen = 0, timeNow = 0, timeElapsed = 0;
    printf("testing music\n");
    
    timeNow = getTime();
    timeThen = timeNow;
    
    startMusic();

    timeElapsed = timeNow - timeThen;
    while (!hasInput())
    {     
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        
        if (timeElapsed > 1)
        {   
            updateMusic(timeElapsed);
            timeThen = timeNow;
        }  
    }

    stopSound();

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

bool hasInput()
{
    bool hasInput = false;

    if (Cconis())
        hasInput = true;

    return hasInput;
}
