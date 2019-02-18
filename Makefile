SRCS = msg-counter.c dict.c
OBJS = $(SRCS:%.c=%.o)
CC = gcc
PROG = msg-counter
FILE = some_file

CFLAGS = -Wall -Wextra -Wmissing-prototypes --pedantic -std=c99
LDFLAGS = -lm

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

.PHONY: clean run

clean:
	$(RM) $(OBJS) $(PROG)

run: $(PROG)
	./$(PROG) $(FILE)

runwin: $(PROG)
	$(PROG).exe
