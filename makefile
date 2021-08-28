CC = gcc

blob: src/date.c src/blob.c src/args.c src/test.c main.c
	$(CC) -o $@.o $^ -Isrc -I/usr/include/postgresql -lpq -Werror

odt:
	pandoc -f markdown -t odt -o README.odt README.md
	lowriter README.odt

.PHONY: blob odt
