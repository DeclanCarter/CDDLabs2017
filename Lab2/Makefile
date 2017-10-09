
CC=g++
CFLAGS = -std=c++11 -pthread
HFILES = Semaphore.h
CFILES = Semaphore.cpp Rendezvous.cpp

SIMPLE: $(CFILES) $(HFILES)
	$(CC) $(CFLAGS) *.cpp -o Rendezvous

CLEAN:
	rm *.o
