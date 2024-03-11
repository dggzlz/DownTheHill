#include "psg.h"

UINT8 mixerR7State = 0x3F;/*global variable for tracking state of register 7*/


void writePsg(int reg, UINT8 val)
{
    if(reg >=0 && reg <= 15)
    {
        *PsgRegSelect = reg;
        *PsgRegWrite = val;
        if(reg == 7)
        {
            mixerR7State = val;
        }
    }
}

void setTone(int channel, int tuning)
{
    if(channel >= 0 && channel <= 2 && tuning >= 0 && tuning <= 0xFFF)
    {
    writePsg(channel * 2, tuning & 0xFF); /*8bit fine tuning*/
    writePsg(channel * 2 + 1, (tuning >> 8) & 0x0F); /*4 bit coarse tune*/ 
    }
}

void setVolume(int channel, int volume)
{
    if(channel >= 0 && channel <=2 && volume >= 0 && volume <=15)
    writePsg(8 + channel, volume); /*level channels are 8,9,A*/
}

void enableChannel(int channel, int toneOn, int noiseOn)
{
    if(channel >= 0 && channel <= 2)
    {
        UINT8 mixer = mixerR7State;
        if(toneOn)
        {
            mixer &= ~(1 << channel); /*bitwise NOT since r7 is reversed for some reason*/
        }
        else
        {
            mixer |= (1 << channel);
        }

        if(noiseOn)
        {
            mixer &= ~(8 << channel);
        }
        else
        {
            mixer |= (8 << channel);
        }

        writePsg(7, mixer);
    }
}

void stopSound()
{
    int i = 0;
    writePsg(7, 0x3F);/*disables all the channels*/
    for(i; i<=2; i++)
    {
        setVolume(i, 0);
    }
}