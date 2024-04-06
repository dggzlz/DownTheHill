#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <osbind.h>

/*TEMPO FOR JUMP*/

#define JUMP 'j'
#define REPTILIA 'r'


#define reptiliaLen (int)(sizeof(gameSong) / sizeof(gameSong[0]))
#define jumpLen (int)(sizeof(menuNote1) / sizeof(menuNote1[0]))


int curNote = 0;
static UINT32 duration = 0;

/*Song based on Jump, from the album 1984 by Van Halen*/
Note menuNote1[] = 
{   
    /*1st bar*/
    {rest, 28}, {D >> sixth_oct, 14}, {rest, 28}, {E >> sixth_oct, 14}, {rest, 28},

    /*2nd bar*/
    {C >> sixth_oct, 14}, {rest, 28}, {C >> sixth_oct, 14}, 
    {rest, 14}, {D >> sixth_oct, 14}, {rest, 14}, {D >> sixth_oct, 14},

    /*3rd bar*/
    {D >> sixth_oct, 21}, {rest, 7}, {E >> sixth_oct, 14}, {rest, 28}, 
    {C >> sixth_oct, 14}, {rest, 14}, {A >> fifth_oct, 14},

    /*4th bar*/
    {A >> fifth_oct, 14}, {G >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 70},

    /*5th bar*/
    {rest, 28}, {D >> sixth_oct, 14}, {rest, 28}, {E >> sixth_oct, 14}, {rest, 28},

    /*6th bar*/
    {C >> sixth_oct, 14}, {rest, 28}, {C >> sixth_oct, 14}, 
    {rest, 14}, {D >> sixth_oct, 14}, {rest, 14}, {D >> sixth_oct, 14},

    /*7th bar*/
    {D >> sixth_oct, 21}, {rest, 7}, {E >> sixth_oct, 14}, {rest, 28}, 
    {C >> sixth_oct, 14}, {rest, 14}, {A >> fifth_oct, 14},

    /*8th bar*/
    {A >> fifth_oct, 14}, {G >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 70},

};

Note menuNote2[] = 
{   
    /*1st bar*/
    {rest, 28}, {B >> fifth_oct, 14}, {rest, 28}, {C >> sixth_oct, 14}, {rest, 28},

    /*2nd bar*/
    {A >> fifth_oct, 14}, {rest, 28}, {A >> fifth_oct, 14}, 
    {rest, 14}, {B >> fifth_oct, 14}, {rest, 14}, {B >> fifth_oct, 14},

    /*3rd bar*/
    {B >> fifth_oct, 21}, {rest, 7}, {C >> sixth_oct, 14}, {rest, 28}, 
    {A >> fifth_oct, 14}, {rest, 14}, {F >> fifth_oct, 14},

    /*4th bar*/
    {F >> fifth_oct, 14}, {G >> fifth_oct, 14}, {rest, 14}, {D >> fifth_oct, 70},

    /*5th bar*/
    {rest, 28}, {B >> fifth_oct, 14}, {rest, 28}, {C >> sixth_oct, 14}, {rest, 28},

    /*6th bar*/
    {A >> fifth_oct, 14}, {rest, 28}, {A >> fifth_oct, 14}, 
    {rest, 14}, {B >> fifth_oct, 14}, {rest, 14}, {B >> fifth_oct, 14},

    /*7th bar*/
    {B >> fifth_oct, 21}, {rest, 7}, {C >> sixth_oct, 14}, {rest, 28}, 
    {A >> fifth_oct, 14}, {rest, 14}, {F >> fifth_oct, 14},

    /*8th bar*/
    {F >> fifth_oct, 14}, {G >> fifth_oct, 14}, {rest, 14}, {D >> fifth_oct, 70},

};

