#include<linux/module.h>
#include<linux/list.h>

struct student{
	char name[20];
	int rollno;
	int std;
	int marks;
	struct list_head slist;
};

struct list_head slist_head;


static __init int kernlist_init(void)
{
	struct student *ptr = NULL;

	printk(KERN_INFO "%s : kernlist_init() is called\n" , THIS_MODULE->name);
	
	// Initialise list head
	INIT_LIST_HEAD(&slist_head);

	// create student at runtime, initialise members of student and add it into list
	ptr = (struct student *)kmalloc(sizeof(struct student), GFP_KERNEL);
	strcpy(ptr->name, "abc");
	ptr->rollno = 12;
	ptr->std = 4;
	ptr->marks = 96;
	list_add(&ptr->slist, &slist_head);

	// create student at runtime, initialise members of student and add it into list
	ptr = (struct student *)kmalloc(sizeof(struct student), GFP_KERNEL);
	strcpy(ptr->name, "xyz");
	ptr->rollno = 14;
	ptr->std = 6;
	ptr->marks = 94;
	list_add(&ptr->slist, &slist_head);
	
	// create student at runtime, initialise members of student and add it into list
	ptr = (struct student *)kmalloc(sizeof(struct student), GFP_KERNEL);
	strcpy(ptr->name, "pqr");
	ptr->rollno = 11;
	ptr->std = 4;
	ptr->marks = 98;
	list_add_tail(&ptr->slist, &slist_head);
	
	printk(KERN_INFO "%s : Students list \n", THIS_MODULE->name);
	struct list_head *trav;
	list_for_each(trav, &slist_head)
	{
		ptr = list_entry(trav, struct student, slist);
		printk(KERN_INFO "%s : %s %d %d %d\n", THIS_MODULE->name, ptr->name, ptr->rollno, ptr->std, ptr->marks );
	}

	printk(KERN_INFO "%s : kernlist_init() is completed\n" , THIS_MODULE->name);
	return 0;
}


static __exit void kernlist_exit(void)
{
	struct list_head *trav, *next;

	printk(KERN_INFO "%s : kernlist_exit() is called\n" , THIS_MODULE->name);
		
	list_for_each_safe(trav, next, &slist_head)
	{
		list_del(trav);
	}

	printk(KERN_INFO "%s : kernlist_exit() is completed\n" , THIS_MODULE->name);
}

module_init(kernlist_init);
module_exit(kernlist_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("desd @ sunbeam");
MODULE_DESCRIPTION("This is kernel module to explore kernel LIST");

















