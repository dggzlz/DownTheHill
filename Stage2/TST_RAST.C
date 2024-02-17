#include "raster.h"
#include <stdio.h>
#include <osbind.h>
#include "types.h"

int main() {
    
    char *base8 = Physbase();
    UINT16 *base16 = Physbase();
    UINT32 *base32 = Physbase();
    int x1, y1, x2, y2;

    clearScreen(base32);
    printf("Starting test program...\nClick enter to continue\n");
    getchar();


    /***Test plotPixel***/
    printf("Testing plotPixel...\n");
    printf("set coordinate x: ");
    scanf("%d", &x1);
    printf("set coordinate y: ");
    scanf("%d", &y1);
    plotPixel(base16, x1, y1);
    printf("pixel plotted at given coordinates\n please enter to continue\n");
    getchar();
    

    /***Test plotVertical***/
    printf("Testing plotVertical...\n");
    printf("Set start coordinate x: ");
    scanf("%d", &x1);

    printf("Set coordinate y1: ");
    scanf("%d", &y1);
    
    printf("Set coordinate y2: ");
    scanf("%d", &y2);
    
    clearScreen(base32);    
    plotVertical(base8, x1, y1, y2);
    printf("Vertical line plotted.\nPlease press Enter to continue.\n");
    getchar(); /*Wait for user input to continue*/


    /***Test plotHorizontal***/
    printf("Testing plotHorizontal...\n");
    printf("Set start coordinate y: ");
    scanf("%d", &y1);

    printf("Set coordinate x1: ");
    scanf("%d", &x1);
    
    printf("Set coordinate x2: ");
    scanf("%d", &x2);
    
    clearScreen(base32);
    plotHorizontal(base32, y1 , x1 , x2);
    printf("Horizontal line plotted.\nPlease press Enter to continue.\n");
    getchar(); /* Wait for user input to continue*/
       
    /***Test clearScreen***/
    printf("Testing clearScreen...\n");
    clearScreen(base32);

    printf("Test program completed.\n");

    return 0;
}
