#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	unsigned short x1, unsigned short y1,
               unsigned short x2, unsigned short y2,
               short style, short mode
	plot_line(unsigned short x1, unsigned short y1,
               unsigned short x2, unsigned short y2,
               short style, short mode);


	return 0;
}
