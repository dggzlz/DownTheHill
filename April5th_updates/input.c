/* File: input.c
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose:  
 *  This file is part of stage 5 of the project. it is charged of handling
 *  any input from the keyboard. These functions are wrapper that call TOS 
 *  system calls to handle keyboard input
 */

#include "input.h"
#include <stdio.h>
#include <osbind.h>

/*
Name:
    input
Purpose:
    This is a wrapper function that uses Cnecin to read characters from Keyboard
Inputs:
    None
Outputs: 
    A UINT16 read from the keyboard.   
Details:
    Cnecin reads the key that was pressed. The value that returns is 
    bitshifted 16 times. 
*/
UINT32 input()
{
    return Cnecin() >> 16;  
}

/*
Name:
    input
Purpose:
    This is a wrapper function that uses Cconis to read characters from Keyboard
Inputs:
    None
Outputs: 
    A boolean that checks if there was any input
Details:
    Cconis check if there was any keyboard input, if there was, then it returns
    true, otherwise it returns false.   
     
*/
bool hasInput()
{
    bool hasInput = false;

    if (Cconis())
        hasInput = true;

    return hasInput;
}



