#DTH_MAKEFILE
CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

TARGET := DownHill.tos
GAME_OBJS := rast_asm.o raster.o splash.o renderer.o model.o input.o events.o dth.o music.o psg.o effects.o sync.o

all: $(GAME_OBJS) $(TARGET)

rast_asm.o: rast_asm.s
	$(ASLFLAGS) rast_asm.s

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)

%.o : %.c
	$(CC) $(CCFLAGS) -c %<
