CC=gcc
INCLUDE = ./include
CFLAGS = -Wall -g -I$(INCLUDE)
LFLAGS = -pthread
BIN = webserver

src = $(wildcard *.c)
objs = $(patsubst %.c,%.o, $(src))


$(BIN): $(objs)
	$(CC) $(CFLAGS) $^ $(LFLAGS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o $(BIN)
