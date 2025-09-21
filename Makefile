CC = gcc
CFLAGS = -Wall -Wextra -g -I include
SRC = src/main.c src/compressor.c
OUT = file-compressor

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
