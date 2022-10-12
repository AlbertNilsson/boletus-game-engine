CC = gcc
CLINKS = -lglfw -framework Cocoa -framework OpenGL -framework IOKIT
SOURCE = src/window.c src/keyInput.c src/cursorInput.c
OBJS = objs/window.o objs/keyInput.o objs/cursorInput.o
HEADERS = headers/keyInput.h headers/cursorInput.h
EXE = boletus

boletus: $(HEADERS) $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(CLINKS)
objs/window.o: $(HEADERS) $(SOURCE)
	$(CC) -o $@ -c src/window.c 
objs/keyInput.o: $(HEADERS) src/keyInput.c
	$(CC) -o $@ -c src/keyInput.c 
objs/cursorInput.o: $(HEADERS) src/cursorInput.c
	$(CC) -o $@ -c src/cursorInput.c 

clean:
	$(RM) $(EXE) objs/*.o
