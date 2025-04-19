CC = gcc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/process.c src/scheduler.c src/utils.c
OBJ = $(SRC:.c=.o)
BIN = bin/probsched

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean:
	rm -f $(BIN) *.o
