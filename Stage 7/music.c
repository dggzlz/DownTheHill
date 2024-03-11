/*this code is unfinished*/

#include "psg.h"
#include "music.h"

#define C4 478
#define C5 239
#define C6 120
#define C7 60
#define G6 160
#define F6 90
#define F7 45


int currentNote = 0;
UINT32 noteStartTime = 0;

typedef struct
{
    int pitch;
    UINT32 duration;  
} Note;

Note jumpVanHalen[] = {
    {C4, 420},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {F6, 70},
    {G6, 70},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 140},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {F6, 70},
    {G6, 70},
    {G6, 140},
    {G6, 70},
    {F6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 140},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {F6, 70},
    {G6, 70},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 140},
    {G6, 70},
    {G6, 70},
    {F6, 70},
    {F6, 70},
    {G6, 70},
    {G6, 140},
    {G6, 70},
    {F6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 140},
    {F7, 70},
    {F7, 70},
    {F7, 70},
    {C7, 140},
    {F6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 70},
    {C6, 140}
};

void startJumpMusic()
{
   currentNote = 0;
   noteStartTime = 0;
   setTone(0, jumpVanHalen[currentNote].pitch);
   setVolume(0, 15); 
}

/*used chatgpt for this part*/
void update_music(UINT32 time_elapsed)
{
    static UINT32 accumulatedTime = 0;
    accumulatedTime += time_elapsed;

    if (accumulatedTime >= jumpVanHalen[currentNote].duration)
    {
        accumulatedTime = 0;
        currentNote++;
        if (currentNote >= 53)
        {
            currentNote = 0;
        }
        setTone(0, jumpVanHalen[currentNote].pitch);
    }
}