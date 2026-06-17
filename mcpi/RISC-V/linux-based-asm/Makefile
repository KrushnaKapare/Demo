
AS=riscv64-linux-gnu-as
LD=riscv64-linux-gnu-ld
CC=riscv64-linux-gnu-gcc

PROGRAM=demo06
LDFLAGS=-static -lc

$(PROGRAM).out: $(PROGRAM).o
	$(CC) -g -o $@ $^ $(LDFLAGS)
#	$(LD) -g -o $@ $^ $(LDFLAGS)

$(PROGRAM).o: $(PROGRAM).s
	$(AS) $< -g -o $@

clean:
	rm -f $(PROGRAM).o $(PROGRAM).out

run: $(PROGRAM).out
	qemu-riscv64-static -g 1234 $(PROGRAM).out

debug: $(PROGRAM).out
	gdb-multiarch $(PROGRAM).out -ex "target remote :1234"

