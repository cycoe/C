CC = tcc
CFLAGS = -Wall -O3
LDFLAGS =

SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}

all: server client

server: server.o wrap.o
	$(CC) server.o wrap.o -o server $(LDFLAGS)

client: client.o wrap.o
	$(CC) client.o wrap.o -o client $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean all
clean:
	rm $(OBJ) server client
