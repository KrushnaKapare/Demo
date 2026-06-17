1. create a new dts overlay (compatible="desd,spi-demo") and compile it.
2. uEnv.txt
	- disable cape
	- enable overlay
3. in v1 driver code, add `of_device_id` table to match with DT and assoiciate with driver struct.
4. compile the driver and load it (insmod). probe() will be called.
5. remove the driver (rmmod). remove() will be called.

