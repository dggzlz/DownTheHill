#include <stdio.h>
#include "model.h"
#include "events.h"

int main() {
    /*Initialize game model*/
    printf("Starting test program...\nClick enter to continue\n");
    getchar();
    while(getchar() != '\n');
    
    Model model = {
        snowboarderSet(),
        .skiers = {
            newSkier(),
            newSkier(),
            newSkier(),
            newSkier()
        },
        .trees = {
            createTree(),
            createTree()
        },
        .hearts = {
            createLife(),
            createLife(),
            createLife()
        },
        .skierCounter = newCounter()
    };

    printf("Player initial position: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    printf("Click enter to continue\n");
    getchar();
    while (getchar() != '\n');


    /*Simulate move left event*/
    moveRequest(KEY_LEFT, &model.snowboarder);
    printf("Player position after moving left: (%d, %d)\n", model.snowboarder.x, model.snowboarder.y);

    /*Simulate move right event*/
    moveRequest(KEY_RIGHT, &model.snowboarder);
    printf("Player position after moving right: (%d, %d)\n", model.snowboarder.x, model.snowboarder.y);

    /*Simulate move right event again*/
    moveRequest(KEY_RIGHT, &model.snowboarder);
    printf("Player position after moving right again: (%d, %d)\n", model.snowboarder.x, model.snowboarder.y);

    /*Simulate tree movement*/
    treeMoves(&tree);
    printf("Tree position after moving: (%d, %d)\n", tree.x, tree.y);

    return 0;
}
