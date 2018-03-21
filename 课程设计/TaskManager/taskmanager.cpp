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
    show_info(1);//initial
    show_info(2);//initial
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
    show_info(tab_num);

}

void TaskManager::show_info(int tab_num)
{
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd\nhh:mm:ss");
    ui->label_time_2->setText(localTime);

    if(tab_num == 1)//system info
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

    if(tab_num == 2)//process
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
//    //获得进程号
//    QListWidgetItem *item = ui->listWidget_process->currentItem();
//    QString pro = item->text();
//    pro = pro.section("\t", 0, 0);
//    system("kill " + pro.toLatin1());
//    QMessageBox::warning(this, "kill", "该进程已被杀死!"), QMessageBox::OK);
//    //回到进程信息tab表
//    show_tabWidgetInfo(1);
}
// * @brief KNNDlg::on_deleteSpfiles_clicked删除选中的样本文件
// */
//void KNNDlg::on_deleteSpfiles_clicked()
//{


//    QList <QListWidgetItem*> items ;//注意 items是个Qlist 其中的元素是QListWidgetItem
//    items=ui->SPList->selectedItems();
//    if(items.size()==0)
//        return;
//    else
//    {
//        for(int i =0; i<items.size(); i++)//遍历所算的ITEM
//        {
//            QListWidgetItem*sel = items[i];
//            int r = ui->SPList->row(sel);
//            delete  ui->SPList->takeItem(r);

//        }
//        //下面代码可实现删除单选的item
//        //    QListWidgetItem *item = ui->SPList->takeItem(ui->SPList->currentRow());
//        //    delete item;
//    }
//}
