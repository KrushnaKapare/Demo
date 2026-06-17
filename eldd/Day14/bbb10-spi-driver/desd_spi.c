
/*
 * desd_spi.c - Minimal SPI test driver for BeagleBone Black (kernel 5.10)
 *
 * - Uses a custom modalias "desd-spi-dev" to avoid clashing with spidev
 * - Uses bus_num = 1 and chip_select = 1 (avoid CS0 used by BB-SPIDEV1 overlay)
 * - Probe performs a simple 1-byte transfer to test SPI link
 *
 * Build with the provided Makefile:
 *   make
 * Install:
 *   sudo insmod desd_spi.ko
 * (Ensure SPI overlay is loaded via u-boot or by copying dtbo to /boot/dtbs/<kernel-version>/overlays and rebooting)
 *
 * Test:
 *  - Check kernel logs: dmesg | tail -n 50
 *  - Check /sys/bus/spi/devices for spi1.1
 *
 */

#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

static struct spi_board_info spi_device_info = {
    .modalias = "desd-spi-dev", /* Custom name to bind to our driver */
    .max_speed_hz = 1000000,    /* 1 MHz for safe testing */
    .bus_num = 1,               /* SPI bus number (spi1) */
    .chip_select = 1,           /* Use CS1 to avoid overlay's CS0 */
    .mode = SPI_MODE_0,         /* SPI mode 0 */
};

static struct spi_device *spi_device;

/* Simple probe: perform a one-byte transfer to validate SPI link */
static int spi_device_probe(struct spi_device *spi)
{
    int ret;
    u8 tx = 0x5A;
    u8 rx = 0x00;
    struct spi_transfer t = {
        .tx_buf = &tx,
        .rx_buf = &rx,
        .len = 1,
        .cs_change = 0,
    };
    struct spi_message m;

    pr_info("desd-spi: probed device modalias=%s bus=%d cs=%d\n",
            spi->modalias, spi->master->bus_num, spi->chip_select);

    /* Configure basic SPI parameters */
    spi->mode = SPI_MODE_0;
    spi->bits_per_word = 8;
    spi->max_speed_hz = spi_device_info.max_speed_hz;

    ret = spi_setup(spi);
    if (ret)
    {
        pr_err("desd-spi: spi_setup failed: %d\n", ret);
        return ret;
    }

    spi_message_init(&m);
    spi_message_add_tail(&t, &m);

    /* Do a synchronous transfer (will return -EIO if controller/CS wrong) */
    ret = spi_sync(spi, &m);
    if (ret)
    {
        pr_err("desd-spi: spi_sync failed: %d\n", ret);
        /* Still return 0 so driver binds even if transfer fails; useful for debug */
        return 0;
    }

    pr_info("desd-spi: transfer OK, tx=0x%02x rx=0x%02x\n", tx, rx);

    /* Keep the spi pointer for potential later use (module exit cleanup) */
    spi_device = spi;

    // alloc device number
    // class create
    // device create
    // cdev init
    // cdev add

    return 0;
}

static int spi_device_remove(struct spi_device *spi)
{
    pr_info("desd-spi: removed device modalias=%s\n", spi->modalias);

    // clean up ... (4)

    /* If we had allocated resources (char device, buffers), free here. */
    if (spi_device == spi)
        spi_device = NULL;
    return 0;
}

static struct spi_device_id dev_id_table[] = {
    {"desd-spi-dev", 0},
    {},
};
MODULE_DEVICE_TABLE(spi, dev_id_table);

static struct spi_driver spi_device_driver = {
    .driver = {
        .name = "desd-spi-dev",
        .owner = THIS_MODULE,
    },
    .probe = spi_device_probe,
    .remove = spi_device_remove,
    .id_table = dev_id_table,
};

/* Kernel module init/exit: create spi device and register driver.
 * Sequence:
 *  - Find master by bus number
 *  - Create a spi_device with spi_new_device()
 *  - Register driver with spi_register_driver()
 *
 */

static int __init desd_spi_init(void)
{
    struct spi_master *master;
    int ret;

    pr_info("desd-spi: init\n");

    master = spi_busnum_to_master(spi_device_info.bus_num);
    if (!master)
    {
        pr_err("desd-spi: Failed to find SPI master %d\n", spi_device_info.bus_num);
        return -ENODEV;
    }

    spi_device = spi_new_device(master, &spi_device_info);
    if (!spi_device)
    {
        pr_err("desd-spi: Failed to create SPI device on bus %d cs %d\n",
               spi_device_info.bus_num, spi_device_info.chip_select);
        return -ENODEV;
    }

    /* Register the driver; if probe matches, our probe() will be called */
    ret = spi_register_driver(&spi_device_driver);
    if (ret < 0)
    {
        pr_err("desd-spi: Failed to register SPI driver: %d\n", ret);
        spi_unregister_device(spi_device);
        spi_device = NULL;
        return ret;
    }

    pr_info("desd-spi: device and driver registered\n");
    return 0;
}

static void __exit desd_spi_exit(void)
{
    pr_info("desd-spi: exit\n");
    spi_unregister_driver(&spi_device_driver);
    if (spi_device)
        spi_unregister_device(spi_device);
}

module_init(desd_spi_init);
module_exit(desd_spi_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sunbeam DESD");
MODULE_DESCRIPTION("Minimal SPI test driver (desd-spi-dev)");
