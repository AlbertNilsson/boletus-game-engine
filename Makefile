CC = gcc
CLINKS = -lglfw -framework Cocoa -framework OpenGL -framework IOKIT
OBJS = objs/window.o objs/keyInput.o
HEADERS = headers/keyInput.h
EXE = magic-toad

magic-toad: $(HEADERS) $(OBJS)
	$(CC) $(OBJS) -o $(EXE) $(CLINKS)
objs/window.o: $(HEADERS) src/window.c src/keyInput.c
	$(CC) -o $@ -c src/window.c 
objs/keyInput.o: $(HEADERS) src/keyInput.c
	$(CC) -o $@ -c src/keyInput.c 


clean:
	$(RM) $(EXE) objs/*.o
