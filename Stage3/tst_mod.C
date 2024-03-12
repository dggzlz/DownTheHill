#include <stdio.h>
#include "model.h"
#include "events.h"

int main() {
    /*Initialize game model*/
    printf("Starting test program...\nClick enter to continue\n");
    getchar();
    
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
        .skierCounter = {0, 0, 0, 0}
    };

    printf("Player initial position: (%d, %d)\n", model.snowboarder.x, model.snowboarder.y);
    
    Tree tree = {256, 400, 0}; 
    Lives lives = {3, 576, 100};  /*initial lives*/ 

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
