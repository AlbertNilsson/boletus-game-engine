CC=gcc
CFLAGS=-lglfw -lGLEW -framework OpenGL 
EXE=triangle


boletus: files.h window.o files.o
	$(CC) window.o files.o -o $(EXE) $(CFLAGS)
window.o: window.c
	$(CC) -o $@ -c window.c 
files.o: files.h files.c
	$(CC) -o $@ -c files.c 

clean:
	rm window.o files.o $(EXE)
