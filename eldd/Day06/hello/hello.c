#include <linux/module.h>

static int __init desd_init(void)
{
    pr_info("%s: desd_init() called.\n", THIS_MODULE->name);
    return 0;
}

static void __exit desd_exit(void)
{
    pr_info("%s: desd_exit() called.\n", THIS_MODULE->name);
}

module_init(desd_init);
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
MODULE_DESCRIPTION("Hello Kernel Module");
