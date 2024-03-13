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
    plotBitmap64(base32, player->x, 100, RightSnowBoarder, 128);
}

void renderPlayerLeft(Snowboarder *player, UINT32 *base32)
{
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
    plotBitmap64(base32, skier->x, skier->y, skierBM, 128);
}


void renderTree(Tree *tree, UINT32 *base32)
{
    plotBitmap64(base32,tree->x, tree->y, treeBM, 128);
    /*printf("tree located at x: %d, y: %d\n", tree->x,tree->y);*/
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
    if(!collisionCheck)
    {
        if (key == left)
        {
            renderPlayerLeft(model->player, base32);
        }
        else if (key == right)
        {
            renderPlayerRight(model->player, base32);
        }
    }
    else
    renderFakePlayer(base32);
    for(i = 0; i < treeArray.size; i++)
    {
        renderTree(model->tree, base32);
    }
}