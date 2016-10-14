#include <linux/module.h> /*Need by all modules*/

int symbol_var = 56;
extern int symbol_fun(int);

int init_module(void) {
  printk(KERN_INFO "module_b inserts successfully\n");
  printk(KERN_INFO "symbol_var:%d\n",symbol_var);

  printk(KERN_INFO "symbol_function(56) = %d\n",symbol_fun(56));
  return 0;
}
void cleanup_module(void) {
  printk(KERN_INFO "module_b removes successfully\n");
}

EXPORT_SYMBOL(symbol_var);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("OSLAB");
MODULE_DESCRIPTION("OSLAB_MODULE");


