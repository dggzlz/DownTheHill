/* File: psg.c 
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose: This file is part of the Programmable Sound Generator 
 * library (stage 7 of the project), and it contains the 
 * definitions for the functions prototypes defined on the 
 * psg.h module.
 * 
 * The functions of this library are of "low-level". They only allow
 * direct manipulation of the PSG on the Atari ST. They are meant to be
 * called by other libraries to help make more complex shapes.
 * 
 * Assumptions: 
 * To use any function in the psg library it is assumed and required 
 * that supervisor mode will have been entered.
 */

#include "psg.h"
#include <osbind.h>

UINT8 mixerR7State = 0x3F; /*global variable for tracking state of register 7*/

/***Write To The PSG ***/
/*
Name: writePsg
Purpose:
        Selects a register and writes to the selected register
        by using the volatile pointers *PsgRegSelect and
        *PsgRegWrite.
Inputs: 
        int reg:
            An integer value that corresponds
            to register 0-15 which will be selected to.
        UINT8 val:
            A UINT8 value that corresponds to 
            the value that will be written to 
            the register.
Outputs: 
        None
Details:
        If the register to be written to is register 7,
        it will update the global variable mixerR7State.
Assumptions and Limitations:   
        This function assumes that when called, the caller will have entered supervisor
        mode.   
*/
void writePsg(int reg, UINT8 val)
{
    volatile char *PsgRegSelect = 0xFF8800;
    volatile char *PsgRegWrite  = 0xFF8802;
    long old_ssp = Super(0);

    if(reg >=0 && reg <= 15)
    {
        
        *PsgRegSelect = reg;
        *PsgRegWrite = val;
        
        if(reg == 7)
        {
            mixerR7State = val;
        }
    }

    Super(old_ssp);
}

/***Fine And Coarse Tune a Channel ***/
/*
Name:
        setTone 
Purpose:
        Fine and coarse tunes a channel by changing
        the 8 bits for the fine tuning and the 4 bits 
        for the coarse tuning.
Inputs: 
        int channel:
             An integer between 0 and 2 inclusive that
             correseponds to channels A,B,C respectively.
        int tuning:
            A 12 bit value that corresponds to the 12 bits
            that determine the tone/pitch of a sound.    
Outputs: 
        None

Calculations:
        "channel * 2, tuning & 0xFF" This line accesses the
        fine tuning of a channel and masks the tuning value
        with 0xFF to remove the values of the coarse tune.

        "channel * 2 + 1, (tuning >> 8) & 0x0F" This line
        accesses the coarse tuning register and shifts the
        coarse tuning value to the right so that it removes
        the 8 bit fine tuning values.
Assumptions and Limitations:
        This function assumes that when called, the caller will have entered supervisor
        mode.       
*/

void setTone(int channel, int tuning)
{
    if((channel >= 0 && channel <= 2) && (tuning >= 0 && tuning <= 0xFFF))
    {
        writePsg(channel << 1, tuning & 0xFF); /*8bit fine tuning*/
        writePsg((channel << 1) + 1, (tuning >> 8) & 0x0F); /*4 bit coarse tune*/ 
    }
}

/***Set The Volume For a Channel***/
/*
Name:
      setVolume  

Purpose: Changes the level channel 
        for a corresponding channel. 

Inputs: int channel:
             An integer between 0 and 2 inclusive that
             correseponds to channels A,B,C respectivly.
        int volume:
            An integer between 0 and 15 that corresponds
            to the volume level.
Outputs: 
        None

Calculations:
        Since the channels are 0,1,2 for A,B,C,
        this line "8 + channel, volume" offsets to 
        the level register for the respective channel.

Assumptions and Limitations: 
        This function assumes that when called, the caller will have entered supervisor
        mode.       
*/

void setVolume(int channel, int volume)
{
    if(channel >= 0 && channel <=2 && volume >= 0 && volume <= 15)
        writePsg(8 + channel, volume); /*level channels are 8,9,A*/
}
/****if i pass b0-3, 4th bit, on/off, sets the envelope*/

/***Enable Or Disable a Channel***/
/*
Name:
        enableChannel
Purpose:
        Turns the tone or noise channel on or off by 
        setting or clearing the bits that corresponds to the 
        respective channel and the corresponding tone 
        and noise depending on their state.
Inputs: int channel:
             An integer between 0 and 2 inclusive that
             correseponds to channels A,B,C respectivly.
        int toneOn:
            An integer to represent a boolean value of
            either 0 or 1 that corresponds to whether the
            tone channel is on or not.
        int noiseOn:
            An integer to represent a boolean value of
            either 0 or 1 that corresponds to whether the
            noise channel is on or not.
Outputs: 
        None
        
Calculations:
        In register 7 the tone corresponds to bits 0,1,2
        "mixer &= ~(1 << channel)" this line will shift one
        to the selective channel that is on and the bitwise
        not it since 0 is on and 1 is off for reg7. If the tone is
        off it is just set to 1 to turn it off. The same idea is
        in place for the noise but since we want to shift between the 
        3rd,4th and 5th bit we shift 8 which corresponds to binary 
        00001000 thus ignoring the tone bits.  

Assumptions and Limitations:      
        This function assumes that when called, the caller will have entered supervisor
        mode.  
*/

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

/***Silence All PSG Sound***/
/*
Name:
        stopSound
Purpose: Silences all PSG sound production by
        disabling the tone and noise for all
        channels A,B, and C by setting the lower 
        six bits to 1 which turns off the channel.
        It also turns the volume for each channel
        to zero so that upon enabling, the volume
        will be at a known state.   
Inputs: 
        None
Outputs: 
        None        
Assumptions and Limitations: 
        This function assumes that when called, the caller will have entered supervisor
        mode.     
*/

void stopSound()
{
    int i = 0;

    writePsg(7, 0x3F);/*disables all the channels*/
    
    for(i; i < 3; i++)
        setVolume(i, 0);
}

/***SET NOISE***/
/*
Name:
        setNoise
Purpose:    
        Sets the frequency of the noise channel.
Inputs: 
        int tuning
            A 5 bit value that defines the noise frequency.
Outputs: 
        None        
Assumptions and Limitations: 
        This function assumes that when called, the caller will have entered supervisor
        mode.     
*/

void setNoise(int tuning)
{
    if (tuning >= 0 && tuning <= 0x1F)
        writePsg(6, tuning);
}

/***SET ENVELOPE***/
/*
Name:
        setEnvelope
Purpose:    
        Sets the envelope which defines the pattern of
        the sound and the speed the sounds takes to complete 
        one cycle of the pattern.
Inputs: 
        int shape
            The four bit integer that defines the pattern
            of the sound over time.
        unsigned int sustain
            The 16 bit number that defines the frequency 
            of the envelope which is how fast the sound
            takes to complete one cycle of the pattern.
Outputs: 
        None        
Assumptions and Limitations: 
        This function assumes that when called, the caller will have entered supervisor
        mode.     
*/

void setEnvelope(int shape, unsigned int sustain)
{
    writePsg(11, sustain & 0xFF);/*get low 8 bits*/
    writePsg(12, (sustain >> 8) & 0xFF); /*get high 8 bits*/

    /*LOAD SHAPE*/
    if(shape >= 0 && shape <= 0xFF)
        writePsg(13, shape);
}


