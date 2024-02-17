#include <stdio.h>
#include "model.h"
#include "events.h"

int main() {
    /*Initialize game model*/
    printf("Starting test program...\nClick enter to continue\n");
    getchar();
    
    Snowboarder player = {3, 320, 100, 0};
    printf("Player initial position: (%d, %d)\n", player.x, player.y);
    
    Tree tree = {256, 400, 0}; 
    Lives lives = {3, 576, 100};  /*initial lives*/ 

    /*Simulate move left event*/
    moveRequest(KEY_LEFT, &player);
    printf("Player position after moving left: (%d, %d)\n", player.x, player.y);

    /*Simulate move right event*/
    moveRequest(KEY_RIGHT, &player);
    printf("Player position after moving right: (%d, %d)\n", player.x, player.y);

    /*Simulate move right event again*/
    moveRequest(KEY_RIGHT, &player);
    printf("Player position after moving right again: (%d, %d)\n", player.x, player.y);

    /*Simulate tree movement*/
    treeMoves(&tree);
    printf("Tree position after moving: (%d, %d)\n", tree.x, tree.y);

    return 0;
}
