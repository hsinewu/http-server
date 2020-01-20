CC=g++
CFLAGS=
BUILD_FOLDER=../build
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) -o ../http $(BUILD_FOLDER)/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(BUILD_FOLDER)/$@
