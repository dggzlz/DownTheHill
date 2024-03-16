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

    int treeStart;
    Tree newTree1; 
    Tree *tree1 = &newTree1;

    /*Lives initilization*/
    Lives life;
    Lives *lifePointer = &life;
    newLife(lifePointer);

    /*test 1 lives lost*/

    clearScreen(base);
    printf("BEGINNING LIVES LOST TEST\n");

    printf("LIVES LEFT ARE: %d\n", lifePointer->numLives);
    printf("Press ENTER To Decrease Lives\n");
    renderLives(lifePointer,base);
    getchar(); 
    clearScreen(base);

   decreaseLife(lifePointer);

   printf("LIVES LEFT ARE:%d\n", lifePointer->numLives);
   printf("Press ENTER To Decrease Lives\n");
   renderLives(lifePointer,base);
   getchar(); 
   clearScreen(base);

   decreaseLife(lifePointer);

   printf("LIVES LEFT ARE:%d\n", lifePointer->numLives);
   printf("Press ENTER To Decrease Lives\n");
   renderLives(lifePointer,base);
   getchar(); 
   clearScreen(base);

   decreaseLife(lifePointer);

   printf("LIVES LEFT ARE:%d\n", lifePointer->numLives);
   printf("LIVES TEST DONE\nPRESS ENTER\n");
   renderLives(lifePointer,base);
   getchar(); 
   clearScreen(base);
   

    /*test 2 tree render*/

    printf("Beginning Tree Initialization And Render\n");
    spawnTree(tree1);
    treeStart = tree1->y;
    printf("Press Enter to Render Tree\n");
    while(getchar() != '\n')
    getchar();
    clearScreen(base);
    printf("Tree location at\n x:%d y:%d\n", tree1->x, tree1->y);
    printf("What a Cool Tree\nPress Enter to Continue\n");
    renderTree(tree1,base);
    while(getchar() != '\n')
    getchar();
    clearScreen(base);

/*test 3*/
    printf("PRESS ENTER CONTINUOUSLY\nTO MOVE TREE UPWARDS TO THE TOP\nY location bug exists\n");
    getchar();
    while(treeStart>0)
    {
    clearScreen(base);
    moveTree(tree1);
    treeStart -= 5;
    renderTree(tree1,base);
    printf("Tree location at\n x:%d y:%d\n", tree1->x, tree1->y);
    getchar();
    }
    printf("Tree Movement Test End\n");
    printf("press a key to continue\n");
    getchar();
    clearScreen(base);



/*test 4*/
   /* printf("Begin fake player test\n");
    renderFakePlayer(base);
   /* printf("End fake player test\n");
    while (getchar() != '\n');/*clear buffer
    printf("\nPRESS ENTER TO CONTINUE\n");
    getchar(); /* Wait for user input to continue
    clearScreen(base);
    printf("tests ended");*/
    


    return 0;
}