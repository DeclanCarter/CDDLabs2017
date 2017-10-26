
CC=g++
CFLAGS = -std=c++11 -pthread
HFILES = Semaphore.h
CFILES = Semaphore.cpp barrier.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)


SIMPLE: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o barrier

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: SIMPLE

CLEAN:
	rm *.o
