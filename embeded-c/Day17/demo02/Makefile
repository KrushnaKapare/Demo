
TARGET=demo02

CSRCS=$(TARGET).c
COBJS=$(CSRCS:.c=.o)

CC=gcc

CFLAGS=-m32 -Wall -ggdb3
LDFLAGS=-m32 -Wall -lm -ggdb3

$(TARGET): $(COBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)

debug:
	gdb ./$(TARGET)

.phony:	run clean debug











