#include<linux/module.h>

int init_module(void)
{
	printk(KERN_INFO "This is init_module() function\n");
	printk(KERN_INFO "hello world\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "This is cleanup_module() function\n");
	printk(KERN_INFO "bye world\n");
}

MODULE_INFO(license, "GPL");
MODULE_INFO(author, "DESD @ SUNBEAM");
MODULE_INFO(description, "This is our first kernel module");













