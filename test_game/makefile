CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

TARGET := main
GAME_OBJS := rast_asm.o raster.o  renderer.o model.o events.o input.o dth.o

all: $(GAME_OBJS_OBJS) $(TARGET)

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)
	
rast_asm.o : rast_asm.s
	$(ASLFLAGS) rast_asm.s
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#render


