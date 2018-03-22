/********************************************************************************
** Form generated from reading UI file 'taskmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKMANAGER_H
#define UI_TASKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskManager
{
public:
    QTabWidget *tabWidget;
    QWidget *sys_info;
    QGroupBox *pc_group;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_pc_name;
    QLabel *label_boot_time;
    QLabel *label_run_time;
    QLabel *label_pc_version;
    QGroupBox *cpu_group;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_cpu_name;
    QLabel *label_cpu_hz;
    QWidget *pro_info;
    QListWidget *list_process;
    QPushButton *button_kill;
    QLineEdit *edit_pid;
    QPushButton *button_search;
    QWidget *cpumem_info;
    QTabWidget *tabWidget_2;
    QWidget *cpu_paint;
    QGroupBox *group_cpu;
    QLabel *label_cpurate;
    QLabel *label_19;
    QLabel *label_cover;
    QWidget *mem_paint;
    QGroupBox *group_mem;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_mem_used;
    QLabel *label_mem_free;
    QLabel *label_mem_total;
    QLabel *label_cover_2;
    QWidget *swap_image;
    QGroupBox *group_swap;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_swap_used;
    QLabel *label_swap_free;
    QLabel *label_swap_total;
    QLabel *label_cover_3;
    QWidget *my_info;
    QLabel *label_7;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_20;
    QPushButton *button_off;
    QLabel *label_21;
    QLabel *label_cpurate_2;
    QLabel *label_time_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_mem_used_2;
    QLabel *label_mem_free_2;
    QLabel *label_22;
    QPushButton *button_refcpu;

    void setupUi(QWidget *TaskManager)
    {
        if (TaskManager->objectName().isEmpty())
            TaskManager->setObjectName(QStringLiteral("TaskManager"));
        TaskManager->resize(669, 602);
        tabWidget = new QTabWidget(TaskManager);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 90, 631, 501));
        tabWidget->setTabShape(QTabWidget::Triangular);
        sys_info = new QWidget();
        sys_info->setObjectName(QStringLiteral("sys_info"));
        pc_group = new QGroupBox(sys_info);
        pc_group->setObjectName(QStringLiteral("pc_group"));
        pc_group->setGeometry(QRect(20, 20, 491, 191));
        label = new QLabel(pc_group);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 81, 18));
        label_2 = new QLabel(pc_group);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 121, 18));
        label_3 = new QLabel(pc_group);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 101, 18));
        label_4 = new QLabel(pc_group);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 120, 81, 18));
        label_pc_name = new QLabel(pc_group);
        label_pc_name->setObjectName(QStringLiteral("label_pc_name"));
        label_pc_name->setGeometry(QRect(190, 30, 81, 18));
        label_boot_time = new QLabel(pc_group);
        label_boot_time->setObjectName(QStringLiteral("label_boot_time"));
        label_boot_time->setGeometry(QRect(190, 60, 281, 18));
        label_run_time = new QLabel(pc_group);
        label_run_time->setObjectName(QStringLiteral("label_run_time"));
        label_run_time->setGeometry(QRect(190, 90, 301, 18));
        label_pc_version = new QLabel(pc_group);
        label_pc_version->setObjectName(QStringLiteral("label_pc_version"));
        label_pc_version->setGeometry(QRect(190, 120, 271, 18));
        cpu_group = new QGroupBox(sys_info);
        cpu_group->setObjectName(QStringLiteral("cpu_group"));
        cpu_group->setGeometry(QRect(20, 280, 491, 111));
        label_5 = new QLabel(cpu_group);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 81, 18));
        label_6 = new QLabel(cpu_group);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 70, 81, 18));
        label_cpu_name = new QLabel(cpu_group);
        label_cpu_name->setObjectName(QStringLiteral("label_cpu_name"));
        label_cpu_name->setGeometry(QRect(100, 30, 421, 20));
        label_cpu_hz = new QLabel(cpu_group);
        label_cpu_hz->setObjectName(QStringLiteral("label_cpu_hz"));
        label_cpu_hz->setGeometry(QRect(100, 70, 391, 20));
        tabWidget->addTab(sys_info, QString());
        pro_info = new QWidget();
        pro_info->setObjectName(QStringLiteral("pro_info"));
        list_process = new QListWidget(pro_info);
        list_process->setObjectName(QStringLiteral("list_process"));
        list_process->setGeometry(QRect(10, 10, 581, 401));
        button_kill = new QPushButton(pro_info);
        button_kill->setObjectName(QStringLiteral("button_kill"));
        button_kill->setGeometry(QRect(480, 420, 112, 34));
        edit_pid = new QLineEdit(pro_info);
        edit_pid->setObjectName(QStringLiteral("edit_pid"));
        edit_pid->setGeometry(QRect(10, 420, 151, 31));
        button_search = new QPushButton(pro_info);
        button_search->setObjectName(QStringLiteral("button_search"));
        button_search->setGeometry(QRect(180, 420, 112, 34));
        tabWidget->addTab(pro_info, QString());
        cpumem_info = new QWidget();
        cpumem_info->setObjectName(QStringLiteral("cpumem_info"));
        tabWidget_2 = new QTabWidget(cpumem_info);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(20, 10, 581, 441));
        tabWidget_2->setTabPosition(QTabWidget::West);
        cpu_paint = new QWidget();
        cpu_paint->setObjectName(QStringLiteral("cpu_paint"));
        group_cpu = new QGroupBox(cpu_paint);
        group_cpu->setObjectName(QStringLiteral("group_cpu"));
        group_cpu->setGeometry(QRect(20, 0, 501, 51));
        label_cpurate = new QLabel(group_cpu);
        label_cpurate->setObjectName(QStringLiteral("label_cpurate"));
        label_cpurate->setGeometry(QRect(110, 30, 81, 18));
        label_19 = new QLabel(group_cpu);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 30, 101, 18));
        label_cover = new QLabel(cpu_paint);
        label_cover->setObjectName(QStringLiteral("label_cover"));
        label_cover->setGeometry(QRect(130, 120, 301, 181));
        label_cover->setPixmap(QPixmap(QString::fromUtf8("../../../wait_image.png")));
        label_cover->setScaledContents(false);
        tabWidget_2->addTab(cpu_paint, QString());
        mem_paint = new QWidget();
        mem_paint->setObjectName(QStringLiteral("mem_paint"));
        group_mem = new QGroupBox(mem_paint);
        group_mem->setObjectName(QStringLiteral("group_mem"));
        group_mem->setGeometry(QRect(20, 0, 431, 81));
        label_8 = new QLabel(group_mem);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 30, 81, 18));
        label_9 = new QLabel(group_mem);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 60, 81, 18));
        label_10 = new QLabel(group_mem);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(260, 30, 101, 18));
        label_mem_used = new QLabel(group_mem);
        label_mem_used->setObjectName(QStringLiteral("label_mem_used"));
        label_mem_used->setGeometry(QRect(80, 30, 81, 18));
        label_mem_free = new QLabel(group_mem);
        label_mem_free->setObjectName(QStringLiteral("label_mem_free"));
        label_mem_free->setGeometry(QRect(80, 60, 81, 18));
        label_mem_total = new QLabel(group_mem);
        label_mem_total->setObjectName(QStringLiteral("label_mem_total"));
        label_mem_total->setGeometry(QRect(260, 60, 81, 18));
        label_cover_2 = new QLabel(mem_paint);
        label_cover_2->setObjectName(QStringLiteral("label_cover_2"));
        label_cover_2->setGeometry(QRect(130, 120, 301, 181));
        label_cover_2->setPixmap(QPixmap(QString::fromUtf8("../../../wait_image.png")));
        label_cover_2->setScaledContents(false);
        tabWidget_2->addTab(mem_paint, QString());
        swap_image = new QWidget();
        swap_image->setObjectName(QStringLiteral("swap_image"));
        group_swap = new QGroupBox(swap_image);
        group_swap->setObjectName(QStringLiteral("group_swap"));
        group_swap->setGeometry(QRect(20, 0, 411, 81));
        label_13 = new QLabel(group_swap);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 30, 81, 18));
        label_14 = new QLabel(group_swap);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 60, 81, 18));
        label_15 = new QLabel(group_swap);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(250, 30, 101, 18));
        label_swap_used = new QLabel(group_swap);
        label_swap_used->setObjectName(QStringLiteral("label_swap_used"));
        label_swap_used->setGeometry(QRect(80, 30, 81, 18));
        label_swap_free = new QLabel(group_swap);
        label_swap_free->setObjectName(QStringLiteral("label_swap_free"));
        label_swap_free->setGeometry(QRect(80, 60, 81, 18));
        label_swap_total = new QLabel(group_swap);
        label_swap_total->setObjectName(QStringLiteral("label_swap_total"));
        label_swap_total->setGeometry(QRect(250, 60, 81, 18));
        label_cover_3 = new QLabel(swap_image);
        label_cover_3->setObjectName(QStringLiteral("label_cover_3"));
        label_cover_3->setGeometry(QRect(130, 120, 301, 181));
        label_cover_3->setPixmap(QPixmap(QString::fromUtf8("../../../wait_image.png")));
        label_cover_3->setScaledContents(false);
        tabWidget_2->addTab(swap_image, QString());
        tabWidget->addTab(cpumem_info, QString());
        my_info = new QWidget();
        my_info->setObjectName(QStringLiteral("my_info"));
        label_7 = new QLabel(my_info);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 140, 281, 31));
        label_16 = new QLabel(my_info);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(150, 30, 141, 21));
        label_17 = new QLabel(my_info);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(150, 60, 141, 21));
        label_18 = new QLabel(my_info);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(150, 90, 141, 21));
        label_20 = new QLabel(my_info);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(150, 120, 91, 17));
        tabWidget->addTab(my_info, QString());
        button_off = new QPushButton(TaskManager);
        button_off->setObjectName(QStringLiteral("button_off"));
        button_off->setGeometry(QRect(521, 70, 111, 31));
        label_21 = new QLabel(TaskManager);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 10, 90, 18));
        label_cpurate_2 = new QLabel(TaskManager);
        label_cpurate_2->setObjectName(QStringLiteral("label_cpurate_2"));
        label_cpurate_2->setGeometry(QRect(170, 40, 81, 18));
        label_time_2 = new QLabel(TaskManager);
        label_time_2->setObjectName(QStringLiteral("label_time_2"));
        label_time_2->setGeometry(QRect(20, 30, 81, 41));
        label_11 = new QLabel(TaskManager);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(340, 10, 90, 18));
        label_12 = new QLabel(TaskManager);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(510, 10, 90, 18));
        label_mem_used_2 = new QLabel(TaskManager);
        label_mem_used_2->setObjectName(QStringLiteral("label_mem_used_2"));
        label_mem_used_2->setGeometry(QRect(340, 40, 81, 18));
        label_mem_free_2 = new QLabel(TaskManager);
        label_mem_free_2->setObjectName(QStringLiteral("label_mem_free_2"));
        label_mem_free_2->setGeometry(QRect(510, 40, 81, 18));
        label_22 = new QLabel(TaskManager);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(160, 10, 99, 18));
        button_refcpu = new QPushButton(TaskManager);
        button_refcpu->setObjectName(QStringLiteral("button_refcpu"));
        button_refcpu->setGeometry(QRect(340, 70, 101, 31));

        retranslateUi(TaskManager);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TaskManager);
    } // setupUi

    void retranslateUi(QWidget *TaskManager)
    {
        TaskManager->setWindowTitle(QApplication::translate("TaskManager", "TaskManager", 0));
        pc_group->setTitle(QApplication::translate("TaskManager", "\346\255\244\347\224\265\350\204\221", 0));
        label->setText(QApplication::translate("TaskManager", "\344\270\273\346\234\272\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("TaskManager", "\345\220\257\345\212\250\346\227\266\351\227\264\357\274\232", 0));
        label_3->setText(QApplication::translate("TaskManager", "\345\267\262\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", 0));
        label_4->setText(QApplication::translate("TaskManager", "\347\211\210\346\234\254\345\217\267\357\274\232", 0));
        label_pc_name->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_boot_time->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_run_time->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_pc_version->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        cpu_group->setTitle(QApplication::translate("TaskManager", "CPU", 0));
        label_5->setText(QApplication::translate("TaskManager", "\345\236\213\345\217\267\357\274\232", 0));
        label_6->setText(QApplication::translate("TaskManager", "\344\270\273\351\242\221\357\274\232", 0));
        label_cpu_name->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_cpu_hz->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(sys_info), QApplication::translate("TaskManager", "\347\263\273\347\273\237", 0));
        button_kill->setText(QApplication::translate("TaskManager", "\347\273\223\346\235\237\350\277\233\347\250\213", 0));
        edit_pid->setText(QApplication::translate("TaskManager", "\350\257\267\350\276\223\345\205\245\350\277\233\347\250\213pid", 0));
        button_search->setText(QApplication::translate("TaskManager", "\346\220\234\347\264\242", 0));
        tabWidget->setTabText(tabWidget->indexOf(pro_info), QApplication::translate("TaskManager", "\350\277\233\347\250\213", 0));
        group_cpu->setTitle(QApplication::translate("TaskManager", "CPU\344\275\277\347\224\250\347\216\207", 0));
        label_cpurate->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_19->setText(QApplication::translate("TaskManager", "\345\275\223\345\211\215\344\275\277\347\224\250\347\216\207\357\274\232", 0));
        label_cover->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(cpu_paint), QApplication::translate("TaskManager", "CPU", 0));
        group_mem->setTitle(QApplication::translate("TaskManager", "\345\206\205\345\255\230\344\275\277\347\224\250\346\203\205\345\206\265", 0));
        label_8->setText(QApplication::translate("TaskManager", "\345\267\262\347\224\250\357\274\232", 0));
        label_9->setText(QApplication::translate("TaskManager", "\345\217\257\347\224\250\357\274\232", 0));
        label_10->setText(QApplication::translate("TaskManager", "\345\206\205\345\255\230\346\200\273\345\244\247\345\260\217", 0));
        label_mem_used->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_mem_free->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_mem_total->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_cover_2->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(mem_paint), QApplication::translate("TaskManager", "MEM", 0));
        group_swap->setTitle(QApplication::translate("TaskManager", "\344\272\244\346\215\242\345\210\206\345\214\272\344\275\277\347\224\250\346\203\205\345\206\265", 0));
        label_13->setText(QApplication::translate("TaskManager", "\345\267\262\347\224\250\357\274\232", 0));
        label_14->setText(QApplication::translate("TaskManager", "\345\217\257\347\224\250\357\274\232", 0));
        label_15->setText(QApplication::translate("TaskManager", "\345\206\205\345\255\230\346\200\273\345\244\247\345\260\217", 0));
        label_swap_used->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_swap_free->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_swap_total->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_cover_3->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(swap_image), QApplication::translate("TaskManager", "SWAP", 0));
        tabWidget->setTabText(tabWidget->indexOf(cpumem_info), QApplication::translate("TaskManager", "\346\200\247\350\203\275", 0));
        label_7->setText(QApplication::translate("TaskManager", "\350\216\267\345\217\226\345\270\256\345\212\251\350\257\267\350\201\224\347\263\273630212894@qq.com", 0));
        label_16->setText(QApplication::translate("TaskManager", "CS1503 \347\217\255", 0));
        label_17->setText(QApplication::translate("TaskManager", "U201514559", 0));
        label_18->setText(QApplication::translate("TaskManager", "\345\221\250\351\223\255\346\230\212", 0));
        label_20->setText(QApplication::translate("TaskManager", "2018/3/22", 0));
        tabWidget->setTabText(tabWidget->indexOf(my_info), QApplication::translate("TaskManager", "\345\205\263\344\272\216", 0));
        button_off->setText(QApplication::translate("TaskManager", "Shutdown", 0));
        label_21->setText(QApplication::translate("TaskManager", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", 0));
        label_cpurate_2->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_time_2->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_11->setText(QApplication::translate("TaskManager", "\345\206\205\345\255\230\345\267\262\347\224\250\357\274\232", 0));
        label_12->setText(QApplication::translate("TaskManager", "\345\206\205\345\255\230\345\217\257\347\224\250\357\274\232", 0));
        label_mem_used_2->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_mem_free_2->setText(QApplication::translate("TaskManager", "TextLabel", 0));
        label_22->setText(QApplication::translate("TaskManager", "CPU\344\275\277\347\224\250\347\216\207\357\274\232", 0));
        button_refcpu->setText(QApplication::translate("TaskManager", "Reflesh", 0));
    } // retranslateUi

};

namespace Ui {
    class TaskManager: public Ui_TaskManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKMANAGER_H
