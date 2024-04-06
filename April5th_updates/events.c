#include "events.h"
#include "RASTER.H"
#include "model.h"
#include "bool.h"
#include "effects.h"
#include <osbind.h>
#include <stdlib.h>
#include <stdio.h>



/****ANSYNCHRONOUS EVENTS****/

/*
Name:
    moveRequest       
Purpose:
    The purpose of this function is to change the 
    players position in the left or right direction.
    The function also keeps the player from avoiding 
    collisions with the edge while invulnerable and 
    going off screen.        
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
    char ch
        A character indicating the direction
        of the move request (left or right)    
Outputs: 
    None      
Details:
    Sets the posture of the player to either 
    "l" or "r" and sets the direction of 
    the movement either in the negative
    or positive based on the posture respectively.
    The players new x coordinate is set by adding
    the positive or negative direction multiplied
    by the amount of pixels the player can move.
    The function calls another function that
    determines if the player is invulnerable
    and if so checks if the player is attempting to 
    go past the boarder and if they are will set the
    players x coordinate right at the boarder so the can never go 
    past it.
Assumptions and Limitations: 
    This function assumes that the boundries of the space the player
    can traverse are meant for the Atari ST screen size.    
*/

void moveRequest(Snowboarder *player, char ch)
{
    int i = 0;
    player->posture = ch;
    
    if(ch == POSTURE_L)
    {
        i = -1;
    }
    else if(ch == POSTURE_R)
    {
        i = 1;
    }

    player->x += player->vel * i; 
    
    if(isPlayerInvulnerable(player))
    {
        if(player->x > 576)
            player->x = 576;
        if(player->x < LEFT_EDGE)
            player->x = LEFT_EDGE;
    }
         
}

/****SYNCHRONOUS TIMED EVENTS*****/

/*Skier events*/

/*
Name:
    spawnSkier       
Purpose:
    This function initializes the spawn locations of 
    the first wave of skiers    
Inputs:
    NPCskier *skier
        A pointer to the NPCskier object
    int yInit
        The initial y coordinate for the
        NPCskier object
Outputs: 
    None    
Details and Calculations:
    The possible x coordinates are 10 
    columnes that are size aligned. They are obtained
    using a random function that is then moded with 10 to 
    give a discrete value between 0-10. This value is 
    then multiplied by 64 since the bitmap of the skier
    is of size 64.    
*/
void spawnSkier(NPCskier *skier, int yInit)
{
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    skier->x = newPosition * 64;
    skier->y = yInit;
    skier->pos = 1;
    skier->deltaY = -2; /*vertical speed of skier*/
    skier->timer = 0;                                         
    skier->toDraw = true;
}

/*
Name:
    moveSkier   
Purpose:
    The purpose of this function is to move the NPCskier
    upwards at the speed specified by the deltaY attribute.
    It also sets the posture (pos) of the NPCskier to 
    alternate between its left and right bitmap when rendering. 
    It alternates based on the counter specified by the timer attribute.   
Inputs:
    NPCskier *skier
        A pointer to the NPCskier object
Outputs:
    None
        
Details and Calculations:
    The NPCskiers deltaY position is added to the y coordinate
    effectivly moving it up the screen. If the current time is
    greater than the NPCskiers timer then its position is altered
    and the timer is reset to two seconds. It is multiplied by 70 because
    the refresh rate is 70hertz which means 1 second is composed of 70
    clock ticks. If the skier goes above its maximum y coordinate,
    the fuinction will call another function to reset the NPCskiers 
    position.       
*/
void moveSkier(NPCskier *skier)
{ 
    skier->y += skier->deltaY;
    
    if(getTime() >= skier->timer)
    {
        if (skier->pos == 1)
        {
            skier->pos = 0;
        }else 
        {
            skier->pos = 1;
        }
        skier->timer = getTime() + 2 * 70;       
    }

    if (skier->y <= 31)
        resetSkier(skier);
}

/*Tree events*/

/*
Name:
   spawnTree    
Purpose:
    This function initializes the spawn locations of 
    the first wave of trees        
Inputs: 
    Tree *tree
        A pointer to the Tree object
    int yInit
        The initial y coordinate for the
        Tree object
Outputs:
    None
Details and Calculations:
    The possible x coordinates are 10 
    columnes that are size aligned. They are obtained
    using a random function that is then moded with 10 to 
    give a discrete value between 0-10. This value is 
    then multiplied by 64 since the bitmap of the skier
    is of size 64.        
*/

