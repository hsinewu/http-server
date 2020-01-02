CC=g++
CFLAGS=
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)

all: $(OBJS)
	$(CC) $(CFLAGS) -o http ./build/*.o

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o ./build/$@

install:
	cp ./systemd/service.sh /usr/bin/http
	cp ./systemd/http.service /etc/systemd/system/http.service

clean:
	rm run build/*
