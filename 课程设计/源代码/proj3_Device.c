#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <asm/uaccess.h>
#include <linux/device.h>

static int Devnumber;//设备驱动号
static char message[128] = "The peacocks ruled the GONGMEN city.";
//开启驱动设备
static int Myopen(struct inode *, struct file *);
//设备文件被释放时调用
static int Myrelease(struct inode *, struct file *);
//从驱动设备中读出数据
static ssize_t Myread(struct file *, char *, size_t, loff_t *);       
//把数据写到驱动设备
static ssize_t Mywrite(struct file *, const char *, size_t, loff_t *);

static const struct file_operations Myfop = {
	.open = Myopen,
	.release = Myrelease,
	.read = Myread,
	.write = Mywrite,
};

//初始化注册设备
static int __init Myinit(void)
{ 
	printk("Initial Start\n");
	Devnumber = register_chrdev(0, "Mydev", &Myfop);
	//主设备号由系统分配
	if (Devnumber < 0) {
		printk("Register Fail!\n");
		return -1;
	}
	if (Devnumber == 0) //设备号为0时创建
	{
		printk("Register Success!\n");
	}
	return 0;
}

//卸载设备
static void __exit Myexit(void)
{
	unregister_chrdev(Devnumber, "Mydev");
	printk("Unregister Success!\n");
}

//定义功能函数
static int Myopen(struct inode *myinode, struct file *myfile)
{
	try_module_get(THIS_MODULE);
	printk("Open Success!\n");
	return 0;
}

static int Myrelease(struct inode *myinode, struct file *myfile)
{
	module_put(THIS_MODULE);
	printk("Release Success!\n");
	return 0;
}

static ssize_t Myread(struct file *myfile, char *buf, size_t len, loff_t *mylof)
{
	int i = copy_to_user(buf, message,sizeof(message));
	if(i==0){
		printk("Read Success!\n");
		return sizeof(message);
	}
	else{
		return -EFAULT;
	}
}

static ssize_t Mywrite(struct file *myfile, const char *buf, size_t len, loff_t *mylof)
{
	int i = copy_from_user(message,buf,sizeof(message));
	if(i==0){
		printk("Write Success!\n");
		return sizeof(message);
	}
	else{
		return -EFAULT;
	}
}

module_init(Myinit);
module_exit(Myexit);
MODULE_LICENSE("GPL");