void spawnTree(Tree *tree, int yInit)
{   
    int newPosition = rand() % 10;

    while (newPosition == 0 || newPosition == 10)
        newPosition = rand() % 10;

    tree->x = newPosition * 64;
    tree->y = yInit;
    tree->upwardSpeed = -3;
}

/*
Name:
    moveTree   
Purpose:
    The purpose of this function is to move the 
    tree towards the top of the screen and upon 
    reaching its maximum y value, call a function
    to reset its position.
Inputs:
    Tree *tree
        A pointer to the Tree object
Outputs:
    None    
Details and Calculations:
    The Tree deltaY position is added to the y coordinate
    effectivly moving it up the screen. The function checks if 
    the y position is 31 or less and if so, resets the tree. 
    The maximum y position is 31 because some bitmaps
    that permanently remain at the top are 32x32 and this 
    prevents the trees from covering those other bitmaps.     
*/

void moveTree(Tree *tree)
{
    tree->y += tree->upwardSpeed;
    
    if(tree->y <= 31)
        resetTree(tree);
} 

/*****CONDITION-BASED EVENTS*****/

/*
Name:
    resetTree   
Purpose:
    The purpose of this function is to
    reset the tree to the bottom of the screen
    along a random x column.    
Inputs:
    Tree *tree
        A pointer to the Tree object
Outputs: 
    None     
Details and Calculations:
    The tree gets rest to a y of 400 since that is 
    the very bottom of the screen. The possible x coordinates are 10 
    columnes that are size aligned. They are obtained
    using a random function that is then moded with 10 to 
    give a discrete value between 0-10. This value is 
    then multiplied by 64 since the bitmap of the Tree
    is of size 64.        
*/

void resetTree(Tree *tree) 
{
    tree->y = 400;
    tree->x = (rand() % 10) * 64; 
} 

/*
Name:
    resetSkier
Purpose:
    The purpose of this function is to
    reset the NPCskier to the bottom of the screen
    along a random x column. 
Inputs:
    NPCskier *skier
        A pointer to the NPCskier object
Outputs: 
    None     
Details and Calculations:
    The skier gets rest to a y of 400 since that is 
    the very bottom of the screen. The possible x coordinates are 10 
    columnes that are size aligned. They are obtained
    using a random function that is then moded with 10 to 
    give a discrete value between 0-10. This value is 
    then multiplied by 64 since the bitmap of the Tree
    is of size 64. The skiers toDraw boolean attribute
    is reset, allowing it to be drawn on the screen 
    incase it was part of a previous collision.    
*/

void resetSkier(NPCskier *skier)
{
    skier->y = 400;
    skier->x = (rand() % 10) * 64;
    skier->toDraw = true;
}

/*
Name:
   checkColEdge    
Purpose:
    The purpose of this function is to check the players
    left and right edges to see if they have collided with 
    an edge.        
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    bool isCollision
        A boolean value that indicates if a collision
         has happened.            
Details:
    The function accesses the players edge coordinates 
    and checks if the coordinates are the same as the
    left and right coordinates of the edges of the screen.
    If the coordinates are the same, the boolean isCollison
    is set to true.     
*/

bool checkColEdge(Snowboarder *player)
{
    bool isCollision = false;

    if (player->x < LEFT_EDGE || (player->x + 64) > RIGHT_EDGE)
        isCollision = true;

    return isCollision;
}


/*
Name:
    checkCollisionObs 
Purpose:
    The purpose of this function is to check if
    the player has collided with a tree.
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
    Tree *tree
        A pointer to the Tree object
Outputs: 
    bool isCollision 
        A boolean value that indicates whether or
        not the player has collided with a tree. 
Details:
    Bounding box objects are created for the player and
    the tree. The 4 lines of the box are then set 
    according to the locations of the player and tree.
    The function then checks for an overlap between
    these boxes which would indicate a collision has occured.    
*/

bool checkCollisionObs(Snowboarder *player, Tree *tree)
{ 
    BoundingBox playerBox;
    BoundingBox treeBox;
    bool isCollision = false;

    playerBox.maxX = player->x + 64;
    playerBox.minX = player->x;
    playerBox.maxY = player->y + 64;
    playerBox.minY = player->y;
    
    treeBox.maxX = tree->x + 64; 
    treeBox.minX = tree->x;
    treeBox.maxY = tree->y + 64;
    treeBox.minY = tree->y;

    if ((playerBox.maxY > treeBox.minY && playerBox.minY < treeBox.maxY)
        &&(playerBox.maxX > treeBox.minX && playerBox.minX < treeBox.maxX)) 
        isCollision = true;

    return isCollision;   
}

