#include <stdio.h>
#include "model.h"
#include "events.h"
#include "bool.h"

int main() {
    /*Initialize game model*/
    Model model;
    bool isCollision;

    printf("Starting test program...\nClick enter to continue\n");
    getchar(); 

    /***SETTING SNOWBOARDER***/
    printf("setting the model initial values\n");
    setModel(&model);

    printf("initial values for the player {x:%d, y:%d, vel:%d, posture:%c}\n", 
    model.snowboarder.x, model.snowboarder.y, 
    model.snowboarder.vel, model.snowboarder.posture);
    
    while (getchar() != '\n');/*clear buffer*/    
    printf("PRESS ENTER TO CONTINUE\n");
    getchar();
    
    /*SKIER #1*/
    printf("initial values for the skier #1 {x:%d, y:%d, delta y:%d, pos: %d, toDraw: %d}\n", 
        model.skiers[0].x, model.skiers[0].y, model.skiers[0].deltaY, 
        model.skiers[0].pos, model.skiers[0].toDraw);
    /*SKIER #2*/
    printf("initial values for the skier #2 {x:%d, y:%d, delta y:%d, pos: %d, toDraw: %d}\n", 
        model.skiers[1].x, model.skiers[1].y, model.skiers[1].deltaY, 
        model.skiers[1].pos, model.skiers[1].toDraw);

    /*SKIER #3*/
    printf("initial values for the skier #3 {x:%d, y:%d, delta y:%d, pos: %d, toDraw: %d}\n", 
        model.skiers[2].x, model.skiers[2].y, model.skiers[2].deltaY, 
        model.skiers[2].pos, model.skiers[2].toDraw);

    printf("PRESS ENTER TO CONTINUE\n");
    getchar();

    /***SETTING TREES***/
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

    printf("initial values for the lives {counter:%d, x:%d, y:%d}\n", 
        model.skierCounter.hitCounter, 
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
    moveRequest(&model.snowboarder, 'l');
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
    moveRequest(&model.snowboarder, 'r');
    printf("Player position after moving right: (%d, %d)\n", 
        model.snowboarder.x, model.snowboarder.y);
    while (getchar() != '\n');/*clear buffer*/    
    printf("press enter to continue\n");
    getchar();

    /*Simulate move right event again*/
    printf("calling moveRequest to move the player to the right\n");
    moveRequest(&model.snowboarder,'r');
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

    printf("checking collision with edges\n");
    
    model.snowboarder.x = 0;
    printf("collision with left edge.\n");
    if (checkColEdge(&(model.snowboarder))){
        printf("Collision detected!\n");
    }
    else{
        printf("no collision!\n");
    }

    printf("collision with right edge.\n");
    model.snowboarder.x = 575;
    if (checkColEdge(&(model.snowboarder))){
        printf("Collision detected!\n");
    }
    else{
        printf("no collision!\n");
    }

    printf("provoking a collision...\n");
    model.snowboarder.x = 128;
    model.skiers[0].x = 128;
    model.snowboarder.y = 200;
    model.skiers[0].y = 180;

    if (checkCollisionSkier(&(model.snowboarder), &(model.skiers[0]))){
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
    collisionSkier(&model.score, &model.skierCounter, 0);
    printf("values after the collision with skier: score:%d, skier counter:%d\n", 
         model.score.scorePlayer, model.skierCounter.hitCounter);

    printf("program terminated\n");

    return 0;
}
