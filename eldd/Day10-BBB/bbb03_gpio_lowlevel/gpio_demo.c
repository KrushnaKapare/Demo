// io memory demo for beaglebone black
#include <linux/module.h>
#include <linux/io.h>
#include <linux/delay.h>

#define GPIO1_BASE_ADDR 0x4804C000 // Base address of GPIO1
#define GPIO_OE 0x134              // Offset for Output Enable register
#define GPIO_SETDATAOUT 0x194      // Offset for Set Data Output register
#define GPIO_CLEARDATAOUT 0x190    // Offset for Clear Data Output register
#define GPIO_PIN (1 << 16)         // GPIO1_16 (P9.15 pin - BBB pinout diagram)

void __iomem *gpio_base; // MMIO base address pointer

static int __init gpio_driver_init(void)
{
    int i;
    // request_mem_region() -- doesn't work well with bbb-gpio
    //  because those addresses are owned by vendor given producer driver.

    // Map the physical address to a virtual address
    gpio_base = ioremap(GPIO1_BASE_ADDR, 0x1000);
    if (!gpio_base)
    {
        pr_err("Failed to ioremap GPIO1_BASE_ADDR\n");
        return -ENOMEM;
    }

    // Configure GPIO1_16 as an output
    u32 oe_reg = ioread32(gpio_base + GPIO_OE);
    oe_reg &= ~GPIO_PIN; // Clear the bit to set as output
    iowrite32(oe_reg, gpio_base + GPIO_OE);

    for (i = 1; i <= 10; i++)
    {
        // Turn on the GPIO1_16 pin
        iowrite32(GPIO_PIN, gpio_base + GPIO_SETDATAOUT);
        pr_info("GPIO1_16 is set HIGH (LED ON)\n");
        // delay
        msleep(500);
        // Turn off the GPIO1_16 pin
        iowrite32(GPIO_PIN, gpio_base + GPIO_CLEARDATAOUT);
        pr_info("GPIO1_16 is set LOW (LED OFF)\n");
        // delay
        msleep(500);
    }
    return 0;
}

static void __exit gpio_driver_exit(void)
{
    // Turn off the GPIO1_16 pin
    iowrite32(GPIO_PIN, gpio_base + GPIO_CLEARDATAOUT);
    pr_info("GPIO1_16 is set LOW (LED OFF)\n");

    // Unmap the memory region
    iounmap(gpio_base);

    // release_mem_region();
}

module_init(gpio_driver_init);
module_exit(gpio_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nilesh Ghule");
MODULE_DESCRIPTION("Simple GPIO driver using ioread32() and iowrite32()");
