#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/config.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <asm/uaccess.h>

int init_module_func(void)
{
	printk("<1>Hello,world\n");
	return 0;
}
void cleanup_module_func(void)
{
	printk("<1>Goodbye cruel world\n");
}
module_init(init_module_func);
module_exit(cleanup_module_func);
MODULE_LICENSE("GPL");
