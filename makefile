CC  = gcc
FLG = -Werror -Isrc -I/usr/include/postgresql
LIB = -lpq
SRC = src/args.c src/blob.c src/date.c src/test.c main.c

blob:
	$(CC) $(SRC) $(FLG) $(LIB) -o $@.o

.PHONY: blob
