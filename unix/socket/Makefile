CC = tcc
CFLAGS = -Wall -O3
LDFLAGS =

SRC = $(wildcard *.c)
OBJ = ${SRC:.c=.o}
SERVER = server
CLIENT = client

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER).o
	$(CC) $(SERVER).o -o $(SERVER) $(LDFLAGS)

$(CLIENT): $(CLIENT).o
	$(CC) $(CLIENT).o -o $(CLIENT) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm $(OBJ) $(SERVER) $(CLIENT)
