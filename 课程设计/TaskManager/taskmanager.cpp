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

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
    show_info(1);//initial
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
            int pos = str5.indexOf("model name");
            if(pos!=-1)
            {
                pos+=13;
                cpu_name = QString(str5.mid(pos, str5.length()-13));
            }

            else if(pos = str5.indexOf("vendor_id"),pos!=-1)
            {
                pos+=12;
                cpu_version = QString(str5.mid(pos, str5.length()-12));
            }

        }


        file.close();
        cpu_name = cpu_name +cpu_version;
        ui->label_cpu_name->setText(cpu_name);
        //label_cpu_hz label_cpu_name label_pc_name label_boot_time label_run_time
    }   //label_pc_version
}
