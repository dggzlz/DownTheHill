#MODEL_MAKEFILE
CC := cc68x
CCFLAGS := -g

TARGET := tst_mod
MODEL_OBJS :=  rand.o model.o events.o tst_mod.o

$(TARGET) : $(MODEL_OBJS)
	$(CC) $(CCFLAGS) $^ -o $(TARGET)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<


