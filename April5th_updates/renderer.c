/*void render(const Model *model, UINT32 *base32) counter is 16pixels*/
#include "model.h"
#include "events.h"
#include "raster.h"
#include "renderer.h"
#include "bitmaps.h"
#include "splash.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"


void stopCursor()
{
    printf("\033f");
    fflush(stdout);
}

void renderPlayer(Snowboarder* player, UINT32 *base)
{
    
    if (player->x >= LEFT_EDGE && player->x <= RIGHT_EDGE)
    {
        if (player->posture == 'r')
            plotBitmap64(base, player->x, player->y, rightSnowBoarderBM, HEIGHT_64);
        else if (player->posture == 'l')
            plotBitmap64(base, player->x, player->y, leftSnowBoarderBM, HEIGHT_64);
    }
    
    if(getTime() <= player->invulnerableTimer)
    {
        renderAngel(base);
    }
}

void renderAngel(UINT32 *base) /*object for 5 second invincibility*/
{
    int x = SCREEN_CENTER_X;
    int y = 100;
    int y2 = 0;
    plotBitmap64(base, x, y2, angelBM, HEIGHT_64);
}


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

void renderTree(Tree *tree, UINT32 *base)
{
    if (tree->x >= LEFT_EDGE && tree->x <= (RIGHT_EDGE - 64) 
        && tree->y >= UPPER_EDGE && tree->y <= (BOTTOM_EDGE - 64))
        plotBitmap64(base, tree->x, tree->y, treeBM, HEIGHT_64);
}

void renderScore(ScoreCounter *score, UINT32 *base)
{
        int playerScore = score->scorePlayer;
        int startX = score->x;
        int startY = score->y;
        int digitSpace = 15;
        int placeValue = 10000; 
        int xPos = startX;

        while(placeValue > 0)
        {
            int digit = (playerScore / placeValue) % 10;
            xPos += digitSpace;
            plotBitmap16((UINT16*)base, xPos, startY, numberBM_ptr[digit], HEIGHT_16);
            xPos += digitSpace;
            placeValue /= 10;
        }

}
void renderSkiersHitBitMap(SkierCounter *skierHit, UINT32 *base)
{
    plotBitmap32(base, 0, 4, skierCounterBM, HEIGHT_32);
}

void renderSkiersHit(SkierCounter *skierHit, UINT32 *base)
{
    int skiersHit = skierHit->hitCounter;
    int startX = skierHit->x;
    int startY = skierHit->y;
    int digitSpace = 15;
    int placeValue = 100; 
    int xPos = startX;

    while(placeValue > 0)
    {
        int digit = (skiersHit / placeValue) % 10;
        xPos += digitSpace;
        plotBitmap16((UINT16*)base, xPos, startY, numberBM_ptr[digit], HEIGHT_16);
        xPos += digitSpace;
        placeValue /= 10;
    }
}


void renderLives(Lives *lives, UINT32 *base)
{
    int count = lives->numLives;
    int xCoor = lives->x;

    while(count>0)
    {
        plotBitmap32(base, xCoor,lives->y, heartLifeBM, HEIGHT_32);
        xCoor -= 32;
        count--;
    }

}

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

void renderSplashScr(const UINT32* splash, UINT32 *base)
{
    int i;
    
    for (i = 0; i < SPLASH_HEIGHT; i++) 
        *(base++) |= splash[i];
    
}
 

void renderGameOver(const Model *model, UINT32 *base)
{
    renderSplashScr(gameOverSplash, base);
    renderScore(&model->score,base);
    renderSkiersHit(&(model->skierCounter), base);
}