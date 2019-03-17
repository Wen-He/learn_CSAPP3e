CC = gcc
CFLAGS = -m64 -std=c99 -Og -pg
LIB = ./lib/vec.c

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))
PROGS_TEST = $(patsubst %.c,%.test,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIB)

test: $(PROGS_TEST)

%.test: %
	@touch $<.txt
	./$< $<.txt

.PHONY: clean
clean:
	-find . -type f -executable -print0 | xargs -0 rm
	-rm -f *.txt gmon.out

