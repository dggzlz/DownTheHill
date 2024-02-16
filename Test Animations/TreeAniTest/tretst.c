#include <osbind.h>

typedef unsigned long UINT32;

typedef struct

{
    UINT32 bitmap[128];

} Bitmap64;

typedef struct
{
    Bitmap64 tree;
    unsigned int x,y;
    int upwardSpeed; 

} Tree;



void spawnTree(UINT32 *base);
void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height);
				  
void clearScreen(UINT32 *base);


main()
{
	
 UINT32 tree[128] = 
        { 
        0x0000000F, 0xF0000000,
        0x0000000F, 0xF0000000,
        0x0000000F, 0xF0000000,
        0x0000000F, 0xF0000000,
        0x000000FF, 0xFF000000,
        0x000000FF, 0xFF000000,
        0x000000FF, 0xFF000000,
        0x000000FF, 0xFF000000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x00000FFF, 0xFFF00000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x0000FFFF, 0xFFFF0000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x000FFFFF, 0xFFFFF000,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x00FFFFFF, 0xFFFFFF00,
        0x0FFFFFFF, 0xFFFFFFF0,
        0x0FFFFFFF, 0xFFFFFFF0,
        0x0FFFFFFF, 0xFFFFFFF0,
        0x0FFFFFFF, 0xFFFFFFF0,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000,
        0x000000F0, 0x0F000000
        };

	UINT32 *base = Physbase();
	int y = 340;
	
	while(y>0)
	{
	plotBitmap64(base,320,y,tree,128);
	y -= 10;
	clearScreen(base);
	}
	
	return 0;
	

}

/*

void spawnTree(UINT32 *base)
{
    Tree newTree = {tree,50,399,-5};
    plotBitMap64(base, newTree->x,newTree->y,newTree tree,128);
}
*/


void clearScreen(UINT32 *base) 
{       
    int i, j;

    for(j = 0; j < 400; j++){
        for(i = 0; i < 20; i++){
            *(base + (j * 20) + i) &= 0x00000000; /*instead of setting to zero could perform a clear mask*/
        }
   }
}





void plotBitmap64(UINT32 *base, 
                  int x, int y, 
                  const UINT32 *bitmap, 
                  unsigned int height)
{
    int i = 0;
    int offset = (20 * y + (x>>5));

    while (i < height){
        *(base + offset) = bitmap[i];
        *(base + (offset + 1)) = bitmap[i + 1];
        offset += 20;
        i+=2;
    }
}





