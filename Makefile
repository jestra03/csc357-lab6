CC = gcc
CFLAGS = -Wall -std=c99 -pedantic
MAIN = evens
OBJS = evens.o

all : $(MAIN)

$(MAIN) : $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

evens.o : evens.c
	$(CC) $(CFLAGS) -c evens.c

clean :
	rm *.o $(MAIN) core
