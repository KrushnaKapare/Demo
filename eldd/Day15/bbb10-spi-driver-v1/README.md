1. uEnv.txt
	- cape enabled
	- no overlays enabled
2. config pins to set spi0 pins to spi modes
3. basic driver -- `spi_new_device()` failed.
4. comment `spi_new_device()` i.e. no device creation from driver. use device created by default dtb/cape.
5. compile and load the driver (insmod)
6. unbind existing driver, driver_override, and bind spi0.0 to our driver. then probe() will be called.
7. unload driver (rmmod) -- calls remove().

---

probe() method sends a test byte (0xA5) on spi bus. if loopback wire is connected (`P9_18` to `P9_21`), then same data will be received. check kernel log.

