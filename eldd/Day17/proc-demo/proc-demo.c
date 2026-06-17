#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

static int test_arr[] = {11, 22, 33, 44, 55};

static void *desd_seq_start(struct seq_file *m, loff_t *pos)
{
    // return addr of the data to be displayed first
    pr_info("%s: desd_seq_start() called - pos=%lld.\n", THIS_MODULE->name, *pos);
    if (*pos == 5) // already reached to end (called after stop)
        return NULL;
    return &test_arr[*pos]; // *pos will be 0 at the start.
}

static int desd_seq_show(struct seq_file *m, void *v)
{
    int *ptr = (int *)v;
    // return num of chars written in seq file for display
    pr_info("%s: desd_seq_show() called - data=%p.\n", THIS_MODULE->name, v);
    seq_printf(m, "elem at %ld index is %d.\n", ptr - test_arr, *ptr);
    return 0;
}

static void *desd_seq_next(struct seq_file *m, void *v, loff_t *pos)
{
    (*pos)++; // go next pos
    // return addr of next data to be displayed
    pr_info("%s: desd_seq_next() called - pos=%lld.\n", THIS_MODULE->name, *pos);
    if (*pos == 5)          // end of array data
        return NULL;        // NULL represent end of data is reached
    return &test_arr[*pos]; // *pos will be next elem index.
}

static void desd_seq_stop(struct seq_file *m, void *v)
{
    // clean up code for seq file (if any)
    pr_info("%s: desd_seq_stop() called.\n", THIS_MODULE->name);
}

static struct seq_operations desd_seq_ops = {
    .start = desd_seq_start,
    .show = desd_seq_show,
    .next = desd_seq_next,
    .stop = desd_seq_stop,
};

static int desd_proc_open(struct inode *pinode, struct file *pfile)
{
    int ret = seq_open(pfile, &desd_seq_ops); // built-in seq file operation
    pr_info("%s: desd_proc_open() called with ret=%d.\n", THIS_MODULE->name, ret);
    return 0;
}

static struct proc_ops desd_proc_ops = {
    .proc_open = desd_proc_open, // user-defined wrapper on seq file operation
    .proc_read = seq_read,       // built-in seq file operation
    .proc_release = seq_release, // built-in seq file operation
};

static struct proc_dir_entry *desd_dentry;

static int __init proc_ex_init(void)
{
    pr_info("%s: proc_ex_init() called.\n", THIS_MODULE->name);
    desd_dentry = proc_create("desd", 0444, NULL, &desd_proc_ops);
    pr_info("%s: proc_create() called.\n", THIS_MODULE->name);
    return 0;
}

static void __exit proc_ex_exit(void)
{
    pr_info("%s: proc_ex_exit() called.\n", THIS_MODULE->name);
    // proc_remove(desd_dentry);
    remove_proc_entry("desd", NULL);
}

module_init(proc_ex_init);
module_exit(proc_ex_exit);

MODULE_LICENSE("GPL");
