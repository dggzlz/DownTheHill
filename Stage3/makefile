CC := cc68x
CCFLAGS := -g

model_objects := tst_mod.o model.o events.o
model_exe := tst_mod

model_tests : $(model_objects)
	$(CC) $(CCFLAGS) $^ -o $(model_exe)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#model


