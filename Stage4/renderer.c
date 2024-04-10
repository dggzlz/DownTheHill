/* File: renderer.c
 * Contributers: Juan Diego Serrato, Diego Gonzalez
 * Project: Down the Hill
 * Course: COMP 2659 - Machinery II
 * Section: 001
 * Instructor: Paul Pospisil
 * 
 * Purpose:  
 *  This File is part of stage 4 of the project, and it contains the function 
 *  that draw the model of the videogame.
 * 
 * Assumptions: 
 *  The functions are meant to draw, and therefore won't be checking for any 
 *  conditions of the objects rather than if their coordinates are within the 
 *  screen. This means the model that will be draw, should have its value previously set. 
 */

#include "model.h"
#include "events.h"
#include "raster.h"
#include "renderer.h"
#include "bitmaps.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"

/*
Name:
    stopCursor
Purpose:
    it stop the cursor from blinking        
*/

void stopCursor()
{
    printf("\033f");
    fflush(stdout);
}

/*
Name:
    renderPlayer        
Purpose:
    The purpose of this function is to render
    the Snowboarder object      
Inputs:
    Snowboarder* player
        A pointer to the Snowboarder object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs: 
    None     
Details:
    Checks that the players location is within the bounds 
    of the screen and then depending on the posture of the
    player will render the appropriate bitmap. It checks
    if the player is invulnerable and if so renders the 
    Angel protector to indicate the player is invulnerable.       
*/
void renderPlayer(Snowboarder* player, UINT32 *base)
{
    if (player->x >= LEFT_EDGE && player->x <= RIGHT_EDGE)
    {
        if (player->posture == POSTURE_R)
            plotBitmap64(base, player->x, player->y, rightSnowBoarderBM, HEIGHT_64);
        else if (player->posture == POSTURE_L)
            plotBitmap64(base, player->x, player->y, leftSnowBoarderBM, HEIGHT_64);
    }
    
    if(getTime() <= player->invulnerableTimer)
    {
        renderAngel(base);
    }
}

/*
Name:
    renderAngel        
Purpose:
    The purpose of this function is to render
    the Paul protector bitmap.       
Inputs:
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs: 
    None
Details:
    This function creates variables for the desired
    location of the Angel which is at the top centre
    of the screen then renders it.       
*/
void renderAngel(UINT32 *base) /*object for 5 second invulnerability*/
{
    int x = SCREEN_CENTER_X;
    int y = 100;
    int y2 = 0;
    plotBitmap64(base, x, y2, angelBM, HEIGHT_64);
}

/*
Name:
    renderSkier        
Purpose:
    The purpose of this function is to render
    the NPCskier object         
Inputs:
    NPCskier *skier
        A pointer to the NPCskier object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs: 
    None    
Details:
    Checks if the skier has not collided and renders
    the skier so long as its position is within the 
    bounds of the screen, and based on the posture 
    renders the appropriate bitmap. If the skier has
    collided it renders the Grim Reaper spirit who
    has come to claim the soul of the skier.      
*/

void renderSkier(NPCskier *skier, UINT32 *base)
{   
    if (skier->toDraw)
    {
        if (skier->x >= LEFT_EDGE && skier->x <= (RIGHT_EDGE - 64) 
                && skier->y >= UPPER_EDGE && skier->y <= (BOTTOM_EDGE - 64))
        {
            if(skier->pos == 0)          
                plotBitmap64(base, skier->x, skier->y, leftSkierBM, HEIGHT_64);
            else if (skier->pos == 1)
                plotBitmap64(base, skier->x, skier->y, rightSkierBM, HEIGHT_64);
        }
    }
    else
    {
        if (skier->x >= LEFT_EDGE && skier->x <= (RIGHT_EDGE - 64) 
                && skier->y >= UPPER_EDGE && skier->y <= (BOTTOM_EDGE - 64))
        {        
            plotBitmap64(base, skier->x, skier->y, grimReaperBM, HEIGHT_64);  
        }
    }
}

/*
Name:
    renderTree        
Purpose:
    The purpose of this function is to render
    the Tree object         
Inputs:
    Tree *tree
        A pointer to the Tree object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs: 
    None     
Details:
    This function checks if the trees position is
    within the bounds of the screen and if so 
    renders the tree at the appropriate location.       
*/

void renderTree(Tree *tree, UINT32 *base)
{
    if (tree->x >= LEFT_EDGE && tree->x <= (RIGHT_EDGE - 64) 
        && tree->y >= UPPER_EDGE && tree->y <= (BOTTOM_EDGE - 64))
        plotBitmap64(base, tree->x, tree->y, treeBM, HEIGHT_64);
}

