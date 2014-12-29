#----------------------------------------------------------------------------
#       Makefile
#----------------------------------------------------------------------------
CC=	gcc
AR=	ar
CFLAGS=	-c
LDFLAGS=
BIN=	main
OBJ=	main.o debug.o

all:$(BIN)

$(BIN):$(OBJ)
	$(CC) -o $@ $(OBJ)
probe.o:main.c 
	$(CC) $(CFLAGS) main.c
debug.o:debug.c
	$(CC) $(CFLAGS) debug.c
clean:
	rm -f *.o main
