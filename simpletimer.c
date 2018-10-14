#include<linux/kernel.h>
#include<linux/timer.h>
#include<linux/module.h>
#include<linux/init.h>
#include <linux/jiffies.h>

static struct timer_list hellotimer;

void my_timer_handler(struct timer_list *unused)
{
 printk(KERN_INFO "my_timer_handler() has been called by kernel timer \n");
 add_timer(&hellotimer);
}


static int  __init my_init_module(void)
{
  
  timer_setup(&hellotimer, my_timer_handler,0);
  add_timer(&hellotimer);
  mod_timer(&hellotimer, jiffies + msecs_to_jiffies(100));
  return 0;
}


static void __exit my_exit_module(void)
{
  del_timer(&hellotimer);
  printk("Timer removed \n");
}


module_init(my_init_module);
module_exit(my_exit_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BoNian Lin");
