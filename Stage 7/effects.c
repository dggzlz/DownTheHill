#include "effects.h"


void playEffectSkiierDeath()
{
    setNoise(0xAA);
    setEnvelope(0x0F, 0x00FF);
    enableChannel(2, 0, 1);
    setVolume(2, 0X10); /*lets envelope control volume*/  
}

void playEffectRescueCopter()
{
    setNoise(0x0F);
    setEnvelope(0x08, 0x00FF);
    enableChannel(2, 0, 1);
    setVolume(2, 0X10); /*lets envelope control volume*/
}

void EndGameAmbulance()/*this function does not adhere to sound effects but we will add it anyway*/
{
    setTone(1, 0x0AA);
    enableChannel(1, 1, 0);
    setVolume(1, 11); 
    while (!Cconis())		/* tone now playing, await key */
        {
        writePsg(1, 0xAA);    
        usleep(sirenTime); 

        writePsg(1, 0xD6);
        usleep(sirenTime); 
        }
}