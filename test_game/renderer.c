/*void render(const Model *model, UINT32 *base32) counter is 16pixels*/
#include "model.h"
#include "events.h"
#include "RASTER.H"
#include "renderer.h"
#include "bitmaps.h"
#include <osbind.h>
#include <stdio.h>
#include "types.h"



void renderPlayer(Snowboarder* player, UINT32 *base)
{
    if (player->x >= 1 && player->x <= 575){
        if (player->posture == 'r')
            plotBitmap64(base, player->x, 100, RightSnowBoarder, 128);
        else if (player->posture == 'l')
            plotBitmap64(base, player->x, 100, LeftSnowBoarder, 128);
    }
}

void renderFakePlayer(UINT32 *base) /*object for 5 second invincibility*/
{
    int x = 320;
    int y = 100;
    plotBitmap64(base, x, y, RightSnowBoarder, 128);
}

void renderSkier(NPCskier *skier, UINT32 *base)
{
    plotBitmap64(base, skier->x, skier->y, skierBM, 128);
}


void renderTree(Tree *tree, UINT32 *base)
{
    plotBitmap64(base, tree->x, tree->y, treeBM, 128);
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
    renderFakePlayer(base);
    
    for(i = 0; i < numOfTrees; i++)
        renderTree(&model->trees[i], base);
    
    for(i = 0; i < numOfSkiers; i++)
        renderSkier(&model->skiers[i], base);
        
    renderLives(&model->hearts,base);
  /*  renderSkierHitCount(model->newCounter,base);*/
}

    /*NEED TO CREATE BITMAPS FOR FONTS
void renderSkierHitCount();
*/

/*void renderGameOver();*/