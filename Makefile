#----------------------------------------------------------------------------
#       Makefile
#----------------------------------------------------------------------------
CC=	gcc
AR=	ar
CFLAGS=	-c
LDFLAGS=
BIN=	probe
OBJ=	probe.o debug.o

all:$(BIN)

$(BIN):$(OBJ)
	$(CC) -o $@ $(OBJ)
probe.o:probe.c 
	$(CC) $(CFLAGS) probe.c
debug.o:debug.c
	$(CC) $(CFLAGS) debug.c
clean:
	rm -f *.o probe