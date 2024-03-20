#DTH_MAKEFILE
CC := cc68x
CCFLAGS := -g

TARGET := tst_game
GAME_OBJS :=  input.o dth.o

$(TARGET) : $(GAME_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<


