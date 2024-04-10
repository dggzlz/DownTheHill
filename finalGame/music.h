#ifndef MUSIC_H
#define MUSIC_H
#include "types.h"

#define rest 0
#define C 0xD5D
#define C_sharp 0xC9C
#define D 0xBE7
#define D_sharp 0xB3C
#define E 0xA9B
#define F 0xA02
#define F_sharp 0x973
#define G 0x8EB
#define G_sharp 0x86B
#define A 0x7F2
#define A_sharp 0x780
#define B 0x714

#define second_oct 1
#define third_oct 2
#define fourth_oct 3
#define fifth_oct 4
#define sixth_oct 5
#define seventh_oct 6
#define eitghth_oct 7

#define REPTILIA 'r'
#define JUMP 'j'

typedef struct
{
    int pitch;
    UINT32 duration;  /*duration in milliseconds*/
} Note;

void startMusic(char title);
void updateMusic(UINT32 time_elapsed, char title);

#endif