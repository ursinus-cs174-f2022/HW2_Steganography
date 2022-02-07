CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: grayscale noise randutils.o

randutils.o: randutils.cpp randutils.h
	$(CC) $(CFLAGS) -c randutils.cpp

grayscale: grayscale.cpp simplecanvas/SimpleCanvas.h
	$(CC) $(CFLAGS) -o grayscale grayscale.cpp

noise: noise.cpp randutils.o simplecanvas/SimpleCanvas.h
	$(CC) $(CFLAGS) -o noise randutils.o noise.cpp

clean:
	rm grayscale noise randutils.o