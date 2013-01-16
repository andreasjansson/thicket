CC = g++
CFLAGS = -g -c -O9
LDFLAGS = -lsndfile
OBJS = thicket.o agent.o inputaudio.o outputaudio.o

all: thicket

thicket: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o thicket

thicket.o: thicket.cpp agent.hpp inputaudio.hpp outputaudio.hpp
	$(CC) $(CFLAGS) thicket.cpp

agent.o: agent.cpp agent.hpp
	$(CC) $(CFLAGS) agent.cpp

inputaudio.o: inputaudio.cpp inputaudio.hpp
	$(CC) $(CFLAGS) inputaudio.cpp

outputaudio.o: outputaudio.cpp outputaudio.hpp
	$(CC) $(CFLAGS) outputaudio.cpp

clean:
	rm *.o thicket