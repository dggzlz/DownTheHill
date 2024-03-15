#include <stdio.h>
#include "model.h"
#include "events.h"
#include "bool.h"
#include "keys.h"

int main() {
    /*Initialize game model*/
    Model model;
    bool isCollision;

    printf("Starting test program...\nClick enter to continue\n");
    getchar(); 

    /***SETTING SNOWBOARDER***/
    printf("setting the snowboarder's initial values\n");
    snowboarderSet(&(model.snowboarder));

    printf("initial values for the player {x:%d, y:%d, deltax:%d, posture:%c}\n", 
        model.snowboarder.x, model.snowboarder.y, 
        model.snowboarder.deltaX, model.snowboarder.posture);
    
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();
    
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

    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /***SETTING TREES***/
    printf("setting values for the trees\n");
    spawnTree(&(model.trees[0]));    
    spawnTree(&(model.trees[1]));  

    /*TREE #1*/
    printf("initial values for the tree #1 {x:%d, y:%d, speed:%d}\n", 
        model.trees[0].x, model.trees[0].y, 
        model.trees[0].upwardSpeed);
    
    /*TREE #2*/
    printf("initial values for the tree #2 {x:%d, y:%d, speed:%d}\n", 
        model.trees[1].x, model.trees[1].y, 
        model.trees[1].upwardSpeed);

    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /***SETTING SCORE***/   
    printf("setting values for the score\n");
    newScore(&(model.score));
    
    printf("initial values for the score {score:%d, x:%d, y:%d}\n", 
        model.score.scorePlayer, model.score.x, model.score.y);
    
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /***SETTING LIVES***/
    printf("setting values for the lives\n");
    newLife(&(model.hearts));

    printf("initial values for the lives {lives #:%d, x:%d, y:%d}\n", 
        model.hearts.numLives, model.hearts.x, model.hearts.y);
    
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /***SETTING COUNTER***/
    printf("setting values for the counter\n");
    newCounter(&(model.skierCounter));  

    printf("initial values for the lives {counter:%d, score:%d, x:%d, y:%d}\n", 
        model.skierCounter.hitCounter, model.skierCounter.scoreCounter, 
        model.skierCounter.x, model.skierCounter.y);
    
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();
    

    /***TESTING MOVE REQUESTS AND POSITIONS CHANGES***/
    printf("testing moves requests and synchronous change of position\n");
    printf("Player initial position: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();
    

    /*Simulate move left event*/
    printf("calling moveRequest to move the player to the left\n");
    moveRequest(KEY_LEFT, &(model.snowboarder));
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    printf("Player position after moving left: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /*Simulate move right event*/
    printf("calling moveRequest to move the player to the right\n");
    moveRequest(KEY_RIGHT, &(model.snowboarder));
    printf("Player position after moving right: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /*Simulate move right event again*/
    printf("calling moveRequest to move the player to the right\n");
    moveRequest(KEY_RIGHT, &(model.snowboarder));
    printf("Player position after moving right: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /*Simulate obstacles movement*/
    printf("next, moving obstacles\n");
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    moveTree(&(model.trees[1]));
    printf("Tree #1 position after moving: (%d, %d)\n", 
        model.trees[1].x, model.trees[1].y);

    moveTree(&(model.trees[1]));
    printf("Tree #1 position after moving for a second time: (%d, %d)\n", 
        model.trees[1].x, model.trees[1].y);

    moveSkier(&(model.skiers[1]));
    printf("skier #1 position after moving: (%d, %d)\n", model.skiers[1].x, 
        model.skiers[1].y);

    moveTree(&(model.trees[1]));
    printf("skier #1 position after moving for a second time: (%d, %d)\n", 
        model.skiers[1].x, model.skiers[1].y);

    /***TESTING COLLISIONS***/
    while (getchar() != '\n');/*clear buffer*/  
    printf("testing collisions...press enter to continue.\n");
    getchar();

    if (checkCollisionObs(&(model.snowboarder), &(model.trees[0]))){
            printf("Collision detected!\n");
    }
    else{
        printf("no collision!\n");
    }

    while (getchar() != '\n');/*clear buffer*/  
    printf("press enter to continue.\n");
    getchar();

    printf("provoking a collision...\n");
    model.snowboarder.x = 20;
    model.skiers[0].x = 50;
    model.snowboarder.y = 50;
    model.skiers[0].y = 55;

    if (checkCollisionObs(&(model.snowboarder), &(model.trees[0]))){
        printf("Collision detected!\n");
    }
    else{
        printf("no collision!\n");
    }
    
    while (getchar() != '\n');/*clear buffer*/  
    printf("press enter to continue.\n");
    getchar();

    printf("testing collision with obstacles now\n");
    collisionObs(&(model.hearts), &(model.snowboarder));
    printf("values after the collision: player's x: %d, lives #:%d", 
         model.snowboarder.x, model.hearts.numLives);

    while (getchar() != '\n');/*clear buffer*/  
    printf("press enter to continue.\n");
    getchar();

    printf("testing collision with skier...\n");
    collisionSkier(&(model.score), &(model.skierCounter));
    printf("values after the collision with skier: score:%d, skier counter:%d\n", 
        model.skierCounter.scoreCounter, model.skierCounter.hitCounter);

    printf("program terminated\n");

    return 0;
}
