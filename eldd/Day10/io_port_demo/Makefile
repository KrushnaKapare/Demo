
obj-m = io_port.o

io_port.ko: io_port.c
	make -C /lib/modules/$$(uname -r)/build M=$$(pwd) modules

clean:
	make -C /lib/modules/$$(uname -r)/build M=$$(pwd) clean

.PHONY : clean
