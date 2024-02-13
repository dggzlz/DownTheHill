#include <osbind.h>
#include "raster.h"

int main()
{
    /*Different size bases to test each function respectevily*/
    char *base8 = Physbase();
    UINT16 *base16 = Physbase();
    UINT32 *base32 = Physbase();
    UINT64 *base64 = Physbase();


    plotPixel(base16, x, y);
    clearScreen(base32);

    plotHorizontal(base32, row);
    clearScreen(base32);

    plotVertical(base8, col);
    clearScreen(base32);

    plotHorizontal(base32, 383);
    clearScreen(base32);
    
    plotBitmap16(base16, 0, 0, invaderBitmap, bitMapsize16);
    clearScreen(base32);


	return 0;
}
