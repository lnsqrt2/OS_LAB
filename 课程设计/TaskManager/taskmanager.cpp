#include "taskmanager.h"
#include "ui_taskmanager.h"
#include <QStringList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QTime>
#include <QTimer>
#include <QTabWidget>
#include <QDateTime>
#include <QDir>


TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    ui->button_kill->setEnabled(false);
    //show_info(1);//initial
    show_info(3);//initial
    item_num = 0;
    Timer = NULL;
    Timer = new QTimer(this);
    connect(Timer,&QTimer::timeout,this,&TaskManager::update_info);
    connect(ui->tabWidget,&QTabWidget::currentChanged,this,&TaskManager::show_info);
    Timer->start(1000);
}

TaskManager::~TaskManager()
{
    delete ui;
}

void TaskManager::update_info()
{
    tab_num = ui->tabWidget->currentIndex();
    show_info(0);
    show_info(2);

}

void TaskManager::show_info(int tab_num)
{
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd\nhh:mm:ss");
    ui->label_time_2->setText(localTime);

    if(tab_num == 0)//system info
    {
        // (1)获取并显示主机名
        // 功能(1)：/proc/sys/kernel/hostname
        file.setFileName("/proc/sys/kernel/hostname");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
            return;
        }
        QByteArray line1 = file.readLine();
        QString str1(line1);
        pc_name = str1.simplified();//clear \n
        file.close();
        //qDebug() << pc_name;
        ui->label_pc_name->setText(pc_name);

        // (2)获取并显示系统启动的时间
        // (3)显示系统到目前为止持续运行的时间
        // 功能(2)(3)：/proc/uptime
        file.setFileName("/proc/uptime");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
            return;
        }
        QByteArray line2 = file.readLine();
        QString str2(line2);
        QStringList list2 = str2.split(" ");
        file.close();

        str2 = list2[0];
        float boot = str2.toFloat();
        int boot_day = (boot/86400);
        int boot_hour = (boot - boot_day*86400)/3600;
        int boot_minute = (boot - boot_day*86400-boot_hour*3600)/60;
        int boot_second = (boot - boot_day*86400-boot_hour*3600-boot_minute*60);

        //qDebug() << boot<< boot_day<< boot_hour<< boot_minute<< boot_second;
        //qDebug() << boot_time;
        boot_time = QString("%1d %2h %3m %4s").arg(boot_day).arg(boot_hour).arg(boot_minute).arg(boot_second);
        ui->label_boot_time->setText(boot_time);

        QString str3 = list2[1];
        str3 = str3.simplified();//clear \n
        float run = str3.toFloat();
        int run_day = (run/86400);
        int run_hour = (run - run_day*86400)/3600;
        int run_minute = (run - run_day*86400-run_hour*3600)/60;
        int run_second = (run - run_day*86400-run_hour*3600-run_minute*60);

        //qDebug() << run<< run_day<< run_hour<< run_minute<< run_second;
        //qDebug() << run_time;
        run_time = QString("%1d %2h %3m %4s").arg(run_day).arg(run_hour).arg(run_minute).arg(run_second);
        ui->label_run_time->setText(run_time);

        //(4)显示系统的版本号
        // 功能(4)：/proc/sys/kernel/ostype ,
        //            /proc/sys/kernel/osrelease
        file.setFileName("/proc/sys/kernel/ostype");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
            return;
        }
        QByteArray line3 = file.readLine();
        QString str4_1 = (line3);
        file.close();

        file.setFileName("/proc/sys/kernel/osrelease");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
            return;
        }
        QByteArray line4 = file.readLine();
        file.close();
        QString str4_2 = (line4);
        QString str4 = str4_1 + str4_2;
        str4 = str4.simplified();
        //qDebug() << str4;
        ui->label_pc_version->setText(str4);

        // (5)显示cpu的型号和主频大小
        // 功能(5)：/proc/cpuinfo
        int pos = 0;
        file.setFileName("/proc/cpuinfo");
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
            return;
        }
        while(1)
        {
            QByteArray line5 = file.readLine();
            QString str5(line5);
            str5 = str5.simplified();
            if(str5 == NULL)
                break;
            pos = str5.indexOf("model name");//find model name
            if(pos!=-1)
            {
                pos+=13;
                cpu_name = QString(str5.mid(pos, str5.length()-13));
            }
            pos = str5.indexOf("cpu MHz");//find MHz
            if(pos!=-1)
            {
                pos+=10;
                cpu_hz = QString(str5.mid(pos, str5.length()-10));
            }
        }
        file.close();
        cpu_hz = cpu_hz+" MHz";
        ui->label_cpu_name->setText(cpu_name);
        ui->label_cpu_hz->setText(cpu_hz);
        //label_cpu_hz label_cpu_name label_pc_name label_boot_time label_run_time
    }   //label_pc_version

    if(tab_num == 1)//process
    {
        // (7)显示系统所有进程的一些信息，包括pid，ppid(parent pid)，占用内存大小，优先级等等
        // 功能(7)：/proc/(pid)/stat,
        //               /proc/(pid)/statm
        //R:runnign, S:sleeping (TASK_INTERRUPTIBLE), D:disk sleep (TASK_UNINTERRUPTIBLE), T: stopped, T:tracing stop,Z:zombie, X:dead
        bool p_flag;
        int start = 3;
        int left, right;
        ui->list_process->clear();
        item_num = 0;
        QDir my_dir("/proc");
        QStringList p_List = my_dir.entryList();//all pid list
        QString pid_list = p_List.join("\n");//插入分节符
        QListWidgetItem *title = new QListWidgetItem(QString("NAME")    +"\t\t"+
                                                     QString("PID")     +"\t"+
                                                     QString("PPID")    +"\t"+
                                                     QString("STAT")    +"\t"+
                                                     QString("MEM")     +"\t"+
                                                     QString("优先级"), ui->list_process);
        while(1)
        {
            left = pid_list.indexOf("\n", start);
            right = pid_list.indexOf("\n", left+1);
            pid = pid_list.mid(left+1, right-left-1);
            pid.toInt(&p_flag);

            if(!p_flag)
                break;
            else
                start = right;

            file.setFileName("/proc/" + pid + "/stat");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
                return;
            }
            QByteArray line7 = file.readLine();
            QString str7 = (line7);
            if (str7 ==  NULL)
            {
                break;
            }
            left = str7.indexOf("(");
            right = str7.indexOf(")");
            p_name = str7.mid(left+1, right-left-1);//in ()
            p_name.simplified();
            //qDebug()<<p_name;
            p_stat = str7.section(" ", 2, 2);
            ppid = str7.section(" ", 3, 3);
            p_pri = str7.section(" ", 17, 17);
            p_mem = str7.section(" ", 22, 22);
            p_mem = QString::number(p_mem.toInt()/1024)+" K";
            item_num++;
            //qDebug()<<item_num;
            if(p_name.length() >= 11 || p_name=="watchdog/0"|| p_name=="watchdog/1"|| p_name=="watchdog/2"|| p_name=="watchdog/3")
                QListWidgetItem *item = new QListWidgetItem(p_name  + "\t" +
                                                            pid     + "\t" +
                                                            ppid    + "\t" +
                                                            p_stat  + "\t" +
                                                            p_mem   + "\t" +
                                                            p_pri, ui->list_process);
            else
                QListWidgetItem *item = new QListWidgetItem(p_name  + "\t\t" +
                                                            pid     + "\t" +
                                                            ppid    + "\t" +
                                                            p_stat  + "\t" +
                                                            p_mem   + "\t" +
                                                            p_pri, ui->list_process);
        }
        file.close();
    }
    if(tab_num == 2)
    {
        // (8)cpu使用率的图形化显示(2分钟内的历史纪录曲线)
        // 功能(8)：/proc/stat

//        1、  采样两个足够短的时间间隔的Cpu快照，分别记作t1,t2，其中t1、t2的结构均为：
//        (user、nice、system、idle、iowait、irq、softirq、stealstolen、guest)的9元组;
//        2、  计算总的Cpu时间片totalCpuTime
//        a)         把第一次的所有cpu使用情况求和，得到s1;
//        b)         把第二次的所有cpu使用情况求和，得到s2;
//        c)         s2 - s1得到这个时间间隔内的所有时间片，即totalCpuTime = j2 - j1 ;
//        3、计算空闲时间idle
//        idle对应第四列的数据，用第二次的idle - 第一次的idle即可
//        idle=第二次的idle - 第一次的idle
//        4、计算cpu使用率cpu_rate
//        pcpu =100* (total-idle)/total
        int cpu_info[2][9];
        int s1 =0;
        int s2 =0;
        for(int t=0;t<=1;t++)
        {
            file.setFileName("/proc/stat");
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::warning(this,"Warning","File open fail!", QMessageBox::Ok);
                return;
            }
            QByteArray line8 = file.readLine();
            QString str8 = (line8);
            qDebug()<<str8;
            QStringList list8 = str8.split(" ");
            for(int i=0;i<=8;i++)
            {
                cpu_info[t][i] = QString(list8[i+2]).toInt();//"cpu","","user"...
                //qDebug()<<cpu_info[t][i];
            }
            QTime t1;
            t1.start();
            while(t1.elapsed()<100)
                QCoreApplication::processEvents();
        }
        file.close();
        for(int i=0;i<=8;i++)
        {
            s1 = s1 + cpu_info[0][i];
        }
        for(int i=0;i<=8;i++)
        {
            s2 = s2 + cpu_info[1][i];
        }
        //qDebug()<<s2<<s1;
        //qDebug()<<cpu_info[1][3]<<cpu_info[0][3];
        totalCpuTime = s2-s1;
        idleTime = cpu_info[1][3]-cpu_info[0][3];
        //qDebug()<<totalCpuTime<<idleTime;
        cpu_rate = 100* (totalCpuTime-idleTime)/totalCpuTime;
        QString rate = QString::number(cpu_rate);
        rate = rate + " %";
        //qDebug()<<rate;
        ui->label_cpurate->setText(rate);
        ui->label_cpurate_2->setText(rate);

        //cpu_image









        // (9)内存和交换分区(swap)使用率的图形化显示(2分钟内的历史纪录曲线)
        // 功能(9)：/proc/meminfo
    }

}