/*
Name:
    checkCollisionSkier   
Purpose:
     The purpose of this function is to check if
    the player has collided with a skier.   
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
    NPCskier *skier
        A pointer to the NPCskier object
Outputs: 
    bool isCollision 
        A boolean value that indicates whether or
        not the player has collided with a skier.  
Details:
    Bounding box objects are created for the player and
    the skier.The function will only check collisions 
    against the skier if the skier has not previously 
    had a collision during its time from the bottom to the top
    of the screen. This is decided by whether the toDraw attribute
    of the skier is true or false. The 4 lines of the box are then set 
    according to the locations of the player and skier.
    The function then checks for an overlap between
    these boxes which would indicate a collision has occured.          
*/

bool checkCollisionSkier(Snowboarder *player, NPCskier *skier)
{
    BoundingBox playerBox;
    BoundingBox skierBox;
    bool isCollision = false;

    if (skier->toDraw)
    {
        playerBox.maxX = player->x + 64;
        playerBox.minX = player->x;
        playerBox.maxY = player->y + 64;
        playerBox.minY = player->y;
        
        skierBox.maxX = skier->x + 64; 
        skierBox.minX = skier->x;
        skierBox.maxY = skier->y + 64;
        skierBox.minY = skier->y;

        if ((playerBox.maxY > skierBox.minY && playerBox.minY < skierBox.maxY)
            &&(playerBox.maxX > skierBox.minX && playerBox.minX < skierBox.maxX)) 
        {    
            isCollision = true;
            skier->toDraw = false;
        }
    }
    return isCollision; 
}


/*
Name:
    hasSkierColWithTree   
Purpose:
    The purpose of this function is to check whether 
    a skier has collided with a tree.        
Inputs: 
    NPCskier *skier
        A pointer to the NPCskier object
    Tree *tree
        A pointer to the Tree object
Outputs: 
    None      
Details:
    Bounding box objects are created for the player and
    the skier.The function will only check collisions 
    against the skier if the skier is in the same
    column as a tree and has not previously had a collision during 
    its time from the bottom to the top of the screen. This is 
    decided by whether the toDraw attribute of the skier is true or
    false. The 4 lines of the box are then set according to the locations
    of the player and skier.
    The function then checks for an overlap between
    these boxes which would indicate a collision has occured.    
*/
void hasSkierColWithTree(NPCskier *skier, Tree *tree)
{
    BoundingBox treeBox;
    BoundingBox skierBox;

    if(skier->x == tree->x)
    {
        if (skier->toDraw)
        {

            treeBox.maxX = tree->x + 64; 
            treeBox.minX = tree->x;
            treeBox.maxY = tree->y + 64;
            treeBox.minY = tree->y;
            
            skierBox.maxX = skier->x + 64; 
            skierBox.minX = skier->x;
            skierBox.maxY = skier->y + 64;
            skierBox.minY = skier->y;

            if ((treeBox.maxY > skierBox.minY && treeBox.minY < skierBox.maxY)
                &&(treeBox.maxX > skierBox.minX && treeBox.minX < skierBox.maxX)) 
            {    
                skier->toDraw = false;
            }
        }
    }
}

/*Collisions*/

/*
Name:
    collisionObs
Purpose:
    The purpose of this function is to account 
    for a collison and affect the state of the game.        
Inputs:
    Lives *lives
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    None     
Details:
    This function will check if the player is invulnerable or 
    not and if not will decrease the life of the player,
    change the position of the player to the starting location,
    and make the player invulnerable for three seconds.      
*/
void collisionObs(Lives *lives, Snowboarder *player)
{
    if(!isPlayerInvulnerable(player))
    {
        decreaseLife(lives);
        resetPos(player);
        player->invulnerableTimer = getTime() + 3 * 70;
        player->counter = 0;
    }
}

