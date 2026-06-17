
TARGET=demo01

CSRCS=$(TARGET).c
COBJS=$(CSRCS:.c=.o)

CC=gcc

CFLAGS=-m32 -Wall
LDFLAGS=-m32 -Wall -lm

$(TARGET): $(COBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)


.phony:	run clean











