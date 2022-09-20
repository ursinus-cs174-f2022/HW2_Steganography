CC=g++
CFLAGS=-std=c++11 -g -Wall 

all: art rgb2grayscale noise

randutils.o: randutils.cpp randutils.h
	$(CC) $(CFLAGS) -c randutils.cpp

rgb2grayscale: rgb2grayscale.cpp simplecanvas/SimpleCanvas.h
	$(CC) $(CFLAGS) -o rgb2grayscale rgb2grayscale.cpp

noise: noise.cpp randutils.o simplecanvas/SimpleCanvas.h
	$(CC) $(CFLAGS) -o noise randutils.o noise.cpp

ellipse.o: ellipse.cpp ellipse.h
	$(CC) $(CFLAGS) -c ellipse.cpp

art: ellipse.o art.cpp
	$(CC) $(CFLAGS) -o art art.cpp ellipse.o

clean:
	rm rgb2grayscale noise art randutils.o ellipse.o