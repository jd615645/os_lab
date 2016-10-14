#include <linux/module.h>	/*Need by all modules*/


int symbol_var = 99;
int symbol_fun(int x)
{
	if(x > 0){
		return 1;
	} else if(x == 0){
		return 0;
	} else{
		return -1;
	}
}

int init_module(void)
{
	printk(KERN_INFO "Module_A inserts successfully\n");
	return 0;
}
void cleanup_module(void)
{
	printk(KERN_INFO "Module_A removes successfully\n");
}

EXPORT_SYMBOL(symbol_var);
EXPORT_SYMBOL(symbol_fun);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");


