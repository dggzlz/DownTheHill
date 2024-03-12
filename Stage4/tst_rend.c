/*Test Driver Program*/

#include "renderer.h"
#include "model.h"
#include "events.h"
#include "raster.h"
#include "types.h"
#include <osbind.h>
#include <stdio.h>
#define screenWidth 640
#define screenHeight 400


int main()
{
    UINT32 *base = Physbase();
    
  
/*tree initilizations*/ 
    int treeStart = screenHeight;

    Tree newTree1 = createTree(0);
    Tree *tree1 = &newTree1;
    
/*Lives initilization*/
    Lives newLife = createLife();
    Lives *lifePointer = &newLife;

/*test 1*/
    printf("Beginning Tree Column Tests\n");
    renderTree(tree1,base);
    printf("tree located at x: %d, y: %d\n", tree->x,tree->y);
    printf("Tree Column Tests End\n");
    printf("press a key to continue\n");
    getchar();
    clearScreen(base);

/*test 2*/
    printf("Test all trees movement\n");
    while(treeStart>0)
    {
    moveTree(tree1);
    treeStart -= 64;
    clearScreen(base);
    }
    printf("Tree Movement Test End\n");
    printf("press a key to continue\n");
    getchar();
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
    renderFakePlayer(base);
    printf("End fake player test\n");
     printf("press a key to continue\n");
    getchar();
    clearScreen(base);
    printf("tests ended");




    return 0;
}