/*void render(const Model *model, UINT32 *base32) counter is 16pixels*/
#include "Stage3/model.h"
#include "Stage3/model.c"
#include "Stage2/raster.h"
#include "Stage2/raster.c"
#include "BitMap Arrays/BitMapArrays.h"
#include <osbind.h>






void renderPlayer(const Snowboarder *player, UINT32 *base32)
{
    plotBitMap64(base32,player->x,100,player->snowBoarder,128);
}

void renderFakePlayer(UINT32 *base32, const UINT32 *bitmap) /*object for 5 second invincibility*/
{
    int x = 320;
    int y = 100;
    plotBitMap64(base32,x,y,snowBoarder,128);
}

void renderskier(const NPCskier *skier, UINT32 *base32)
{
    plotBitMap64(base32,skier->x,skier->y,skier->npcSkier,128);
}


void renderTree(const Tree *tree, UINT32 *base32)
{
    plotBitMap64(base32,tree->x,tree->y,tree->tree,128);
    printf("tree located at x: %d, y: %d\n", tree->x,tree->y);
}



void renderLives(const Lives *lives, UINT32 *base32)
{
    int count = lives->numLives;
    printf("number of lives is: %d\n", lives->numLives);
    printf("hearts displayed is: %d\n",count)
    int xCoor = lives->x;
    

    while(count>0)
    {
        plotBitMap32(base32,xCoor,lives->y,lives->heartsHealth,32);
        printf("location of life is: %d\n", xCoor);
        xCoor -= 32;
        count--;

    }

}