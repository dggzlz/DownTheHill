#include "rand.h"
#include "events.h"
#include "model.h"
#include <stdio.h>


int main(){

    Model model;
        /***SETTING SKIERS***/
    printf("setting values for the skiers\n");
    spawnSkier(&(model.skiers[0]));
    spawnSkier(&(model.skiers[1]));
    spawnSkier(&(model.skiers[2]));

    /*SKIER #1*/
    printf("initial values for the skier #1 {x:%d, y:%d, delta x:%d, delta y:%d}\n", 
        model.skiers[0].x, model.skiers[0].y, 
        model.skiers[0].deltaX, model.skiers[0].deltaY);

    /*SKIER #2*/
    printf("initial values for the skier #2 {x:%d, y:%d, delta x:%d, delta y:%d}\n", 
        model.skiers[1].x, model.skiers[1].y, 
        model.skiers[1].deltaX, model.skiers[1].deltaY);

    /*SKIER #3*/
    printf("initial values for the skier #3 {x:%d, y:%d, delta x:%d, delta y:%d}\n", 
        model.skiers[2].x, model.skiers[2].y, 
        model.skiers[2].deltaX, model.skiers[2].deltaY);
    return 0;
}

void spawnSkier(NPCskier *skier){
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    skier->x = newPosition * 64;
    skier->y = 399;
    skier->deltaX = 0;
    skier->deltaY = 0;
}
