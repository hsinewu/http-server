CC=clang++
CFLAGS=
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) -o run ./build/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o ./build/$@

clean:
	rm run build/*