Note menuNote3[] = 
{   
    /*1st bar*/
    {rest, 28}, {G >> fifth_oct, 14}, {rest, 28}, {G >> fifth_oct, 14}, {rest, 28},

    /*2nd bar*/
    {F >> fifth_oct, 14}, {rest, 28}, {F >> fifth_oct, 14}, 
    {rest, 14}, {G >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 14},

    /*3rd bar*/
    {G >> fifth_oct, 21}, {rest, 7}, {G >> fifth_oct, 14}, {rest, 28}, 
    {F >> fifth_oct, 14}, {rest, 14}, {C >> fifth_oct, 14},

    /*4th bar*/
    {C >> fifth_oct, 14}, {C >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 70},

    /*5th bar*/
    {rest, 28}, {G >> fifth_oct, 14}, {rest, 28}, {G >> fifth_oct, 14}, {rest, 28},

    /*6th bar*/
    {F >> fifth_oct, 14}, {rest, 28}, {F >> fifth_oct, 14}, 
    {rest, 14}, {G >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 14},

    /*7th bar*/
    {G >> fifth_oct, 21}, {rest, 7}, {G >> fifth_oct, 14}, {rest, 28}, 
    {F >> fifth_oct, 14}, {rest, 14}, {C >> fifth_oct, 14},

    /*8th bar*/
    {C >> fifth_oct, 14},{C >> fifth_oct, 14}, {rest, 14}, {G >> fifth_oct, 70},

};


