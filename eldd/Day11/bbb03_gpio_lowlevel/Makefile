obj-m := gpio_demo.o

KDIR := /home/nilesh/linux/linux/
PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules
#	above is command for cross compilation
# 	make -C /lib/modules/$(uname -r)/build M=$(PWD) modules
#	above is command for native compilation

clean:
	make -C $(KDIR) M=$(PWD) clean
# 	make -C /lib/modules/$(uname -r)/build M=$(PWD) clean

