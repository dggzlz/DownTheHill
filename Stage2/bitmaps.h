#ifndef BITMAPS_H
#define BITMAPS_H

#include "types.h"
/*BITMAP ARRAYS*/

UINT32 heartLifeBM[32] =
{
       0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x00000000,
        0x03f00fc0,
        0x03f00fc0,
        0x0ffc3ff0,
        0x0ffc3ff0,
        0x3cfffffc,
        0x3cfffffc,
        0x3cfffffc,
        0x3cfffffc,
        0x33fffffc,
        0x33fffffc,
        0x3ffffffc,
        0x3ffffffc,
        0x0ffffff0,
        0x0ffffff0,
        0x03ffffc0,
        0x03ffffc0,
        0x00ffff00,
        0x00ffff00,
        0x003ffc00,
        0x003ffc00,
        0x000ff000,
        0x000ff000,
        0x0003c000,
        0x0003c000,
        0x00000000,
        0x00000000
};
        
UINT32 treeBM[128] = 
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
            
UINT32 RightSnowBoarder[128] =
    {
        0x0000000f, 0xf0000000,
        0x00000030, 0x0c000000,
        0x00000040, 0x02000000,
        0x00000080, 0x01000000,
        0x00000100, 0x00800000,
        0x0000013f, 0xfc800000,
        0x00000140, 0x02800000,
        0x00000197, 0xe9800000,
        0x00000137, 0x8c800000,
        0x00000177, 0xce800000,
        0x00000176, 0x6e800000,
        0x000001b5, 0xad800000,
        0x00000092, 0x49000000,
        0x000000e6, 0x67000000,
        0x00000058, 0x1be00000,
        0x000003e0, 0x06700000,
        0x00000760, 0x0c180000,
        0x00000db0, 0x0c080000,
        0x00001dbc, 0x3f0c0000,
        0x000071df, 0xfb070000,
        0x0000e1cf, 0xf3030000,
        0x000187ff, 0xe7198000,
        0x000337fd, 0xcf70c000,
        0x00061ffc, 0x1fa06000,
        0x000c0ffe, 0x3ff87000,
        0x001cef8f, 0xffff3000,
        0x001e7e0f, 0xf9fc1000,
        0x003b7c1e, 0x1c7d9800,
        0x007df038, 0x073f8800,
        0x00cfc3f0, 0x119e0800,
        0x00df87f0, 0xccdecc00,
        0x00fe0ff0, 0x667f0c00,
        0x00ee18f0, 0x37fe0c00,
        0x006c1971, 0xfffffc00,
        0x000019f0, 0xffff0c00,
        0x00001df6, 0x3ffbfc00,
        0x00001ff7, 0x9ff31c00,
        0x00001ff0, 0x9fc24c00,
        0x00001ff8, 0x0e03fc00,
        0x00000fff, 0x88037c00,
        0x00000ff8, 0x18013c00,
        0x03e007f0, 0x38007800,
        0x03f003ff, 0x0c007000,
        0x07fc03ff, 0xec000000,
        0x07fe03f0, 0x3c000000,
        0x03ff81ff, 0x0c000000,
        0x03ffe1df, 0xec000000,
        0x01fff1e9, 0xfc000000,
        0x01fffcd4, 0xfc000000,
        0x00ffff9e, 0xdb000000,
        0x007ffff1, 0xff000000,
        0x001ffffe, 0x1d000000,
        0x0003ffff, 0xf0800000,
        0x00000fff, 0xff800000,
        0x0000003f, 0xfffff800,
        0x00000001, 0xfffffe00,
        0x00000000, 0x07ffff00,
        0x00000000, 0x003fff00,
        0x00000000, 0x0001fc00,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000
    };
    
    UINT32 LeftSnowBoarder[128] =
    {
        0x0000000f, 0xf0000000,
        0x00000030, 0x0c000000,
        0x00000040, 0x02000000,
        0x00000080, 0x01000000,
        0x00000100, 0x00800000,
        0x0000013f, 0xfc800000,
        0x00000140, 0x02800000,
        0x00000197, 0xe9800000,
        0x00000131, 0xec800000,
        0x00000173, 0xee800000,
        0x00000176, 0x6e800000,
        0x000001b5, 0xad800000,
        0x00000092, 0x49000000,
        0x000000e6, 0x67000000,
        0x000007d8, 0x1a000000,
        0x00000e60, 0x07c00000,
        0x00001830, 0x06e00000,
        0x00001030, 0x0db00000,
        0x000030fc, 0x3db80000,
        0x0000e0df, 0xfb8e0000,
        0x0000c0cf, 0xf3870000,
        0x000198e7, 0xffe18000,
        0x00030ef3, 0xbfecc000,
        0x000605f8, 0x3ff86000,
        0x000e1ffc, 0x7ff03000,
        0x000cffff, 0xf1f73800,
        0x00083f9f, 0xf07e7800,
        0x0019be38, 0x783edc00,
        0x0011fce0, 0x1c0fbe00,
        0x00107988, 0x0fc3f300,
        0x00337b33, 0x0fe1fb00,
        0x0030fe66, 0x0ff07f00,
        0x00307fec, 0x0f187700,
        0x003fffff, 0x8e983600,
        0x0030ffff, 0x0f980000,
        0x003fdffc, 0x6fb80000,
        0x0038cff9, 0xeff80000,
        0x003243f9, 0x0ff80000,
        0x003fc070, 0x1ff80000,
        0x003ec011, 0xfff00000,
        0x003c8018, 0x1ff00000,
        0x001e001c, 0x0fe007c0,
        0x000e0030, 0xffc00fc0,
        0x00000037, 0xffc03fe0,
        0x0000003c, 0x0fc07fe0,
        0x00000030, 0xff81ffc0,
        0x00000037, 0xfb87ffc0,
        0x0000003f, 0x978fff80,
        0x0000003f, 0x2b3fff80,
        0x000000db, 0x79ffff00,
        0x000000ff, 0x8ffffe00,
        0x000000b8, 0x7ffff800,
        0x0000010f, 0xffffc000,
        0x000001ff, 0xfff00000,
        0x001fffff, 0xfc000000,
        0x007fffff, 0x80000000,
        0x00ffffe0, 0x00000000,
        0x00fffc00, 0x00000000,
        0x003f8000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000,
        0x00000000, 0x00000000
    };
        
