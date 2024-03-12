tst_rast: tstPsg.o psg.o music.o
	cc68x -g tstPsg.o psg.o  -o tstPsg

tstPsg.o: tstPsg.c music.h psg.h
	cc68x -g -c tstPsg.c

psg.o: psg.c psg.h
	cc68x -g -c psg.c

music.o: music.c music.h
	cc68x -g -c music.c


CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

model_objects := tstPsg.o psg.o music.o
model_exe := tstPsg

raster_tests : $(model_objects)
	$(CC) $(CCFLAGS) $^ -o $(model_exe)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#psg