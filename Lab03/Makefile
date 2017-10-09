
CC=g++
CFLAGS = -std=c++11 -pthread
HFILES = Semaphore.h
CFILES = Semaphore.cpp Mutex.cpp

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

SIMPLE: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) -o Mutex $(CFILES)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: SIMPLE

CLEAN:
	rm *.o
