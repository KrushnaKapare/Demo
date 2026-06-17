
AS=riscv64-unknown-elf-as
LD=riscv64-unknown-elf-ld
CC=riscv64-unknown-elf-gcc
OBJCOPY=riscv64-unknown-elf-objcopy
#GDB=riscv64-unknown-elf-gdb
GDB=gdb-multiarch
QEMU=qemu-system-riscv64

PROGRAM=demo10
LDFLAGS=-T qemu-riscv64-virt.ld

$(PROGRAM).out: $(PROGRAM).o
	$(LD) $(LDFLAGS) -o $@ $^

$(PROGRAM).o: $(PROGRAM).s
	$(AS) $< -g -o $@

clean:
	rm -f $(PROGRAM).o $(PROGRAM).out

run: $(PROGRAM).out
	$(QEMU) -machine virt -s -S -nographic -kernel $(PROGRAM).out -bios none

stop:
	killall -q $$(echo $(QEMU) | cut -c1-15)

debug: $(PROGRAM).out
	$(GDB) $(PROGRAM).out -ex "target remote :1234"
