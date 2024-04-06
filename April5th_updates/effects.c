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

#define channelC 2

#define sirenTime 500000

void playSkierDeath()
{   
    enableChannel(channelC, 1, 0);
    setVolume(channelC, 0X10);
    setNoise(0x1F);
    setEnvelope(0x08, 0x210F);  
}

void playSpawning()
{
    enableChannel(channelC, 1, 0);
    setVolume(channelC, 0X10);
    setNoise(0x1F);
    setEnvelope(0x0E, 0x02FF);
}

void playRescueChopper()
{
    setNoise(0x0F);
    enableChannel(channelC, 0, 1);
    setEnvelope(0x08, 0x21FF);
    setVolume(channelC, 0X10); /*lets envelope control volume*/
}

void EndGameAmbulance()/*this function does not adhere to sound effects but we will add it anyway*/
{
    enableChannel(channelC, 1, 0);
    setVolume(1, 0x0B); 
    setTone(channelC, 0x0AA);
    setEnvelope(0x08, 0x00FF);   
}