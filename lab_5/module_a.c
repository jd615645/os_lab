#include <linux/module.h>	/*Need by all modules*/


//int symbol_var = 99;
int symbol_fun(int x) {
	if(x > 100) {
		printk(KERN_INFO "Input: %d, Result: 1\n",x);
		return 1;
	}
	else if(x == 100) {
		printk(KERN_INFO "Input: %d, Result: 0\n",x);
		return 0;
	}
	else {
		printk(KERN_INFO "Input: %d, Result: -1\n",x);
		return -1;
	}
}

int init_module(void) {
	printk(KERN_INFO "module_a inserts successfully\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "module_a removes successfully\n");
}

//EXPORT_SYMBOL(symbol_var);
EXPORT_SYMBOL(symbol_fun);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");