UINT32 skierBM[128] = /* suggest adding detail since 64bit now*/
{
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 
        0x000001ff, 0xf8000000, 0x000001ff, 0xf8000000, 
        0x00000600, 0x04000000, 0x00000600, 0x02000000, 
        0x00000800, 0x01000000, 0x000033ff, 0xfcc00000, 
        0x000033ff, 0xfcc00000, 0x000033f0, 0xfcc00000, 
        0x000031f0, 0xf8c00000, 0x00003000, 0x00c00000, 
        0x00000c1f, 0xc1000000, 0x00000c1f, 0xc1000000, 
        0x00000200, 0x06000000, 0x00000200, 0x06000000, 
        0x00006dff, 0xf8000000, 0x00006dff, 0xf801b000, 
        0x000011ff, 0xf801b000, 0x00002d00, 0x08004000, 
        0x00004e00, 0x0400b000, 0x00008800, 0x02013000, 
        0x00011000, 0x01020000, 0x00022000, 0x00840000, 
        0x00044000, 0x00480000, 0x00048300, 0x18300000, 
        0x00050500, 0x14200000, 0x00060900, 0x12600000, 
        0x000c1100, 0x11e00000, 0x000e21ff, 0xf3c00000,
        0x000f41ff, 0xf3800000, 0x00078100, 0x10000000, 
        0x00038200, 0x10000000, 0x0000043f, 0x11800000, 
        0x000008c2, 0x23c00000, 0x00000984, 0x47c00000, 
        0x0000098c, 0xcf800000, 0x0000099c, 0xdf000000, 
        0x000004fc, 0xfe000000, 0x0000023c, 0x3c000000, 
        0x0000011a, 0x18000000, 0x00000199, 0x30000000, 
        0x00000332, 0x60000000, 0x00000366, 0xc0000000, 
        0x000007cf, 0x80000000, 0x00000f9f, 0x00000000, 
        0x00001f3e, 0x00000000, 0x00003e7c, 0x00000000, 
        0x00007cf8, 0x00000000, 0x0000f9f0, 0x00000000, 
        0x0001f3e0, 0x00000000, 0x0003e7c0, 0x00000000, 
        0x0007cf80, 0x00000000, 0x00079f00, 0x00000000, 
        0x00073e00, 0x00000000, 0x00003c00, 0x00000000, 
        0x00003800, 0x00000000, 0x00000000, 0x00000000, 
        0x00000000, 0x00000000, 0x00000000, 0x00000000, 
        0x00000000, 0x00000000, 0x00000000, 0x00000000 
};

