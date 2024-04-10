/*Test Driver Program*/

#include "renderer.h"
#include "RASTER.H"
#include "types.h"
#include "model.h"
#include "events.h"
#include <osbind.h>
#include <stdio.h>
#include <unistd.h> /*got from online used for pauses*/

#define screenWidth 640
#define screenHeight 400
#define delay 2

int main()
{
    UINT32 *base = Physbase();
    
    /*set model*/
    Model model;
    setModel(&model);
    

    printf("Rendering a snapshot of the model\n");
    printf("PRESS ENTER TO CONTINUE");
    getchar();

    clearScreen(base);
    renderModel(&model, base);

    sleep(delay);
    printf("moving player, setting some trees and some skiers\n");
    model.skiers[0].y = 100;
    model.skiers[1].y = 100;
    model.trees[0].y = 100;
    model.trees[1].y = 100;
    model.snowboarder.posture = 'l';
    printf("PRESS ENTER TO CONTINUE");
    getchar();

    clearScreen(base);
    renderModel(&model, base); 

    sleep(delay);
    printf("decreasing life\n");
    model.hearts.numLives -= 1;
    printf("PRESS ENTER TO CONTINUE");
    getchar();

    clearScreen(base);
    renderModel(&model, base);

    sleep(delay);
    printf("program terminated.\n");
    
    
    return 0;
}