CC=gcc
target=main
CPPFLAGS=-I./
SRC=$(wildcard *.c)
objects=$(patsubst %.c,%.o,$(SRC))
$(target): $(objects)
	$(CC) -o $@ $^
%.o:%.c
	gcc -c $< $(CPPFLAGS)

.PHONY:clean
clean:
	rm -f $(objects) $(target)
