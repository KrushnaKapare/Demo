// io-port demo for x86 arch
#include <linux/module.h>
#include <linux/ioport.h>
#include <linux/io.h>

#define DUMMY_PORT 0x78

static int __init io_port_init(void) {
    struct resource *res;
    u8 val;

    pr_info("%s: io_port_init() called.\n", THIS_MODULE->name);
    res = request_region(DUMMY_PORT, 1, "dummy");
    if(IS_ERR_OR_NULL(res)) {
        pr_err("%s: request_region() failed.\n", THIS_MODULE->name);
        return -1;
    }
    pr_info("%s: allocated io port 0x%x.\n", THIS_MODULE->name, DUMMY_PORT);

    val = 0xAB; // some value for testing
    outb(val, DUMMY_PORT);
    pr_info("%s: written value 0x%x on port 0x%x.\n", THIS_MODULE->name, val, DUMMY_PORT);

    val = inb(DUMMY_PORT);
    pr_info("%s: read value 0x%x from port 0x%x.\n", THIS_MODULE->name, val, DUMMY_PORT);
    return 0;
}

static void __exit io_port_exit(void) {
    pr_info("%s: io_port_exit() called.\n", THIS_MODULE->name);
    release_region(DUMMY_PORT, 1);
    pr_info("%s: released io port 0x%x.\n", THIS_MODULE->name, DUMMY_PORT);
}

module_init(io_port_init);
module_exit(io_port_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple IO port demo.");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
