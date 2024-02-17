CC := cc68x
CCFLAGS := -g

render_objects := s4tstdrv.o renderer.o model.o events.o raster.o
render_exe := tst_rend

render_tests : $(render_objects)
	$(CC) $(CCFLAGS) $^ -o $(render_exe)
	
%.o : %.c
	$(CC) $(CCFLAGS) -c %<
#render


