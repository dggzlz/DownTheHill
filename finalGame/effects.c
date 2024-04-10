/* File: effects.c 
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose: This file is part of the Sound Effects 
 * library (stage 7 of the project), and it contains the 
 * definitions for the functions prototypes defined on the 
 * effects.h module.
 * 
 * The functions of this library make use of the low level 
 * programmable sound generator library by making specific 
 * sound effect noises for certain aspects of the Down The Hill 
 * franchise.
 * 
 * Assumptions: 
 * To use any function in the psg library it is assumed and required 
 * that supervisor mode will have been entered.
 */
#include "effects.h"
#include "psg.h"
#include <unistd.h>
#include <osbind.h>


/*
Name:
   playSkierDeath    
Purpose:
    plays the sounds effect for the skier dying.      
Inputs: 
    none
Outputs:
    none
Details:
    The sound effect follows the instructions from the manula to activate sound 
*/
void playSkierDeath()
{   
    setNoise(0x1F);
    enableChannel(channelC, 0, 1);
    setVolume(channelC, 0X10);
    setEnvelope(0x08, 0x21FF);  
}

/*
Name:
    playSpawning 
Purpose:
    plays the sounds effect for the spawning f objects.      
Inputs: 
    none
Outputs:
    none
Details:
    The sound effect follows the instructions from the manula to activate sound    
*/
void playSpawning()
{
    setNoise(0x1F);

    enableChannel(channelC, 1, 0);
    setVolume(channelC, 0X10);
    setEnvelope(0x0E, 0x02FF);
}

/*
Name:
      playRescueChopper
Purpose:
    plays the sounds effect for the rescue chopper      
Inputs: 
    none
Outputs:
    none
Details:
    The sound effect follows the instructions from the manula to activate sound 
*/
void playRescueChopper()
{
    setNoise(0x0F);
    enableChannel(channelC, 0, 1);
    setVolume(channelC, 0X10); /*lets envelope control volume*/
    setEnvelope(0x08, 0x21FF);
}

