dth: dth.o raster.o rast_asm.o input.o model.o events.o renderer.o 
	cc68x -g dth.o raster.o rast_asm.o input.o model.o events.o renderer.o -o dth

raster.o: raster.c raster.h
	cc68x -g -c raster.c

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s

input.o: input.c input.h bool.h
	cc68x -g -c input.c

model.o: model.c model.h
	cc68x -g -c model.c

events.o: events.c events.h 
	cc68x -g -c events.c

renderer.o: renderer.c renderer.h
	cc68x -g -c renderer.c
        
dth.o: dth.c types.h input.h
	cc68x -g -c dth.c
        

CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

model_objects := dth.o raster.o rast_asm.o input.o model.o events.o renderer.o 
model_exe := dth

animation_tests : $(model_objects)
	$(CC) $(CCFLAGS) $^ -o $(model_exe)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#animate

