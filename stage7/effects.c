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
#include <unistd.h>
#define sirenTime 500000


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