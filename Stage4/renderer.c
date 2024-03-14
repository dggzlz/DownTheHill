/*void render(const Model *model, UINT32 *base32) counter is 16pixels*/
#include "model.h"
#include "events.h"
#include "raster.h"
#include "renderer.h"
#include "bitmaps.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"



void renderPlayerRight(Snowboarder *player, UINT32 *base32)
{
    if(player->x >= 1 && player->x <= 575)
    plotBitmap64(base32, player->x, 100, RightSnowBoarder, 128);
}
void renderPlayer(Snowboarder* player, UINT32 *base32, char posture)
{
    if (player->x >= 1 && player->x <= 575){
        if (posture == 'r')
            plotBitmap64(base32, player->x, 100, RightSnowBoarder, 128)
        else if (posture == 'l')
            plotBitmap64(base32, player->x, 100, LeftSnowBoarder, 128);
    }
}
void renderPlayerLeft(Snowboarder *player, UINT32 *base32)
{
    if(player->x >= 1 && player->x <= 575)
    plotBitmap64(base32, player->x, 100, LeftSnowBoarder, 128);
}

void renderFakePlayer(UINT32 *base32) /*object for 5 second invincibility*/
{
    int x = 320;
    int y = 100;
    plotBitmap64(base32, x, y, RightSnowBoarder, 128);
}

void renderSkier(NPCskier *skier, UINT32 *base32)
{
    if(skier->x >= 1 && skier->x <= 575 && skier->y >= 0 && skier->y <= 336)/*does this work considering unsigned?*/
    plotBitmap64(base32, skier->x, skier->y, skierBM, 128);
}


void renderTree(Tree *tree, UINT32 *base32)
{
    if(tree->x >= 1 && tree->x <= 575 && tree->y >= 0 && tree->y <= 336)
    plotBitmap64(base32,tree->x, tree->y, treeBM, 128);
}

void renderLives(Lives *lives, UINT32 *base32)
{
    int count = lives->numLives;
    int xCoor = lives->x;

    while(count>0)
    {
        plotBitmap32(base32, xCoor,lives->y, heartLifeBM, 32);
        xCoor -= 32;
        count--;
    }

}

renderModel(const Model *model, UINT32 *base32)
{
    int i;
    int j;
    if(!checkCollision())
    
        renderPlayer(model->player, base32, model->player->posture);   
    
    else
        renderFakePlayer(base32);
    
    for(i = 0; i < numOfTrees; i++)
    {
        renderTree(model->tree, base32);
    }

    for(j = 0; j < numOfSkiers; j++)
    {
        renderSkier(model->skier, base32);
    }
    
    renderLives(model->lives,base32);
  /*  renderSkierHitCount(model->newCounter,base32);*/
    
}

    /*NEED TO CREATE BITMAPS FOR FONTS
void renderSkierHitCount();
*/

/*void renderGameOver();*/