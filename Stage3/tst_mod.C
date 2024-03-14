#include <stdio.h>
#include "model.h"
#include "events.h"
#include "keys.h"

int main() {
    /*Initialize game model*/
    
    Model model;

    printf("Starting test program...\nClick enter to continue\n");
    getchar();
    while(getchar() != '\n');
    
    

    snowboarderSet(&(model.snowboarder));

    spawnSkier(&(model.skiers[0]));
    spawnSkier(&(model.skiers[1]));
    spawnSkier(&(model.skiers[2]));

    spawnTree(&(model.trees[0]));    
    spawnTree(&(model.trees[1]));  

    newLife(&(model.hearts));
    newCounter(&(model.skierCounter));  

    printf("Player initial position: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    printf("Click enter to continue\n");
    getchar();
    while(getchar() != '\n');


    /*Simulate move left event*/
    printf("calling moveRequest to move the player\n");
    moveRequest(KEY_LEFT, &(model.snowboarder));
    printf("Player position after moving left: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    printf("Press enter to continue\n");
    getchar();
    while(getchar() != '\n');

    /*Simulate move right event*/
    printf("calling moveRequest to move the player\n");
    moveRequest(KEY_RIGHT, &(model.snowboarder));
    printf("Player position after moving right: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    printf("Press enter to continue\n");
    getchar();
    while (getchar() != '\n');

    /*Simulate move right event again*/
    printf("calling moveRequest to move the player\n");
    moveRequest(KEY_RIGHT, &(model.snowboarder));
    printf("Player position after moving right: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    printf("Press enter to continue\n");
    getchar();
    while (getchar() != '\n');

    /*Simulate tree movement*/
    moveTree(&(model.trees[1]));
    printf("Tree position after moving: (%d, %d)\n", model.trees[1].x, model.trees[1].y);
    printf("Press enter to continue\n");
    getchar();
    while (getchar() != '\n');

    return 0;
}