UINT32 angel[128] =
{
    0x00003fff,
0xfffff800,
0x00002030,
0x00600800,
0x00003fff,
0xfffff800,
0x000000c0,
0x00300000,
0x00000180,
0x01d00000,
0x000003f0,
0xff580000,
0x00000f99,
0x00780000,
0x00003005,
0x00280000,
0x00006007,
0x00280000,
0x00004007,
0x08380000,
0x00006087,
0x003e0000,
0x0000200e,
0x00220000,
0x0000201a,
0x002a0000,
0x60002033,
0x007a0000,
0x1e001021,
0xffda0006,
0xe7c00fc0,
0x000a0078,
0x3ffb0640,
0x000607e7,
0x0fffc440,
0x003dfffc,
0x7fffe241,
0x0023fff0,
0x03fff247,
0x0047fffe,
0x1ffff23c,
0x00cfffc0,
0x3ffffa00,
0x008ffff8,
0x01ffff00,
0x119ffffc,
0x07ffff80,
0x333fffc0,
0x0cffff3f,
0xc27fffe0,
0x01ffff80,
0x07ffff30,
0x03fffff0,
0x1fffff80,
0x00ffffff,
0xffffff80,
0x00ffffff,
0xffffff00,
0x007fffff,
0xfffffe00,
0x001fffff,
0xfffffe00,
0x001fffff,
0xfffff800,
0x000ffff7,
0xeffff000,
0x0007ffe7,
0xe7ffe000,
0x0003ffc7,
0xe3ffc000,
0x0001ff87,
0xe1ff8000,
0x0000ff8f,
0xf1ff0000,
0x0000ff0f,
0xf1fe0000,
0x00003f0f,
0xf0fc0000,
0x00001e0f,
0xf0f80000,
0x0000041f,
0xf0700000,
0x0000001f,
0xf0000000,
0x0000001f,
0xf0000000,
0x0000001e,
0xf0000000,
0x0000001e,
0xf0000000,
0x0000000e,
0xf0000000,
0x0000000e,
0xf0000000,
0x0000000e,
0xe0000000,
0x0000000e,
0xe0000000,
0x0000000e,
0x60000000,
0x0000000e,
0x60000000,
0x00000006,
0x60000000,
0x00000006,
0x60000000,
0x00000003,
0x60000000,
0x00000003,
0x60000000,
0x00000001,
0x60000000,
0x00000001,
0xc0000000,
0x00000001,
0xc0000000,
0x00000000,
0xc0000000,
0x00000000,
0x40000000,
0x00000000,
0x60000000,
0x00000000,
0x60000000,
0x00000000,
0x60000000,
0x00000000,
0x60000000
};

/*NUMBERS*/

/*NumberOne*/
UINT16 numOne[16] =
{
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180,
	0x0180
};

/*NumberTwo*/
UINT16 numTwo[16] =
{
	0xffff,
	0xffff,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0xffff,
	0xffff,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xffff,
	0xffff
};

/*NumberThree*/
UINT16 numThree[16] =
{
	0xffff,
	0xffff,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x1fff,
	0x1fff,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0xffff,
	0xffff
};

/*NumberFour*/
UINT16 numFour[16] =
{
	0xe007,
	0xe007,
	0xe007,
	0xe007,
	0xe007,
	0xe007,
	0xe007,
	0xe007,
	0xffff,
	0xffff,
	0xffff,
	0x0007,
	0x007,
	0x0007,
	0x0007,
	0x0007
};

/*NumberFive*/
UINT16 numFive[16] =
{
	0xffff,
	0xffff,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xffff,
	0xffff,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0xffff,
	0xffff
};

/*NumberSix*/
UINT16 numSix[16] =
{
	0xffff,
	0xffff,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xc000,
	0xffff,
	0xffff,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xffff,
	0xffff
};

/*NumberSeven*/
UINT16 numSeven[16] =
{
	0xffff,
	0xffff,
	0xffff,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007,
	0x0007
};

/*NumberEight*/
UINT16 numEight[16] =
{
	0xffff,
	0xffff,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xffff,
	0xffff,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xffff,
	0xffff
};

/*NumberNine*/
UINT16 numNine[16] =
{
	0xffff,
	0xffff,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xc003,
	0xffff,
	0xffff,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003,
	0x0003
};


#endif