#include "effects.h"
#include "psg.h"
#include <stdio.h>
#include <osbind.h>
#include <unistd.h> /*got from online used for pauses*/

#define delay 2

int main()
{

    printf("BEGIN SOUND EFFECTS TEST\n");
    
    printf("PLAYING SKIER HIT\n");
    sleep(delay);
    playSkierDeath();
    printf("Press Key to End Sound Effect\n\n");
    
    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("PLAYING SPAWNING\n");
    sleep(delay);
    playSpawning();
    printf("Press Key to End Sound Effect\n\n");
    
    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("PLAYING RESCUE HELICOPTER\n");
    sleep(delay);
    playRescueChopper();
    printf("Press Key to End Sound Effect\n\n");

    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("PLAYING AMBULANCE\n");
    sleep(delay);
    EndGameAmbulance();
    printf("Press Key to End Sound Effect\n\n");


    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("program ended\n");

	return 0;
}