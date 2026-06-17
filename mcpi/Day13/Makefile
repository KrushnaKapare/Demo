
GCC_BIN=

CC=$(GCC_BIN)arm-none-eabi-gcc
AS=$(GCC_BIN)arm-none-eabi-as
LD=$(GCC_BIN)arm-none-eabi-ld
NM=$(GCC_BIN)arm-none-eabi-nm
DB=$(GCC_BIN)arm-none-eabi-gdb
#DB=$(GCC_BIN)gdb-multiarch
OBJCOPY=$(GCC_BIN)arm-none-eabi-objcopy

TARGET=demo03
CPU=cortex-m4
STATE=thumb
DBG=dwarf2
# Debug Symbols Format for Embedded = warf2 or stabs
ARCH=armv7

EMU=qemu-system-arm
EMUMACH=netduinoplus2
EMUDBGPORT=1234

ASFLAGS=-mcpu=$(CPU) -march=$(ARCH) -m$(STATE) -g$(DBG)
LDFLAGS=-T./netduino.ld

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@ 

$(TARGET).elf: $(TARGET).o
	$(LD) $(LDFLAGS) -o $@ $<

$(TARGET).o: $(TARGET).s
	$(AS) $(ASFLAGS) -o $@ $<

run: $(TARGET).bin
	$(EMU) -machine $(EMUMACH) -cpu $(CPU) -S -d "in_asm,int,exec,cpu,guest_errors,unimp" -gdb tcp::$(EMUDBGPORT) -nographic -kernel $(TARGET).bin

debug: $(TARGET).elf
	$(DB) $(TARGET).elf -ex "target remote localhost:$(EMUDBGPORT)"

stop:
	taskkill /IM "qemu-system-arm.exe" /F

clean:
	rm -f $(TARGET).bin $(TARGET).elf $(TARGET).o

version:
	$(CC) -v

.PHONY: clean run debug version


