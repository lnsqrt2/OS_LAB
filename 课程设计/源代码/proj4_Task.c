//使用GTK/QT实现系统监控器
// (1)获取并显示主机名
// (2)获取并显示系统启动的时间
// (3)显示系统到目前为止持续运行的时间
// (4)显示系统的版本号
// (5)显示cpu的型号和主频大小
// (6)同过pid或者进程名查询一个进程，并显示该进程的详细信息，提供杀掉该进程的功能。
// (7)显示系统所有进程的一些信息，包括pid，ppid，占用内存大小，优先级等等
// (8)cpu使用率的图形化显示(2分钟内的历史纪录曲线)
// (9)内存和交换分区(swap)使用率的图形化显示(2分钟内的历史纪录曲线)
// (10)在状态栏显示当前时间
// (11)在状态栏显示当前cpu使用率
// (12)在状态栏显示当前内存使用情况
// (13)用新进程运行一个其他程序
// (14)关机功能
//----参照WINDOWS的任务管理器，实现其中的几个功能。
// 功能(1)：/proc/sys/kernel/hostname
// 功能(2)：/proc/uptime
// 功能(3)：/proc/uptime
// 功能(4)：/proc/sys/kernel/ostype ,
//            /proc/sys/kernel/osrelease
// 功能(5)：/proc/cpuinfo
// 功能(6)：/proc/(pid)/stat
// 功能(7)：/proc/(pid)/stat,
//               /proc/(pid)/statm
// 功能(8)：/proc/stat
// 功能(9)：/proc/meminfo
// 功能(10)：未使用proc文件系统
// 功能(11)：/proc/stat
// 功能(12)：/proc/meminfo
// 功能(13)：未使用proc文件系统
// 功能(14)：未使用proc文件系统


#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <glib.h>

gboolean getTime(gpointer data)
{
    time_t Mytime;
    time(&Mytime);
    struct tm *time_tm;
    time_tm = localtime(&Mytime);
    gchar *time_dis = g_strdup_printf("%2d:%2d:%2d",(time_tm->tm_hour), (time_tm->tm_min), (time_tm->tm_sec));
    gtk_label_set_markup(GTK_LABEL(data), time_dis);
    return TRUE;
}

void init_Mainwindow(int argc, char const *argv[])
{
	GtkWidget *window;
    GtkWidget *label;
    //环境初始化
    gtk_init(&argc,&argv);
    //创建窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //标签实例化
    label = gtk_label_new (NULL);
    //设置标题
    gtk_window_set_title(GTK_WINDOW(window),"TIME");
    //设置窗口宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    //设置窗口大小
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 350);
    //关闭事件
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    //把标签绑定到窗口
    gtk_container_add(GTK_CONTAINER(window),label);

    gint s = g_timeout_add(1000,getTime,(void *)label);

    //显示所有窗口
    gtk_widget_show_all(window);
    gtk_main();
}

// gboolean getCpuRatio(gpointer data)
// {
// 	FILE *fp;
// 	char buffer[1024];
// 	size_t buf;
// 	float CpuRatio,CpuTime;
// 	float user = 0, nice = 0, sys = 0, idle = 0, iowait = 0;

// 	fp = fopen("/proc/stat", "r");
// 	fputc(user,fp2);
// 	buf = fread(buffer, 1, sizeof(buffer), fp);
// 	fclose(fp);

// 	if (buf == 0)
// 		return 0;
// 	buffer[buf] == '\0';
// 	sscanf(buffer, "%f %f %f %f %f", &user, &nice, &sys, &idle, &iowait);
// 	if (idle <= 0)
// 		idle = 0;
// 	CpuTime = user + nice + sys + idle + iowait;
// 	CpuRatio = 100*(CpuTime-idle)/CpuTime;
// 	if (CpuRatio > 100)
// 		CpuRatio = 100;

// 	gchar *cpu_dis = g_strdup_printf("CPU use radio: %.2f%",CpuRatio);
// 	gtk_label_set_markup(GTK_LABEL(data), cpu_dis);
//     return TRUE;
// }

int main(int argc, char const *argv[])
{
	init_Mainwindow(argc,argv);
	return 0;
}