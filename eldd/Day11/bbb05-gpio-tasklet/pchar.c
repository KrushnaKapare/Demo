#include <linux/module.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

#define LED_PIN 49
static int led_state;

#define SWITCH_PIN 115
static int switch_irq;

// global tasklet object
static struct tasklet_struct switch_tasklet;

// function declarations
static int pchar_open(struct inode *pinode, struct file *pfile);
static int pchar_close(struct inode *pinode, struct file *pfile);
static ssize_t pchar_write(struct file *pfile, const char __user *ubuf, size_t ubufsize, loff_t *poffset);
static ssize_t pchar_read(struct file *pfile, char __user *ubuf, size_t ubufsize, loff_t *poffset);

// global variables
#define MAX 32
static struct kfifo buffer;
static dev_t devno;
static struct class *pclass;
static struct cdev pchar_cdev;
static struct file_operations pchar_fops = {
    .owner = THIS_MODULE,
    .open = pchar_open,
    .release = pchar_close,
    .write = pchar_write,
    .read = pchar_read,
};

// switch -- bottom half
static void switch_tasklet_handler(unsigned long param)
{
    // work that cannot be done in top half -- non-sleeping code only
    // toggle the led
    led_state = !led_state;
    gpio_set_value(LED_PIN, led_state);
    pr_info("%s: switch tasklet - led toggled - %d\n", THIS_MODULE->name, led_state);
}

// switch isr -- top half
static irqreturn_t switch_isr(int irq, void *param)
{
    // time sensitive or hardware related or code not to preempted by the next interrupt on same line
    pr_info("%s: switch_isr() is called.\n", THIS_MODULE->name);
    // schdule the bottom half -- tasklet
    tasklet_schedule(&switch_tasklet);
    // return status
    return IRQ_HANDLED;
}

static int __init pchar_init(void)
{
    int ret;
    struct device *pdevice;
    pr_info("%s: pchar_init() called.\n", THIS_MODULE->name);
    // alloc device number
    ret = alloc_chrdev_region(&devno, 0, 1, "myled");
    if (ret < 0)
    {
        pr_err("%s: alloc_chrdev_region() failed.\n", THIS_MODULE->name);
        goto alloc_chrdev_region_failed;
    }
    // create device class
    pclass = class_create(THIS_MODULE, "myled_class");
    if (IS_ERR(pclass))
    {
        pr_err("%s: class_create() failed.\n", THIS_MODULE->name);
        ret = -1;
        goto class_create_failed;
    }
    // create device file
    pdevice = device_create(pclass, NULL, devno, NULL, "myled");
    if (IS_ERR(pdevice))
    {
        pr_err("%s: device_create() failed.\n", THIS_MODULE->name);
        ret = -1;
        goto device_create_failed;
    }
    // init cdev
    cdev_init(&pchar_cdev, &pchar_fops);
    // add cdev in kernel
    ret = cdev_add(&pchar_cdev, devno, 1);
    if (ret < 0)
    {
        pr_err("%s: cdev_add() failed.\n", THIS_MODULE->name);
        goto cdev_add_failed;
    }
    // alloc kfifo
    ret = kfifo_alloc(&buffer, MAX, GFP_KERNEL);
    if (ret != 0)
    {
        pr_err("%s: kfifo_alloc_add() failed.\n", THIS_MODULE->name);
        goto kfifo_alloc_failed;
    }
    // check if gpio led pin is valid
    ret = gpio_is_valid(LED_PIN);
    if (!ret)
    {
        ret = -1;
        pr_err("%s: gpio_is_valid() pin %d is invalid.\n", THIS_MODULE->name, LED_PIN);
        goto gpio_failed;
    }
    pr_info("%s: gpio_is_valid() pin %d is valid.\n", THIS_MODULE->name, LED_PIN);

    // request gpio pin
    ret = gpio_request(LED_PIN, "bbb-led");
    if (ret < 0)
    {
        pr_err("%s: gpio_request() pin %d is not avail.\n", THIS_MODULE->name, LED_PIN);
        goto gpio_failed;
    }
    pr_info("%s: gpio_request() pin %d is acquired.\n", THIS_MODULE->name, LED_PIN);

    // set gpio direction to output & initial led state to 0
    led_state = 0;
    ret = gpio_direction_output(LED_PIN, led_state);
    if (ret < 0)
    {
        pr_err("%s: gpio_direction_output() pin %d direction not set.\n", THIS_MODULE->name, LED_PIN);
        goto gpio_direction_failed;
    }
    pr_info("%s: gpio_direction_output() pin %d direction set to output.\n", THIS_MODULE->name, LED_PIN);

    // check if switch gpio is valid
    ret = gpio_is_valid(SWITCH_PIN);
    pr_info("%s: gpio_is_valid() pin %d is valid.\n", THIS_MODULE->name, SWITCH_PIN);
    // request switch gpio
    ret = gpio_request(SWITCH_PIN, "myswitch");
    pr_info("%s: gpio_request() pin %d.\n", THIS_MODULE->name, SWITCH_PIN);
    // set gpio direction to input
    ret = gpio_direction_input(SWITCH_PIN);
    pr_info("%s: gpio_direction_input() pin %d set as input.\n", THIS_MODULE->name, SWITCH_PIN);
    // get switch gpio interrupt number
    switch_irq = gpio_to_irq(SWITCH_PIN);
    pr_info("%s: gpio_to_irq() irq num for pin %d is %d.\n", THIS_MODULE->name, SWITCH_PIN, switch_irq);
    // register switch gpio isr
    ret = request_irq(switch_irq, switch_isr, IRQF_TRIGGER_RISING, "switch-irq", NULL);
    pr_info("%s: request_irq() registered isr for pin %d.\n", THIS_MODULE->name, SWITCH_PIN);

    // intialize switch tasklet
    tasklet_init(&switch_tasklet, switch_tasklet_handler, 0);
    pr_info("%s: tasklet_init() intialized switch tasklet.\n", THIS_MODULE->name);
    return 0;

gpio_direction_failed:
    gpio_free(LED_PIN);
gpio_failed:
    kfifo_free(&buffer);
kfifo_alloc_failed:
    cdev_del(&pchar_cdev);
cdev_add_failed:
    device_destroy(pclass, devno);
device_create_failed:
    class_destroy(pclass);
class_create_failed:
    unregister_chrdev_region(devno, 1);
alloc_chrdev_region_failed:
    return ret;
}

