#include psg.h 
#include <osbind.h>

int main()
{
    
    long old_ssp = Super(0); 

    printf("Beginnig PSG Tests\n");
    printf("Channel A Tests with Tone 0x0AA\n");
    printf("Enabling channel A with Tone(1) and Noise(0)\n");
    enableChannel(0, 1, 0);
    printf("BEGIN Channel A Volume Tests");
    printf("Setting channel A volume to 15(MAX)\n");
    setVolume(0, 15);
    usleep(delay);
    printf("Setting channel A tone to 0x0AA\n");
    setTone(0, 0x0AA);
    usleep(delay);
    printf("Setting channel A volume to 4\n");
    usleep(delay);
    setVolume(0, 4);
    usleep(delay);
    printf("Setting channel A volume to 7\n");
    usleep(delay);
    setVolume(0, 7);
    usleep(delay);
    printf("STOPPING SOUND\n");
    usleep(delay);
    stopSound();

    printf("Channel B Tests with Tone 0x3EF\n");
    printf("Enabling channel B with Tone(1) and Noise(0)\n");
    enableChannel(1, 1, 0);
    printf("BEGIN Channel B Volume Tests");
    printf("Setting channel B volume to 15(MAX)\n");
    setVolume(1, 15);
    usleep(delay);
    printf("Setting channel B tone to 0x3EF\n");
    setTone(1, 0x3EF);
    usleep(delay);
    printf("Setting channel B volume to 4\n");
    usleep(delay);
    setVolume(1, 4);
    usleep(delay);
    printf("Setting channel B volume to 7\n");
    usleep(delay);
    setVolume(1, 7);
    usleep(delay);
    printf("STOPPING SOUND\n");
    usleep(delay);
    stopSound();

    printf("Channel C Tests with Tone 0x123\n");
    printf("Enabling channel C with Tone(1) and Noise(0)\n");
    enableChannel(2, 1, 0);
    printf("BEGIN Channel C Volume Tests");
    printf("Setting channel C volume to 15(MAX)\n");
    setVolume(2, 15);
    usleep(delay);
    printf("Setting channel C tone to 123\n");
    setTone(2, 123);
    usleep(delay);
    printf("Setting channel C volume to 4\n");
    usleep(delay);
    setVolume(2, 4);
    usleep(delay);
    printf("Setting channel C volume to 7\n");
    usleep(delay);
    setVolume(2, 7);
    usleep(delay);
    printf("STOPPING SOUND\n");
    usleep(delay);
    stopSound();

    printf("TEST ALL CHANNELS WITH TONE AT ONCE\n");
    printf("ENABLING ALL CHANNELS WITH TONE\n");
    enableChannel(0, 1, 0);
    enableChannel(1, 1, 0);
    enableChannel(2, 1, 0);
    printf("Setting all channel volumes to 15(MAX)\n");
    setVolume(0, 15);
    setVolume(1, 15);
    setVolume(2, 15);
    printf("Setting channel A tone to 0x0AA\n");
    setTone(0, 0x0AA);
    printf("Setting channel B tone to 0x3EF\n");
    setTone(1, 0x3EF);
    printf("Setting channel C tone to 123\n");
    setTone(2, 123);
    usleep(delay);
    usleep(delay);
    usleep(delay);
    usleep(delay);
    printf("STOPPING SOUND\n");
    usleep(delay);
    stopSound();
    usleep(delay);
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