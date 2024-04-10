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
   checkColEdge    
Purpose:
    The purpose of this function is to check the players
    left and right edges to see if they have collided with 
    an edge.        
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    bool isCollision
        A boolean value that indicates if a collision
         has happened.            
Details:
    The function accesses the players edge coordinates 
    and checks if the coordinates are the same as the
    left and right coordinates of the edges of the screen.
    If the coordinates are the same, the boolean isCollison
    is set to true.     
*/
void playSkierDeath()
{   
    enableChannel(channelC, 1, 0);
    setVolume(channelC, 0X10);
    setNoise(0x1F);
    setEnvelope(0x08, 0x210F);  
}

/*
Name:
   checkColEdge    
Purpose:
    The purpose of this function is to check the players
    left and right edges to see if they have collided with 
    an edge.        
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    bool isCollision
        A boolean value that indicates if a collision
         has happened.            
Details:
    The function accesses the players edge coordinates 
    and checks if the coordinates are the same as the
    left and right coordinates of the edges of the screen.
    If the coordinates are the same, the boolean isCollison
    is set to true.     
*/
void playSpawning()
{
    enableChannel(channelC, 1, 0);
    setVolume(channelC, 0X10);
    setNoise(0x1F);
    setEnvelope(0x0E, 0x02FF);
}

/*
Name:
   checkColEdge    
Purpose:
    The purpose of this function is to check the players
    left and right edges to see if they have collided with 
    an edge.        
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    bool isCollision
        A boolean value that indicates if a collision
         has happened.            
Details:
    The function accesses the players edge coordinates 
    and checks if the coordinates are the same as the
    left and right coordinates of the edges of the screen.
    If the coordinates are the same, the boolean isCollison
    is set to true.     
*/
void playRescueChopper()
{
    setNoise(0x0F);
    enableChannel(channelC, 0, 1);
    setVolume(channelC, 0X10); /*lets envelope control volume*/
    setEnvelope(0x08, 0x21FF);
}