static void __exit pchar_exit(void)
{
    pr_info("%s: pchar_exit() called.\n", THIS_MODULE->name);
    // unregister isr
    free_irq(switch_irq, NULL);
    // free switch gpio
    gpio_free(SWITCH_PIN);
    // free gpio
    gpio_free(LED_PIN);
    pr_info("%s: gpio_free() released led gpio pin %d.\n", THIS_MODULE->name, LED_PIN);
    // free kfifo
    kfifo_free(&buffer);
    // delete cdev from kernel
    cdev_del(&pchar_cdev);
    // destroy device file
    device_destroy(pclass, devno);
    // destroy device class
    class_destroy(pclass);
    // release device number
    unregister_chrdev_region(devno, 1);
}

static int pchar_open(struct inode *pinode, struct file *pfile)
{
    pr_info("%s: pchar_open() called.\n", THIS_MODULE->name);
    return 0;
}

static int pchar_close(struct inode *pinode, struct file *pfile)
{
    pr_info("%s: pchar_close() called.\n", THIS_MODULE->name);
    return 0;
}

static ssize_t pchar_write(struct file *pfile, const char __user *ubuf, size_t ubufsize, loff_t *poffset)
{
    int ret;
    char kbuf[2] = "";
    pr_info("%s: pchar_write() called.\n", THIS_MODULE->name);
    ret = copy_from_user(kbuf, ubuf, 1);
    if (ret == 0)
    {
        if (kbuf[0] == '1')
        {
            led_state = 1;
            gpio_set_value(LED_PIN, led_state);
            pr_info("%s: pchar_write() - led pin %d ON.\n", THIS_MODULE->name, LED_PIN);
        }
        else
        {
            led_state = 0;
            gpio_set_value(LED_PIN, led_state);
            pr_info("%s: pchar_write() - led pin %d OFF.\n", THIS_MODULE->name, LED_PIN);
        }
    }
    return ubufsize;
}

static ssize_t pchar_read(struct file *pfile, char __user *ubuf, size_t ubufsize, loff_t *poffset)
{
    int ret;
    pr_info("%s: pchar_read() called.\n", THIS_MODULE->name);
    char kbuf[2] = "";
    if (led_state)
        strcpy(kbuf, "1");
    else
        strcpy(kbuf, "0");
    ret = copy_to_user(ubuf, kbuf, 2);
    return 2;
}

module_init(pchar_init);
module_exit(pchar_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nilesh Ghule <nilesh@sunbeaminfo.com>");
MODULE_DESCRIPTION("Simple Pseudo Char Device Driver using kfifo buffer");
