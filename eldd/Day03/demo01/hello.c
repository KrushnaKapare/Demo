#include<linux/module.h>

// #define KERN_INFO "6"

// init_module() function will be called at the time of insmod

int init_module(void)
{
	printk(KERN_INFO "inside init_module() function\n");
	printk(KERN_INFO "Hello world\n");
	return 0;
}

// cleanup_module() function will be called at the time of rmmod

void cleanup_module(void)
{
	printk(KERN_INFO "inside cleanup_module() function\n");
	printk(KERN_INFO "Bye world\n");

}

// License - GPL or BSD or Dual BSD/GPL
MODULE_INFO(license, "GPL");
MODULE_INFO(author, "desd @ sunbeam");
MODULE_INFO(description, "This is hello Module");

// MODULE_INFO() macro adds one section with name .modinfo in kernel object
//	this info can be seen with the help of modinfo command







