tst_rend.o: tst_rend.c renderer.h 
	cc68x -g -c tst_rend.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s

model.o: model.c model.h
	cc68x -g -c model.c

events.o: events.c events.h
	cc68x -g -c events.c

renderer.o: renderer.c renderer.h
	cc68x -g -c renderer.c

tst_rend: tst_rend.o raster.o rast_asm.o renderer.o model.o events.o
	cc68x -g tst_rend.o raster.o rast_asm.o renderer.o model.o events.o -o tst_rend

CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

model_objects :=  tst_rend.o raster.o rast_asm.o render.o model.o events.o
model_exe := tst_rend

raster_tests : $(model_objects)
	$(CC) $(CCFLAGS) $^ -o $(model_exe)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#render


