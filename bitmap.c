#include <linux/module.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/delay.h>
 
#define BIT_CNT 50
 
DECLARE_BITMAP(test_map, BIT_CNT) = {[0 ... BITS_TO_LONGS(BIT_CNT) - 1] = ~0};
 
static int __init test_init(void)
{
	int ret;
	int i;
	int arr_size = BITS_TO_LONGS(BIT_CNT);
	printk("BITS_TO_LONGS(%d): %d\n", BIT_CNT, BITS_TO_LONGS(BIT_CNT));
 
	printk("init\n");
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	printk("clear_bit(0, test_map)\n");
	clear_bit(0, test_map);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	printk("set_bit(0, test_map)\n");
	set_bit(0, test_map);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	printk("clear_bit(1, test_map)\n");
	clear_bit(1, test_map);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	ret = test_bit(1, test_map);
	printk("test_bit(1, test_map): %d\n", ret);
 
	printk("set_bit(1, test_map)\n");
	set_bit(1, test_map);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	ret = test_bit(1, test_map);
	printk("test_bit(1, test_map): %d\n", ret);
 
	ret = test_and_set_bit(5, test_map);
	printk("test_and_set_bit(5, test_map): %d\n", ret);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	ret = test_and_clear_bit(5, test_map);
	printk("test_and_clear_bit(5, test_map): %d\n", ret);
	for (i = 0; i < arr_size; i++) {
		printk("[%d], %08lx\n", i, test_map[i]);
	}
 
	return 0;
}
 
static void __exit test_exit(void)
{
 
}
 
module_init(test_init);
module_exit(test_exit);
MODULE_LICENSE("GPL");


