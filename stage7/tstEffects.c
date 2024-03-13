#include "effects.h"
#include "psg.h"
#include <stdio.h>
#include <osbind.h>
#include <unistd.h> /*got from online used for pauses*/m

int main()
{
    
    long old_ssp = Super(0); 

    printf("BEGIN SOUND EFFECTS TEST\n");
    usleep(delay);
    printf("PLAYING SKIER HIT\n");
    usleep(delay);
    playEffectSkiierDeath();
    usleep(delay);
    printf("Press Key to End Sound Effect\n");
    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();
    stopSound();

    printf("PLAYING RESCUE HELICOPTER\n");
    playEffectRescueCopter();
    printf("Press Key to End Sound Effect\n");
    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();
    stopSound();

    printf("PLAYING AMBULANCE\n");
    EndGameAmbulance();
    printf("Press Key to End Sound Effect\n");
    printf("END SOUNDS EFFECTS");

    Super(old_ssp);
	return 0;
}