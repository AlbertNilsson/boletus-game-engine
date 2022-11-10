CC = gcc
CLINKS = -lglfw -framework Cocoa -framework OpenGL -framework IOKIT
SOURCE = src/*.c src/util/time.c
HEADERS = src/include/keyInput.h src/include/cursorInput.h src/include/scene.h src/util/include/time.h src/include/cursorInput.h
OBJS = objs/keyInput.o objs/scene.o objs/time.o objs/window.o objs/cursorInput.o
EXE = boletus


boletus: $(HEADERS) $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(CLINKS)

objs/window.o: $(HEADERS) $(SOURCE)
	$(CC) -o $@ -c src/window.c 
objs/keyInput.o: $(HEADERS) src/keyInput.c
	$(CC) -o $@ -c src/keyInput.c 
objs/cursorInput.o: $(HEADERS) src/keyInput.c
	$(CC) -o $@ -c src/cursorInput.c 
objs/scene.o: $(HEADERS) src/scene.c
	$(CC) -o $@ -c  src/scene.c 
objs/time.o: $(HEADERS) src/util/time.c
	$(CC) -o $@ -c  src/util/time.c 

clean:
	$(RM) $(EXE) objs/*.o

