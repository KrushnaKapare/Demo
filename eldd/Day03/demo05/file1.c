// Initialisation code

#include<linux/module.h>
#include"file3.h"

static __init int desd_init(void)
{
	printk(KERN_INFO "%s : desd_init() is called\n", THIS_MODULE->name);
	my_function();
	my_var = 20;
	printk(KERN_INFO "%s : desd_init() is completed\n", THIS_MODULE->name);
	return 0;
}

module_init(desd_init);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("desd @ sunbeam");
MODULE_DESCRIPTION("This is split file demo");







