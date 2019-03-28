CC=clang++
OBJS=client.o server.o

all: $(OBJS)
	$(CC) index.cpp $(OBJS) -o run