/*
Name:
    renderScore        
Purpose:
    The purpose of this function is to render
    the ScoreCounter object         
Inputs:
    ScoreCounter *score
        A pointer to the ScoreCounter object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs: 
    None    
Details:
    This function iterates through each digit of the score count,
    starting from the most significant digit to the least significant digit. It uses
    modulus to extract the remainder of the division and calls the plot for that specific
    number bitmap.
    The rendering starts from the position specified by the ScoreCounter object's coordinates (startX, startY)
    and progresses horizontally with a fixed spacing between digits.             
*/

void renderScore(ScoreCounter *score, UINT32 *base)
{
    int playerScore = score->scorePlayer;
    int startX = score->x;
    int startY = score->y;
    int digitSpace = 15; /*space between digits*/
    int placeValue = 10000; /*max value*/
    int xPos = startX;
    int digit = 0;

    if (playerScore <= placeValue)
    {
        while(placeValue > 0)
        {
            digit = (playerScore / placeValue) % 10; 
            xPos += digitSpace;
            plotBitmap16((UINT16*)base, xPos, startY, numberBM_ptr[digit], HEIGHT_16);
            xPos += digitSpace;
            placeValue /= 10;   
        }
    }
}

/*
Name:
    renderSkiersHitBitMap        
Purpose:
    The purpose of this function is to render
    the SkierCounter bitmap         
Inputs:
    SkierCounter *skierHit
        A pointer to the SkierCounter object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs:
    None 
Details:
    This function renders the bitmap icon that
    represents the skiers hit counter in the top 
    left corner of the screen.      
*/

void renderSkiersHitBitMap(SkierCounter *skierHit, UINT32 *base)
{
    plotBitmap32(base, 0, 4, skierCounterBM, HEIGHT_32);
}

/*
Name:
    renderSkiersHit        
Purpose:
    The purpose of this function is to render
    the SkierCounter hit count        
Inputs:
    SkierCounter *skierHit
        A pointer to the SkierCounter object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs:
    None    
Details:
    This function iterates through each digit of the hit count,
    starting from the most significant digit to the least significant digit. It uses
    modulus to extract the remainder of the division and calls the plot for that specific
    number bitmap.
    The rendering starts from the position specified by the SkierCounter object's coordinates (startX, startY)
    and progresses horizontally with a fixed spacing between digits.
*/
void renderSkiersHit(SkierCounter *skierHit, UINT32 *base)
{
    int skiersHit = skierHit->hitCounter;
    int startX = skierHit->x;
    int startY = skierHit->y;
    int digitSpace = 15; /*space between digits*/
    int placeValue = 100; /*max value*/
    int xPos = startX;
    int digit = 0;

    if (skiersHit <= placeValue)
    {
        while(placeValue > 0)
        {
            digit = (skiersHit / placeValue) % 10;
            xPos += digitSpace;
            plotBitmap16((UINT16*)base, xPos, startY, numberBM_ptr[digit], HEIGHT_16);
            xPos += digitSpace;
            placeValue /= 10;
        }
    }
}

/*
Name:
    renderLives        
Purpose:
    Renders the hearts bitmap to represent
    the amount of tlives the player has left.        
Inputs:
    Lives *lives
        A pointer to the Lives object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs:
    None   
Details:
    This function sets a integer count variable
    equal to the number of lives a player has.
    It will then loop that many times plotting 
    the heart and for any lives greater than one
    will shift the new plotting position to the 
    left by 32 pixels and then decreasing the count.    
Assumptions and Limitations: 
    This function has the limitation of having to be 
    plotted on the right side of the screen otherwise 
    the rest of the hearts will not be visible.  
*/
void renderLives(Lives *lives, UINT32 *base)
{
    int count = lives->numLives;
    int xCoor = lives->x;

    while(count > 0)
    {
        plotBitmap32(base, xCoor,lives->y, heartLifeBM, HEIGHT_32);
        xCoor -= 32;
        count--;
    }
}

/*
Name:
    renderModel        
Purpose:
    The purpose of this function is to render
    each object of the game.  
Inputs:
    const Model *model
        A pointer to the Model object
    UINT32 *base
        A long base pointer to the start of 
        the frame buffer
Outputs:
    None       
Details:
    This function calls the render function
    of each object of the game. For the objects
    that are part of an array, this function will 
    iterate through each object and render it.          
*/
void renderModel(const Model *model, UINT32 *base)
{
    int i;
    
    renderPlayer(&model->snowboarder, base);   
    renderLives(&model->hearts,base);
    renderScore(&model->score,base);
    renderSkiersHit(&(model->skierCounter), base);
    renderSkiersHitBitMap(&(model->skierCounter), base);
    
    for(i = 0; i < numOfTrees; i++)
        renderTree(&model->trees[i], base);
    
    for(i = 0; i < numOfSkiers; i++)
        renderSkier(&model->skiers[i], base);
}

