//编写一个C程序，使用基于文本的终端图形编程库(curses)
//或图形界面(QT/GTK），分窗口显示三个并发进程的运行
//(一个窗口实时显示当前时间，一个窗口实时监测CPU的利用
//率，一个窗口做1到100的累加求和，刷新周期分别为1秒，
//2秒和3秒)
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <glib.h>

// void gettime(gpointer data)
// {
// 	time_t mytime;
// 	struct tm *time_tm;//具体时间项
// 	time(&mytime);
// 	//获取当前时间
// 	time_tm = localtime(&mytime);
// 	gchar *dis_time = g_strdup_printf("%d:%d:%d",(time_tm->tm_hour), (time_tm->tm_min), (time_tm->tm_sec));
// 	gtk_label_set_markup(GTK_LABEL(data), dis_time);
// }
gboolean gettime(gpointer data)
{
    time_t Mytime;
    time(&Mytime);
    struct tm *time_tm;
    time_tm = localtime(&Mytime);
    gchar *time_dis = g_strdup_printf("%2d:%2d:%2d",(time_tm->tm_hour), (time_tm->tm_min), (time_tm->tm_sec));
    gtk_label_set_markup(GTK_LABEL(data), time_dis);
    return TRUE;
}

void init_time(int argc, char const *argv[])
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

    gint s = g_timeout_add(1000,gettime,(void *)label);

    //显示所有窗口
    gtk_widget_show_all(window);
    gtk_main();
}

void init_cpu(int argc, char const *argv[])
{
	GtkWidget *window;
    GtkWidget *label;
    //环境初始化
    gtk_init(&argc,&argv);
    //创建窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //设置标题
    gtk_window_set_title(GTK_WINDOW(window),"CPU");
    //设置窗口宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    //设置窗口大小
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 350);
    //关闭事件
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    label = gtk_label_new("NO2");
    gtk_container_add(GTK_CONTAINER(window),label);

    //显示所有窗口
    gtk_widget_show_all(window);
    gtk_main();
}

void init_add(int argc, char const *argv[])
{
	GtkWidget *window;
    GtkWidget *label;
    //环境初始化
    gtk_init(&argc,&argv);
    //创建窗口
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //设置标题
    gtk_window_set_title(GTK_WINDOW(window),"ADD");
    //设置窗口宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    //设置窗口大小
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 350);
    //关闭事件
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);

    label = gtk_label_new("NO2");
    gtk_container_add(GTK_CONTAINER(window),label);

    //显示所有窗口
    gtk_widget_show_all(window);
    gtk_main();
}

int main(int argc, char const *argv[])
{
	 int time_tm,p_cpu,p_add;
	 if ((time_tm=fork()) == 0)//当前时间
	 {
	 	init_time(argc,argv);
	 }
	else if ((p_cpu=fork()) == 0)//cpu利用率
	{
		init_cpu(argc,argv);
	}
	 else//主进程add
	{
		init_add(argc,argv);
	}
	return 0;
}