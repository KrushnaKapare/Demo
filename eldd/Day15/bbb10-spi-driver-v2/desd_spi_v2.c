
#include <linux/module.h>
#include <linux/spi/spi.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/slab.h>

static struct spi_device *spi_device;

static int spi_device_probe(struct spi_device *spi)
{
    int ret;
    u8 tx = 0xA5, rx = 0x00;

    struct spi_transfer t = {
        .tx_buf = &tx,
        .rx_buf = &rx,
        .len = 1,
    };

    struct spi_message m;

    pr_info("desd-spi: probe: bus=%d cs=%d\n",
            spi->master->bus_num, spi->chip_select);

    spi->mode = SPI_MODE_0;
    spi->bits_per_word = 8;
    spi->max_speed_hz = 1000000;

    ret = spi_setup(spi);
    if (ret)
    {
        pr_err("desd-spi: spi_setup failed: %d\n", ret);
        return ret;
    }

    spi_message_init(&m);
    spi_message_add_tail(&t, &m);

    ret = spi_sync(spi, &m);
    if (ret)
        pr_err("desd-spi: spi_sync failed (%d)\n", ret);
    else
        pr_info("desd-spi: OK tx=0x%02X rx=0x%02X\n", tx, rx);

    spi_device = spi;
    return 0;
}

static int spi_device_remove(struct spi_device *spi)
{
    pr_info("desd-spi: remove\n");
    if (spi_device == spi)
        spi_device = NULL;
    return 0;
}

static struct spi_device_id desd_ids[] = {
    {"desd,spi-demo", 0},
    {}};
MODULE_DEVICE_TABLE(spi, desd_ids);

static const struct of_device_id spi_demo_of_match[] = {
    { .compatible = "desd,spi-demo" },
    { }
};
MODULE_DEVICE_TABLE(of, spi_demo_of_match);

static struct spi_driver desd_driver = {
    .driver = {
        .name = "desd-spi-dev",
        .owner = THIS_MODULE,
		.of_match_table = spi_demo_of_match,
    },
    .probe = spi_device_probe,
    .remove = spi_device_remove,
    .id_table = desd_ids,
};

static int __init desd_spi_init(void)
{
    //struct spi_master *master;
    int ret;

    pr_info("desd-spi: init\n");

    ret = spi_register_driver(&desd_driver);
    if (ret)
    {
        spi_unregister_device(spi_device);
        pr_err("desd-spi: driver reg failed\n");
        return ret;
    }

    return 0;
}

static void __exit desd_spi_exit(void)
{
    pr_info("desd-spi: exit\n");
    spi_unregister_driver(&desd_driver);
}

module_init(desd_spi_init);
module_exit(desd_spi_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sunbeam DESD");
MODULE_DESCRIPTION("Minimal SPI test driver");

