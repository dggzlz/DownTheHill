
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
        0x0ffc3f30,
        0x0ffc3f30,
        0x3cfff03c,
        0x3cfff03c,
        0x3cffc00c,
        0x3cffc00c,
        0x33ffff3c,
        0x33ffff3c,
        0x3fffff3c,
        0x3fffff3c,
        0x0ffffcf0,
        0x0ffffcf0,
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
            
UINT32 snowboarderBM[128] = /* still need to edit bitmap*/
{     
        0x000001FF, 0x00000000,
        0x00000FFF, 0xE0000000,
        0x00007FFF, 0xFE000000,
        0x00006000, 0x06000000,
        0x00018000, 0x01800000,
        0x00018000, 0x01800000,
        0x001E0000, 0x00780000,
        0x001E0000, 0x00780000,
        0x00787FFF, 0xFF9E0000,
        0x00787FFF, 0xFF9E0000,
        0x0079D000, 0x01FE0000,
        0x0079D000, 0x01FE0000,
        0x006799FF, 0xD67E0000,
        0x006799FF, 0xD67E0000,
        0x007D79FD, 0x079E0000,
        0x007D79FD, 0x079E0030,
        0x001E79FF, 0x87980078,
        0x001E79FF, 0x87983078,
        0x001E79E7, 0xE7987878,
        0x001E79E7, 0xE7985878,
        0x001F9999, 0xE6785868,
        0x001F9999, 0xE6785868,
        0x0067E066, 0x01E65C68,
        0x0067E066, 0x01E64C48,
        0x0061FF81, 0xFF866C58,
        0x0061FF81, 0xFF8666D8,
        0x01987800, 0x1E1836D8,
        0x01987800, 0x1E1837FC,
        0x06061E00, 0x78783FCA,
        0x0E061E00, 0x787CFF89,
        0x18018781, 0xE186FF89,
        0x18018781, 0xE187F199,
        0x104079FF, 0x9E01C191,
        0x104079FF, 0x9E058BF3,
        0x10C01800, 0x180C8FE6,
        0x10C01800, 0x1A18FFFE,
        0x11B007FF, 0xE230FFFC,
        0x119C0082, 0x03E0FFFC,
        0x118200C2, 0x01C07FFC,
        0x19810042, 0x00003FFC,
        0x19818042, 0x01821FF4,
        0x0900C063, 0x03C30004,
        0x09006000, 0x0671800C,
        0x0F003DE7, 0x8418C3F8,
        0x0F0007C3, 0xF80E3E00,
        0x060001C3, 0x8003E000,
        0x000001C3, 0x80000000,
        0x000001C3, 0x80000000,
        0x00000199, 0x80000000,
        0x00000199, 0x80000000,
        0x00000799, 0xE0000000,
        0x00000799, 0xE0000000,
        0x00000618, 0x60000000,
        0x00000618, 0x60000000,
        0x000007FF, 0xE0000000,
        0x000007FF, 0xE0000000,
        0x000007FF, 0xE0000000,
        0x000007FF, 0xE0000000,
        0x000007FF, 0xE0000000,
        0x000007FF, 0xE0000000,
        0x000001FF, 0x80000000,
        0x000001FF, 0x80000000,
        0x0000007E, 0x00000000,    
        0x0000007E, 0x00000000   		
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



#endif