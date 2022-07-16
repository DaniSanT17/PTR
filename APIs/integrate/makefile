PRJ=hello

CFLAGS=-Wall -I .
LFLAGS=-L .
LIBS=-lstdc++
CC=gcc

all: $(PRJ)

$(PRJ): main.c
	$(CC) $(CFLAGS) -o $(PRJ) main.c $(LFLAGS) $(LIBS)
	
.PHONY: clean run
	
clean: 
	@rm -f *.o $(PRJ)
	
run:
	./$(PRJ)
