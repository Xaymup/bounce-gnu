CC	   ?= gcc
LIBS	= -lcurses

all: bounce

bounce: src/bounce-gnu.c
	$(CC) $(CFLAGS) src/bounce-gnu.c -o bounce $(LIBS)

clean:
	rm -f bounce
