#ifndef INPUT_H
#define INPUT_H

#include "bool.h"
#include "types.h"

#define LEFT_ARROW 0x4B 
#define RIGHT_ARROW 0x4D
#define ESC 0x01
#define SPACE_BAR 0x39

UINT32 input();
bool hasInput();

#endif