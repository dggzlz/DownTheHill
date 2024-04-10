#DTH_MAKEFILE
CC := cc68x
CCFLAGS := -g

TARGET := tst_game
GAME_OBJS := rast_asm.o raster.o renderer.o model.o input.o events.o sync.o dth.o 

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s

%.o : %.c
	$(CC) $(CCFLAGS) -c %<


