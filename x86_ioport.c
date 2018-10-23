#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/ioport.h>
#include <asm/io.h>

#define BASE 0xe000
#define SIZE 0x08


static int __init test_init(void)
{
   int var;

   if (!request_region(BASE, SIZE, "mydev")) {

    printk(KERN_INFO "unable to get io port at 0x%8X\n", BASE );

    return -ENODEV;

  }

  var = inl(BASE);
  printk( KERN_INFO "read %d\n", var );

  outl(0, BASE);
  var = inl(BASE);
  printk( KERN_INFO "read %d\n", var );
  return 0;
}


static void __exit test_exit(void)
{

 release_region(BASE, SIZE);

}

module_init(test_init);
module_exit(test_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("BoNian Lin");

