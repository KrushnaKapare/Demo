- `desd_spi.c` — minimal SPI driver that:

  - Uses `.modalias = "desd-spi-dev"` and `.bus_num = 1`, `.chip_select = 1`
  - Creates a `spi_device` with `spi_new_device()` and registers a `spi_driver`
  - `probe()` calls `spi_setup()` and performs a single 1-byte `spi_sync()` transfer (prints RX)
  - Keeps minimal feature set so it's safe for initial testing

- `Makefile` — standard external kernel module Makefile.

---

# Steps to run

1. **Enable SPI overlay** (pick SPI1 because driver is configured for `bus_num = 1`):

   Edit `/boot/uEnv.txt`:

   ```bash
   enable_uboot_overlays=1
   uboot_overlay_addr1=BB-SPIDEV1-00A0.dtbo
   ```

   - Then **reboot** the BBB:

   ```bash
   sudo reboot
   ```

2. **After reboot verify SPI overlay loaded**

   ```bash
   dmesg | tail -n 40
   ls /sys/bus/spi/devices
   ls -l /dev/spidev*
   ```

   - You should see `spi1.0` (spidev overlay occupies CS0).
   - Our driver will create/search for `spi1.1` (CS1).

3. **Copy driver files to a working dir in BBB (scp) and build**

   ```bash
   make
   ```

   This produces `desd_spi.ko`.

4. **Load the module**

   ```bash
   sudo insmod desd_spi.ko
   dmesg | tail -n 40
   ```

   Watch kernel logs. Expect lines like:

   ```
   desd-spi: init
   desd-spi: device and driver registered
   desd-spi: probed device modalias=desd-spi-dev bus=1 cs=1
   desd-spi: transfer OK, tx=0x5a rx=0x??
   ```

   `rx` value depends on wiring (use loopback MOSI→MISO to get rx=0x5A).

5. **Verify device presence**

   ```bash
   ls /sys/bus/spi/devices
   # look for spi1.1 (our device)
   ```

6. **Testing physical loopback**

   - Wire MOSI → MISO, connect SCLK and GND. If CS1 pin isn't physically wired, you may need to assert CS manually via pinmux/gpio; simplest test is to use CS0 and adjust code accordingly — but we chose CS1 to avoid conflict with spidev created by the overlay.

   - If you instead want to use CS0 (and control the device only from your driver), disable the spidev overlay and set `.chip_select = 0`.

7. **Unload and cleanup**

   ```bash
   sudo rmmod desd_spi
   dmesg | tail -n 20
   ```

---

# Notes & caveats (must-read)

- **Chip-select wiring**: I used `chip_select = 1` to avoid conflict with the `BB-SPIDEV1` overlay which registers `spi1.0` (CS0). Make sure the physical CS1 pin is available and pinmuxed to SPI1_CS1. If not, either:

  - Use CS0 and disable the spidev overlay, or
  - Use a GPIO as chip-select in DT and controller config (more work).

- **Overlay choice**: I recommended `BB-SPIDEV1-00A0.dtbo`. If you prefer SPI0, change `bus_num = 0` and load `BB-SPIDEV0-00A0.dtbo`.

- **If `spi_sync()` fails** in probe, it's not fatal — driver binds and you can debug. Common reasons for failure:

  - CS not driven (no physical CS line),
  - Pinmux not configured for that CS,
  - Controller requires additional DT properties.

- **Production driver**: This module is a minimal test driver. For production:

  - Use `of_match_table` and DT node instead of `spi_new_device()` (i.e., rely on DT to register the `spi_device`).
  - Implement proper error handling, character device interface if you need a userspace node, and power/pm states.
