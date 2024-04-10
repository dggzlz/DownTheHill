#DTH_MAKEFILE
CC := cc68x
CCFLAGS := -g
ASLFLAGS := gen -D -L2

TARGET := tst
GAME_OBJS := rast_asm.o set_vid.o renderer.o splash.o raster.o s8_tst.o

all: $(GAME_OBJS) $(TARGET)

set_vid.o: set_vid.s
	$(ASLFLAGS) set_vid.s

rast_asm.o: rast_asm.s
	$(ASLFLAGS) rast_asm.s

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)

%.o : %.c
	$(CC) $(CCFLAGS) -c %<