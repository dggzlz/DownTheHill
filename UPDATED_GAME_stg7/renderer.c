/*void render(const Model *model, UINT32 *base32) counter is 16pixels*/
#include "model.h"
#include "events.h"
#include "raster.h"
#include "renderer.h"
#include "bitmaps.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"

#define left_edge 0
#define right_edge 640
#define upper_edge 0
#define bottom_edge 400
#define height 128



void renderPlayer(Snowboarder* player, UINT32 *base)
{
    
    if (player->x >= 0 && player->x <= 576)
    {
        if (player->posture == 'r')
            plotBitmap64(base, player->x, player->y, RightSnowBoarder, height);
        else if (player->posture == 'l')
            plotBitmap64(base, player->x, player->y, LeftSnowBoarder, height);
    }
    
    if((getTime() <= player->invulnerableTimer))
    {
    renderFakePlayer(base);
    }


}

void renderFakePlayer(UINT32 *base) /*object for 5 second invincibility*/
{
    int x = 320;
    int y = 100;
    int y2 = 0;
   /* plotBitmap64(base, x, y, RightSnowBoarder, height);*/
    plotBitmap64(base, x, y2, angel, height);

}

void renderSkier(NPCskier *skier, UINT32 *base)
{   
    if (skier->x >= left_edge && skier->x <= (right_edge - 64) 
            && skier->y >= upper_edge && skier->y <= (bottom_edge - 64))
        {
            if(skier->pos == 0)          
                plotBitmap64(base, skier->x, skier->y, skierLeftBM, height);
            else
                plotBitmap64(base, skier->x, skier->y, skierRightBM, height);
        }



}


void renderTree(Tree *tree, UINT32 *base)
{
    if (tree->x >= left_edge && tree->x <= (right_edge - 64) && tree->y >= upper_edge && tree->y <= (bottom_edge - 64))
        plotBitmap64(base, tree->x, tree->y, treeBM, height);
}



void renderScore(ScoreCounter *score, UINT32 *base)
{
        int playerScore = score->scorePlayer;
        int startX = 0;
        int startY = 0;
        int digitSpace = 16;
        int placeValue = 1000000; 
        int xPos = startX;
        bool leadingZeros = true;

        if(playerScore == 0)
        {
                plotBitmap16((UINT16*)base, startX, startY, numBitmaps[0], 16);
                return;
        }

        while(placeValue > 0)
        {
                int digit = (playerScore / placeValue) % 10;

                if(digit != 0 || !leadingZeros || placeValue == 1)
                {
                        leadingZeros = false;
                        plotBitmap16((UINT16*)base, xPos, startY, numBitmaps[digit], 16);
                        xPos += digitSpace;
                }

                placeValue /= 10;
        }

}


void renderLives(Lives *lives, UINT32 *base)
{
    int count = lives->numLives;
    int xCoor = lives->x;

    while(count>0)
    {
        plotBitmap32(base, xCoor,lives->y, heartLifeBM, 32);
        xCoor -= 32;
        count--;
    }

}

void renderModel(const Model *model, UINT32 *base)
{
    int i;

    renderPlayer(&model->snowboarder, base);   
   /* renderFakePlayer(base);*/
    
    for(i = 0; i < numOfTrees; i++)
        renderTree(&model->trees[i], base);
    
    for(i = 0; i < numOfSkiers; i++)
        renderSkier(&model->skiers[i], base);
    
    renderLives(&model->hearts,base);
    renderScore(&model->score,base);
  /*  renderSkierHitCount(model->newCounter,base);*/
}

    /*NEED TO CREATE BITMAPS FOR FONTS
void renderSkierHitCount();
*/

/*void renderGameOver();*/