// 功能(6)：/proc/(pid)/stat
// (6)同过pid或者进程名查询一个进程，并显示该进程的详细信息，提供杀掉该进程的功能。
void TaskManager::on_button_search_clicked()
{
    int row;
    bool flag =false;
    QString str6 = ui->edit_pid->text();
    QString itemlist;
    QStringList list;
    show_info(2);
    //qDebug()<<item_num;
    for(row =1;row<=item_num;row++)
    {
        itemlist = ui->list_process->item(row)->text();
        list = itemlist.split("\t");
        if(str6==list[0]||(str6==list[1]&&list[1]!="")||(str6==list[2]&&list[1]==""))//pid or p_name
        {
            ui->list_process->setCurrentRow(row);
            ui->button_kill->setEnabled(true);
            flag = true;
            break;
        }
    }
    if(flag == false)
        QMessageBox::warning(this,"Error","Can not find it, please check your input!", QMessageBox::Ok);
    return;
    //qDebug()<<list[0]<<list[1]<<list[2]<<list[3]<<list[4];
}

void TaskManager::on_button_kill_clicked()
{
    QString itemlist = ui->list_process->currentItem()->text();
    QStringList list = itemlist.split("\t");
    QString item;
    char*  ch;
    if(list[1]!="")
        item = list[1];
    else
        item = list[2];
    //qDebug()<<item;
    QString cmd_kill = QString("kill %1").arg(item);
    //qDebug()<<cmd_kill;
    QByteArray ba = cmd_kill.toLatin1();
    ch=ba.data();
    system(ch);
    QMessageBox::warning(this,"Done","Killed!", QMessageBox::Ok);
    QListWidgetItem *k_item = ui->list_process->takeItem(ui->list_process->currentRow());
    delete k_item;
    show_info(2);
}
//system("/sbin/init 0"); //shutdown

