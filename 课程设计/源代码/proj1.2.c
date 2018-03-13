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

gint count = 0;
char buf[5];

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

void init_cpu(int argc, char const *argv[])
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
    gtk_window_set_title(GTK_WINDOW(window),"CPU");
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

gboolean getAdd(gpointer data)
{
    count++;
    sprintf(buf,"%d",count);
    gtk_label_set_markup(GTK_LABEL(data), buf);
    return TRUE;
}

void init_add(int argc, char const *argv[])
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
    gtk_window_set_title(GTK_WINDOW(window),"ADD_MAIN");
    //设置窗口宽度
    gtk_container_set_border_width(GTK_CONTAINER(window), 0);
    //设置窗口大小
    gtk_window_set_default_size(GTK_WINDOW(window), 250, 350);
    //关闭事件
    g_signal_connect(window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
    //把标签绑定到窗口
    gtk_container_add(GTK_CONTAINER(window),label);

    gint s = g_timeout_add(1000,getAdd,(void *)label);

    

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