/*Song based on Reptilia, from the album Room on Fire by The Strokes*/
Note gameSong[] = 
{
    /*
    - Main Riff from 1st bar to 16th bar with guitar
    - Change of riff from mid 16th bar to 24th bar with clean guitar ***change on envelope***
    - change of riff from mid 24th bar to 33th bar with guitar ***change on envelope***
    - Solo Guitar from mid 33th bar to 48th with clean guitar ***change on envelope***
    - Outro from 49th bar to 56th bar
    */

    /*1st bar*/
    {rest, 55},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*2th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {A_sharp >> fourth_oct, 13},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*3th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*4th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*5th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*6th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {A_sharp >> fourth_oct, 13},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*7th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*8th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*9th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*10th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {A_sharp >> fourth_oct, 13},
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, {D >> fifth_oct, 13},
    {B >> fourth_oct, 6},

    /*11th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*12th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13}, {rest, 13},
    {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 6},

    /*13th bar*/
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13}, 
    {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, {rest, 13}, 
    {D >> fifth_oct, 13}, {B >> fourth_oct, 6},

    /*14th bar*/
    {B >> fourth_oct, 7}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13},
    {A_sharp >> fourth_oct, 13}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},
    {rest, 13}, {D >> fifth_oct, 13}, {B >> fourth_oct, 6},

    /*15th bar*/ 
    {B >> fourth_oct, 6}, {A_sharp >> fourth_oct, 13}, {A >> fourth_oct, 13},
    {rest, 13}, {G_sharp >> fourth_oct, 13}, {rest, 1}, {G_sharp >> fourth_oct, 13},
    {rest, 13}, {G_sharp >> fourth_oct, 13}, {B >> fourth_oct, 7},

    /*16th */
    {B >> fourth_oct, 7}, {rest, 13}, {D >> fifth_oct, 13}, {rest, 13},
    {D >> sixth_oct, 13}, {rest, 1}, {D >> sixth_oct, 13}, {rest, 13},
    {D >> sixth_oct, 13}, {A >> fifth_oct, 6},  
    
    /*17th*/
    {A >> fifth_oct, 7}, {rest, 1}, {A >> fifth_oct, 13},
    {rest, 13}, {A >> fifth_oct, 13}, {B >> fifth_oct, 13}, {rest, 1},
    {B >> fifth_oct, 13}, {rest, 13}, {B >> fifth_oct, 13}, {C_sharp >> sixth_oct, 6},    

    /*18th*/
    {C_sharp >> sixth_oct, 7}, {rest, 1}, {C_sharp >> sixth_oct, 13}, {rest, 13},
    {C_sharp >> sixth_oct, 13}, {B >> fifth_oct, 13}, {rest, 1}, {B >> fifth_oct, 13},
    {rest, 13}, {B >> fifth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*19th bar*/
    {C_sharp >> sixth_oct, 6}, {rest, 1}, {C_sharp >> sixth_oct, 13},{rest, 13}, 
    {C_sharp >> sixth_oct, 13}, {A >> fifth_oct, 13}, {rest, 1}, {A >> fifth_oct, 13},
    {rest, 13}, {A >> fifth_oct, 13}, {D >> sixth_oct, 6},

    /*20th bar*/
    {D >> sixth_oct, 7}, {rest, 1}, {D >> sixth_oct, 13}, {rest, 13}, {rest, 13},
    {D >> sixth_oct, 13}, {rest, 1}, {D >> sixth_oct, 13}, {rest, 13}, 
    {D >> sixth_oct, 13}, {A >> fifth_oct, 7},

    /*21th bar*/
    {A >> fifth_oct, 6}, {rest, 1}, {A >> fifth_oct, 13}, {rest, 13}, 
    {A >> fifth_oct, 13}, {B >> fifth_oct, 13}, {rest, 1}, {B >> fifth_oct, 13},
    {rest, 13}, {B >> fifth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*22th bar*/
    {C_sharp >> sixth_oct, 6}, {rest, 1} ,{C_sharp >> sixth_oct, 13}, {rest, 13}, 
    {C_sharp >> sixth_oct, 13},{B >> fifth_oct, 13}, {rest, 1}, 
    {B >> fifth_oct, 13}, {rest, 13}, {B >> fifth_oct, 13}, {C_sharp >> sixth_oct, 6},

    /*23th bar*/ 
    {C_sharp >> sixth_oct, 6}, {rest, 1} ,{C_sharp >> sixth_oct, 13}, {rest, 13}, 
    {C_sharp >> sixth_oct, 13}, {A >> fifth_oct, 13}, {rest, 1}, 
    {A >> fifth_oct, 13}, {rest, 13}, {A >> fifth_oct, 13}, {D >> sixth_oct, 6},

    /*24th bar*/
    {D >> sixth_oct, 7}, {rest, 1}, {D >> sixth_oct, 13}, {rest, 13}, {rest, 13},
    {B >> fifth_oct, 13}, {F_sharp >> fifth_oct, 13}, {A >> fifth_oct, 13},
    {D >> sixth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*25th bar*/
    {C_sharp >> sixth_oct, 6}, {F_sharp >> fifth_oct, 13}, {A >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {rest, 1}, {B >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {D >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 7},


    /*26th bar*/
    {C_sharp >> sixth_oct, 6}, {A >> fifth_oct, 13},  {E >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {B >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {D >> sixth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*27th bar*/
    {C_sharp >> sixth_oct, 6}, {A >> fifth_oct, 13}, {E >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {B >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {D >> sixth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*28th bar*/
    {C_sharp >> sixth_oct, 6}, {A >> fifth_oct, 13}, {E >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {F_sharp >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {F_sharp >> fifth_oct, 13}, {C_sharp >> sixth_oct, 13}, {D >> sixth_oct, 7},

    /*29th bar*/
    {D >> sixth_oct, 6}, {B >> fifth_oct, 13}, {F_sharp >> fifth_oct, 13}, 
    {C_sharp >> sixth_oct, 13}, {B >> fifth_oct, 13}, {F_sharp >> fifth_oct, 13},
    {A >> fifth_oct, 13}, {D >> sixth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*30th bar*/ 
    {C_sharp >> sixth_oct, 6}, {F_sharp >> fifth_oct, 13}, {A >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {rest, 1}, {B >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {D >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 7},

    /*31th bar*/
    {C_sharp >> sixth_oct, 6}, {A >> fifth_oct, 13}, {E >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {B >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {B >> fifth_oct, 13}, {D >> sixth_oct, 13}, {C_sharp >> sixth_oct, 7},

    /*32th bar*/
    {C_sharp >> sixth_oct, 6}, {A >> fifth_oct, 13}, {E >> sixth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {F_sharp >> fifth_oct, 13}, {G >> fifth_oct, 13},
    {F_sharp >> fifth_oct, 13}, {C_sharp >> sixth_oct, 13}, {D >> sixth_oct, 7},

    /*33th bar*/
    {D >> sixth_oct, 7}, {B >> fifth_oct, 13}, {F_sharp >> fifth_oct, 13},
    {C_sharp >> sixth_oct, 13}, {G_sharp >> fifth_oct, 13}, {rest, 6}, 
    {F_sharp >> fifth_oct, 13},{rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*34th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 6},
    {D >> fifth_oct, 13}, {E >> fifth_oct, 13}, {rest, 6}, {D >> fifth_oct, 13},
    {rest, 6}, {C_sharp >> fifth_oct, 13}, {D >> fifth_oct, 7},

    /*35th bar*/
    {D >> fifth_oct, 7}, {rest, 7}, {C_sharp >> fifth_oct, 13}, {rest, 6},
    {F_sharp >> fifth_oct, 13}, {G_sharp >> fifth_oct, 13}, {rest, 6}, 
    {F_sharp >> fifth_oct, 13}, {rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*36th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 6},
    {D >> fifth_oct, 13}, {E >> fifth_oct, 13}, {rest, 6}, {D >> fifth_oct, 13},
    {rest, 6}, {C_sharp >> fifth_oct, 13}, {D >> fifth_oct, 7},

    /*37th bar*/
    {D >> fifth_oct, 7}, {rest, 7}, {C_sharp >> fifth_oct, 13}, {rest, 6},
    {B >> fourth_oct, 13}, {G_sharp >> fifth_oct, 13}, {rest, 6}, 
    {F_sharp >> fifth_oct, 13}, {rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*38th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 6},
    {D >> fifth_oct, 13}, {E >> fifth_oct, 13}, {rest, 6}, {D >> fifth_oct, 13},
    {rest, 6}, {C_sharp >> fifth_oct, 13}, {D >> fifth_oct, 7},

    /*39th bar*/
    {D >> fifth_oct, 7}, {rest, 7}, {C_sharp >> fifth_oct, 13}, {rest, 6},
    {F_sharp >> fifth_oct, 13}, {G_sharp >> fifth_oct, 13}, {rest, 6}, 
    {F_sharp >> fifth_oct, 13}, {rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*40th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 6},
    {D >> fifth_oct, 13}, {E >> fifth_oct, 13}, {rest, 6}, {D >> fifth_oct, 13},
    {rest, 6}, {C_sharp >> fifth_oct, 13}, {B >> fourth_oct, 7},

    /*41th bar*/
    {B >> fourth_oct, 33}, {B >> fifth_oct, 26}, {rest, 1}, {B >> fifth_oct, 6},
    {rest, 6}, {A >> fifth_oct, 7}, {G_sharp >> fifth_oct, 6}, {F_sharp >> fifth_oct, 7},
    {E >> fifth_oct, 6}, {F_sharp >> fifth_oct, 6},

    /*42th bar*/
    {rest, 7}, {D >> fifth_oct, 13}, {rest, 13}, {D >> sixth_oct, 19}, {rest, 7},
    {C_sharp >> sixth_oct, 13}, {A >> fifth_oct, 7}, {G_sharp >> fifth_oct, 6}, 
    {F_sharp >> fifth_oct, 7}, {E >> fifth_oct, 6}, {F_sharp >> fifth_oct, 6},

    /*43th bar*/
    {rest, 7}, {D >> fifth_oct, 13}, {rest, 19}, {F_sharp >> sixth_oct, 19}, 
    {E >> sixth_oct, 7}, {rest, 6}, {D >> sixth_oct, 7}, {C_sharp >> sixth_oct, 7}, 
    {B >> fifth_oct, 6}, {A >> fifth_oct, 7}, {B >> fifth_oct, 6}, 

    /*44th bar*/
    {rest, 7}, {G_sharp >> fifth_oct, 13}, {rest, 6}, {E >> sixth_oct, 7},
    {F >> sixth_oct, 7}, {F_sharp >> sixth_oct, 19}, {E >> sixth_oct, 7}, 
    {rest, 6}, {D >> sixth_oct, 7}, {C_sharp >> sixth_oct, 7}, 
    {B >> fifth_oct, 6}, {rest, 12},

    /*45th bar*/ 
    {rest, 7}, {A >> fifth_oct, 26}, {rest, 13}, {G_sharp >> fifth_oct, 13}, 
    {rest, 6}, {F_sharp >> fifth_oct, 13}, {rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*46th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 6},
    {D >> fifth_oct, 13}, {E >> fifth_oct, 13}, {rest, 6}, {D >> fifth_oct, 13},
    {rest, 6}, {C_sharp >> fifth_oct, 13}, {D >> fifth_oct, 7},

    /*47th bar*/
    {D >> fifth_oct, 7}, {rest, 7}, {C_sharp >> fifth_oct, 13}, {rest, 6},
    {F_sharp >> fifth_oct, 13}, {G_sharp >> fifth_oct, 13}, {rest, 6}, 
    {F_sharp >> fifth_oct, 13}, {rest, 6}, {E >> fifth_oct, 13}, 
    {F_sharp >> fifth_oct, 7},

    /*48th bar*/
    {F_sharp >> fifth_oct, 7}, {rest, 7}, {E >> fifth_oct, 13}, {rest, 7},
    {D >> fifth_oct, 13}, {B >> fourth_oct, 44}, {rest, 13},

    /*49th bar*/
    {rest, 77}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},

    /*50th bar*/
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, 

    /*51th bar*/
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},
    {rest, 25}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13}, 

    /*52th bar*/
    {rest, 25}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13}, 
    {rest, 25}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13}, 

    /*53th bar*/
    {rest, 25}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13}, 
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},

    /*54th bar*/
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},
    {rest, 25}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13},

    /*55th bar*/
    {rest, 21}, {D >> fifth_oct, 13}, {rest, 1}, {D >> fifth_oct, 13}, 
    {rest, 1}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13},
    {rest, 1}, {E >> fifth_oct, 13}, {rest, 1}, {E >> fifth_oct, 13},

    /*56th bar*/
    {rest, 1}, {E >> fifth_oct, 12}, {rest, 1}, {E >> fifth_oct, 12},
    {rest, 1}, {E >> fifth_oct, 12}, {rest, 1}, {E >> fifth_oct, 12},
    {rest, 1}, {E >> fifth_oct, 12}, {rest, 1}, {E >> fifth_oct, 12},
    {rest, 1}, {E >> fifth_oct, 12}, {rest, 1}, {E >> fifth_oct, 12}
};

void startMusic(char title)
{
    curNote = 0;

    if (title == JUMP)
    {
        /*find a way to know which screen is*/
        enableChannel(channelA, 1, 0);
        enableChannel(channelB, 1, 0);
        enableChannel(channelC, 1, 0);
            
        setTone(channelA, menuNote1[curNote].pitch);
        setTone(channelB, menuNote2[curNote].pitch);
        setTone(channelC, menuNote3[curNote].pitch);
        
        setVolume(channelA, 0x0F);
        setVolume(channelB, 0x0F);
        setVolume(channelC, 0x0F);
    }
    else if(title == REPTILIA)
    {
        enableChannel(channelA, 1, 0);
        setTone(channelA, gameSong[curNote].pitch);
        setVolume(channelA, 0x0f);
    }
}


void updateMusic(UINT32 time_elapsed, char title)
{
    duration += time_elapsed;
    
    if (title == JUMP)
    {
        if (duration >= menuNote1[curNote].duration)
        {
            duration = 0;
            curNote++;

            if (curNote >= jumpLen)
                curNote = 0;
        
            setTone(channelA, menuNote1[curNote].pitch);
            setTone(channelB, menuNote2[curNote].pitch);
            setTone(channelC, menuNote3[curNote].pitch);
        }
    }
    else if(title == REPTILIA) 
    {
        if (duration >= gameSong[curNote].duration)
        {
            duration = 0;
            curNote++;

            if (curNote >= reptiliaLen)
                curNote = 0;
            
            setTone(channelA, gameSong[curNote].pitch);
        }
    }

    setEnvelope(0x08, 0x200F);
}
