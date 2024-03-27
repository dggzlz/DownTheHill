#include "rand.h"


#define RAND_MAX 0xA
unsigned int rseed = 0;

void srand(unsigned int x)
{
    rseed = x;
}

unsigned int rand(unsigned int x)
{   
    
    rseed += (64240 / x + 12345);
    return rseed % (RAND_MAX + 1);
}

/*https://rosettacode.org/wiki/Linear_congruential_generator#C*/