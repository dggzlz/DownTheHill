tst_rast: tst_rast.o raster.o rast_asm.o bitmaps.o
	cc68x -g tst_rast.o raster.o rast_asm.o bitmaps.o -o tst_rast

tst_rast.o: tst_rast.c raster.h 
	cc68x -g -c tst_rast.c

raster.o: raster.c raster.h 
	cc68x -g -c raster.c

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s

bitmaps.o: bitmaps.c bitmaps.h 
	cc68x -g -c bitmaps.c 

CC := cc68x
CCFLAGS := -g
AS := gen 
ASLFLAGS := -D -L2

raster_objects := tst_rast.o raster.o rast_asm.o bitmaps.o
raster_exe := tst_rast


raster_tests : $(raster_objects)
	$(CC) $(CCFLAGS) $^ -o $(raster_exe)
	
#%.o : %.c
#	$(CC) $(CCFLAGS) -c $<
        
#%.o	 : %.s
#	$(AS) $(ASLFLAGS) $< -o $@
        
#raster