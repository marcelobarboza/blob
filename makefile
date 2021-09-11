CC      = gcc
CFLAGS  = -Werror
INCLUDE = -Isrc -I/usr/include/postgresql
LIBS    = -lpq
SOURCES = src/args.c src/blob.c src/date.c src/test.c main.c

blob:
	$(CC) $(SOURCES) $(CFLAGS) $(INCLUDE) $(LIBS) -o $@

.PHONY: blob
