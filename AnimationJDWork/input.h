#ifndef INPUT_H
#define INPUT_H

#define LEFT_ARROW 97 /*0x004B00000 USING "A" FOR NOW*/
#define RIGHT_ARROW 100 /*0x004D0000*/ /*USING "D" FOR NOW*/
#define ESC 27 /*0x01 /*0x0001001B*/

#include "bool.h"

char input();
bool hasInput();

#endif