/*
Name:
    collisionSkier   
Purpose:
    The purpose of this function is to update the count of
    the skiers hit and call the function that updates the 
    score of the player.        
Inputs:
    ScoreCounter *score
        A pointer to the ScoreCounter object
    SkierCounter *counter
        A pointer to the SkierCounter object
    UINT32 timeCurr
        A long value of the current time.                     /*description could be better?
Outputs: 
    None      
Details:
    Adds one to the skier hit counter and calls scoreUpdates
    with the last parameter as true to indicate that the collision
    has taken place with a skier inorder to add the extra 30 points.      
*/

void collisionSkier(ScoreCounter *score, SkierCounter *counter,
                    UINT32 timeCurr)
{
    scoreUpdates(score, timeCurr, true);
    counter->hitCounter += 1;
}

/*
Name:
    decreaseLife
Purpose:
    The purpose of this function is to decrease the lives of the 
    Lives object.     
Inputs: 
    Lives *lives
Outputs: 
    None     
Details:
    Subtracts one from the numLives attribute which holds the number
    of lives the player currently has. Once the lives reaches 0, the 
    gameOver attribute is set to true which effectivly triggers the 
    end of the game.      
*/

void decreaseLife(Lives *lives)
{
    lives->numLives += -1;

    if (lives->numLives == 0)
    {
        lives->gameOver = true;
    }
} 

/*
Name:
    resetPos   
Purpose:
    Changes the position of the player to the 
    original starting position.       
Inputs: 
    Snowboarder *player
        A pointer to the Snowboarder object
Outputs:
    None          
Details:
    Sets the Snowboarder objects x coordinate
    to a hard coded value which is the same as
    where the player started.     
*/

void resetPos(Snowboarder *player)
{
    player->x = 288;
}

/*
Name:
    scoreUpdates       
Purpose:
    The purpose of this function is to update
    the score of the player.       
Inputs:
    ScoreCounter *score
        A pointer to the ScoreCounter object
    UINT32 timeCurr
        A long value of the current time.                     /*description could be better?
    bool skierHit
        A boolean that indicates whether or not 
        a skier was collided with by the player.
Outputs:
    None      
Details and Calculations:
    This function updates the score by ten points
    every three seconds and checks if those three
    seconds have elapsed before updating the score.
    It will also check the boolean if the skier was hit
    and if true it will add 30 points to the score.          
*/

void scoreUpdates(ScoreCounter *score, UINT32 timeCurr, bool skierHit)
{   
    if((timeCurr - score->timer) >= 70 * 3) 
    {
        score->scorePlayer += 10;
        score->timer = timeCurr;
    }

    if(skierHit)
    {
        score->scorePlayer += 30;
    }
}

/*
Name:
    isPlayerInvulnerable       
Purpose:
    The purpose of this function is to check whether 
    or not the player is invulnerable.    
Inputs:
    Snowboarder *player
Outputs:
    bool isInvulnerable
        A boolean value that says if the 
        player is invulnerable or not     
Details and Calculations:
    Compares the current time to the 
    invulnerability timer to check 
    whether the 3 seconds has elapsed or not
    and returns the boolean depending.         
*/

bool isPlayerInvulnerable(Snowboarder *player)
{
    bool isInvulnerable;
    
    if(getTime() < player->invulnerableTimer)
        isInvulnerable = true;
    else
        isInvulnerable = false;

    return isInvulnerable;
}

/*Game ends*/

/*
Name:
    checkGameOver   
Purpose:
     The purpose of this function is to check
     whether or not the game has ended.   
Inputs:
    Lives *lives
        A pointer to the Lives object
Outputs:
    bool isOver
        A boolean value that says if the 
        game is over or not       
Details:
    This function checks the gameover attribute
    of the Lives object which is true once all
    the lives have been lost, thus indicating the game 
    is over.       
*/

bool checkGameOver(Lives *lives)
{
    bool isOver = false;
    if(lives->gameOver == true)
        isOver = true;

    return isOver;
}

/*
Name:
    gameOver   
Purpose:
    Changes the location of the ScoreCounter
    and SkierCounter objects to prepare them 
    for display on the end game splash screen.
Inputs: 
    ScoreCounter *score
        A pointer to the ScoreCounter object
    SkierCounter *hitCount
        A pointer to the SkierCounter object
Outputs: 
    None  
Details:
    This function uses pointers to access the attributes 
    of the ScoreCounter and SkierCounter objects and 
    changes their (x,y) position.        
*/
void gameOver(ScoreCounter *score, SkierCounter *hitCount)
{
    score->x= 400;
    score->y=300;
    hitCount->x=400;
    hitCount->y=175;
}
