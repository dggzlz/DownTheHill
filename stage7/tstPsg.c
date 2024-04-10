#include "effects.h"
#include "psg.h"
#include "music.h"
#include <stdio.h>
#include <osbind.h>
#include <unistd.h> /*got from online used for pauses*/

#define delay 2
#define channelA 0
#define channelB 1
#define channelC 2

#define true 1
#define false 0

typedef unsigned int bool;

long getTime();
bool hasInput();


int main()
{
    UINT32 timeThen = 0, timeNow = 0, timeElapsed = 0;
    
    printf("Beginnig PSG Tests\n");
    /***TESTING CHANEL A***/
    printf("Channel A Tests with Tone 0x0AA\n");
    printf("Enabling channel A with Tone(1) and Noise(0)\n");
    enableChannel(channelA, 1, 0);

    printf("BEGIN Channel A Volume Tests");
    printf("Setting channel A volume to 15(MAX)\n");
    setVolume(channelA, 15);
    sleep(delay);

    printf("Setting channel A tone to 0x0AA\n");
    setTone(channelA, 0x0AA);
    sleep(delay);

    printf("Setting channel A volume to 4\n");
    sleep(delay);
    setVolume(channelA, 4);
    sleep(delay);
    
    printf("Setting channel A volume to 7\n");
    sleep(delay);
    setVolume(channelA, 7);
    sleep(delay);
    
    printf("STOPPING SOUND\n");
    sleep(delay);
    stopSound();

    /***TESTING CHANNEL B***/
    printf("Channel B Tests with Tone 0x3EF\n");
    printf("Enabling channel B with Tone(1) and Noise(0)\n");
    enableChannel(channelB, 1, 0);
    
    printf("BEGIN Channel B Volume Tests");
    printf("Setting channel B volume to 15(MAX)\n");
    setVolume(channelB, 15);
    sleep(delay);
    
    printf("Setting channel B tone to 0x3EF\n");
    setTone(channelB, 0x3EF);
    sleep(delay);
    
    printf("Setting channel B volume to 4\n");
    sleep(delay);
    setVolume(channelB, 4);
    sleep(delay);
    
    printf("Setting channel B volume to 7\n");
    sleep(delay);
    setVolume(channelB, 7);
    sleep(delay);
    
    printf("STOPPING SOUND\n");
    sleep(delay);
    stopSound();

    /***TESTING CHANNEL C***/
    printf("Channel C Tests with Tone 0x123\n");
    printf("Enabling channel C with Tone(1) and Noise(0)\n");
    enableChannel(channelC, 1, 0);
    
    printf("BEGIN Channel C Volume Tests");
    printf("Setting channel C volume to 15(MAX)\n");
    setVolume(channelC, 15);
    sleep(delay);
    
    printf("Setting channel C tone to 123\n");
    setTone(channelC, 123);
    sleep(delay);
    
    printf("Setting channel C volume to 4\n");
    sleep(delay);
    setVolume(channelC, 4);
    sleep(delay);
    
    printf("Setting channel C volume to 7\n");
    sleep(delay);
    setVolume(channelC, 7);
    sleep(delay);
    
    printf("STOPPING SOUND\n");
    sleep(delay);
    stopSound();

    /**TESTING ALL CHANNEL TOGETHER*/
    printf("TEST ALL CHANNELS WITH TONE AT ONCE\n");
    printf("ENABLING ALL CHANNELS WITH TONE\n");
    enableChannel(channelA, 1, 0);
    enableChannel(channelB, 1, 0);
    enableChannel(channelC, 1, 0);

    printf("Setting all channel volumes to 15(MAX)\n");
    setVolume(channelA, 15);
    setVolume(channelB, 15);
    setVolume(channelC, 15);

    printf("Setting channel A tone to 0x0AA\n");
    setTone(channelA, 0x0AA);
    printf("Setting channel B tone to 0x3EF\n");
    setTone(channelB, 0x3EF);
    printf("Setting channel C tone to 123\n");
    setTone(channelC, 123);
    sleep(delay);
    sleep(delay);
    sleep(delay);
    sleep(delay);

    printf("STOPPING SOUND\n");
    sleep(delay);
    stopSound();
    sleep(delay);

    /*testing sound effects*/
    printf("BEGIN SOUND EFFECTS TEST\n");
    printf("PLAYING SKIER HIT\n");
    playSkierDeath();
    printf("Press Key to End Sound Effect\n");

    while (!Cconis())        /* tone now playing, await key */
        ;

    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("PLAYING RESCUE HELICOPTER\n");
    playRescueChopper();
    printf("Press Key to End Sound Effect\n");

    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    printf("PLAYING SPAWNING\n");
    playSpawning();
    printf("Press Key to End Sound Effect\n");
    printf("END SOUNDS EFFECTS\n");

    while (!Cconis())        /* tone now playing, await key */
        ;
    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();

    stopSound();

    /***testing music now***/
    printf("testing music\nfirst the main game song\npress any key to stop it\n");

    timeNow = getTime();
    timeThen = timeNow;

    startMusic('r');

    timeElapsed = timeNow - timeThen;
    while (!hasInput())
    {     
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        
        if (timeElapsed > 0)
        {   
            updateMusic(timeElapsed, 'r');
            timeThen = timeNow;
        }  
    }

    stopSound();

    while (Cconis())         /* Clear any remaining key press in the buffer */
        Cconin();
    
    printf("now the main menu song\npress any key to stop it\n");
	
    timeNow = getTime();
    timeThen = timeNow;

    startMusic('j');

    timeElapsed = timeNow - timeThen;
    while (!hasInput())
    {     
        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        
        if (timeElapsed > 0)
        {   
            updateMusic(timeElapsed, 'j');
            timeThen = timeNow;
        }  
    }

    stopSound();

    printf("program ended\n");

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
