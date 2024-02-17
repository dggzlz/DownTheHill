/*Test Driver Program*/
#include "Stage3/model.h"
#include "Stage3/model.c"
#include "Stage2/raster.h"
#include "Stage2/raster.c"
#include "Stage3/bitmaps.h"
#include "Stage4/renderer.c"
#include "Stage4/renderer.h"
#include <osbind.h>
#define screenWidth 640
#define screenHeight 400


int main()
{
    UINT32 *base = Physbase();
    
  
/*tree initilizations*/ 
    treeStart = screenHeight;

    newTree1 = createTree(base,0);
    *tree1 = newTree1;
    
    newTree2 = createTree(base,64);
    *tree2 = newTree2;

     newTree3 = createTree(base,128);
    *tree3 = newTree3;

     newTree4 = createTree(base,192);
    *tree4 = newTree4;

    newTree5 = createTree(base,256);
    *tree5 = newTree5;

    newTree6 = createTree(base,320);
    *tree6 = newTree6;

    newTree7 = createTree(base,384);
    *tree7 = newTree7;

    newTree8 = createTree(base,448);
    *tree8 = newTree8;

    newTree9 = createTree(base,512);
    *tree9 = newTree9;

    newTree10 = createTree(base,576);
    *tree10 = newTree10;
/*Lives initilization*/
    newLife = createLife();
    *lifePointer = newLife;

/*snowboarder initilization*/
    

/*test 1*/
  printf("Beginning Tree Column Tests\n");
    renderTree(tree1,base);
    renderTree(tree2,base);   
    renderTree(tree3,base); 
    renderTree(tree4,base);
    renderTree(tree5,base);
    renderTree(tree6,base);
    renderTree(tree7,base);
    renderTree(tree8,base);
    renderTree(tree9,base);
    renderTree(tree10,base);

    printf("Tree Column Tests End\n");
    clearScreen(base);

/*test 2*/
    printf("Test all trees movement\n");
    while(treeStart>0)
    {
    moveTree(tree1);
    moveTree(tree2);
    moveTree(tree3);
    moveTree(tree4);
    moveTree(tree5);
    moveTree(tree6);
    moveTree(tree7);
    moveTree(tree8);
    moveTree(tree9);
    moveTree(tree10);
    renderTree(tree1,base);
    renderTree(tree2,base);   
    renderTree(tree3,base); 
    renderTree(tree4,base);
    renderTree(tree5,base);
    renderTree(tree6,base);
    renderTree(tree7,base);
    renderTree(tree8,base);
    renderTree(tree9,base);
    renderTree(tree10,base);
    treeStart -= 64;
    clearScreen(base);
    }
    printf("Tree Movement Test End\n");
    clearScreen(base);

/*test 3*/
    printf("Begin Lives lost Test\n");
    renderLives(lifePointer,base);
    updateLives(lifePointer);
    renderLives(lifePointer,base);
    updateLives(lifePointer);
    renderLives(lifePointer,base);
    updateLives(lifePointer);
    renderLives(lifePointer,base);
    printf("Lives lost Test Ends\n");

/*test 4*/
    printf("Begin fake player test\n");
    renderFakePlayer(base,snowBoarder);
    printf("End fake player test\n");
/*test 5*/
    printf("Begin snowboard player test\n");



    return 0;
}