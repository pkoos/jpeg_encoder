.PHONY: clean

CC=gcc
CFLAGS=-I.
DEPS = file_header.h file_footer.h
OBJ = file_header.o file_footer.o
WFLAGS = -Wall -Wextra

jpeg_encoder: main.o $(OBJ)
	$(CC) $(WFLAGS) -g -o $@ $^

main.o: main.c
	$(CC) $(WFLAGS) -g -c $<

%.o: %.c
	$(CC) $(WFLAGS) -g -c -o $@ $<

clean:
	rm -f jpeg_encoder *.o