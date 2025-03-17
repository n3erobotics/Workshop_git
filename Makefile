CC = gcc
CFLAGS = -Wall -Wextra -Werror -ansi -pedantic
LINKS = -lm -pthread

SRCS=$(shell find $(DIR_SRC) -type f -name '*.c')
OBJS=$(patsubst %.c,%.o,$(SRCS))

bin: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	rm -f $(OBJS)
