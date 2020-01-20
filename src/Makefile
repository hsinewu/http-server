CC=g++
CFLAGS=-std=c++11
BUILD_FOLDER=../build
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) -o ../http $(BUILD_FOLDER)/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(BUILD_FOLDER)/$@
