#include<linux/module.h>


// gcc attributes
// __init	-->		__attribute__((section(.init.text)))

// this attribute creates one seperate section with name .init.text
// code of initialisation is added into this section
// so that this section will be removed after initialisation of this module

static __init int desd_init(void)
{
	printk(KERN_INFO "This is desd_init() function\n");
	printk(KERN_INFO "Welcome to Kernel module programming\n");
	return 0;
}

// __exit	-->		__attribute__((section(.exit.text)))

// this attribute creates one seperate section with name .exit.text
// code of deinitialisation is added into this section
// this section will be removed after deinitialisation of this module along with all other sections
static __exit void desd_exit(void)
{
	printk(KERN_INFO "This is desd_exit() function\n");
}

// this function is used to mark desd_init as code of initialisation
// internally it adds wrapper with name init_module on our function
module_init(desd_init);

// this function is used to mark desd_exit as code of deinitialisation
// internally it adds wrapper with name cleanup_module on our function
module_exit(desd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("desd @ sunbeam");
MODULE_DESCRIPTION("This is kernel module with user defined entry point function");


// internal MODULE_XYZ() macro expands to MODULE_INFO() macro

// static keyword is used to restrict access of variables and functions with a file
// here our entry point functions should not be called by some another mdoule











