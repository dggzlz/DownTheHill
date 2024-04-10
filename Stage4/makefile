#DTH_MAKEFILE
CC := cc68x
CCFLAGS := -g

TARGET := tst_rend
GAME_OBJS := rast_asm.o raster.o renderer.o model.o events.o tst_rend.o

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)

rast_asm.o: rast_asm.s
	gen -D -L2 rast_asm.s

%.o : %.c
	$(CC) $(CCFLAGS) -c %<


