#include <linux/module.h>
#include <linux/init.h>
//#include <linux/sched.h>
#include <asm/current.h>

static int jknuckle_init(void) 
{
    printk(KERN_ALERT "Hello World from Jesse Knuckles (jknuckle)\n");
    return 0;
}
static void jknuckle_exit(void)
{
    printk(KERN_ALERT "PID is %d and program name is %s\n", current->pid, current->comm);
}
module_init(jknuckle_init);
module_exit(jknuckle_exit);
MODULE_LICENSE("Dual BSD/GPL");