#include "input.h"
#include "bool.h"
#include <osbind.h>

char input()
{
    char input = (char) Cnecin();

    return input;  
}

bool hasInput()
{
    bool hasInput = false;

    if (Cconis())
        hasInput = true;

    return hasInput;
}

