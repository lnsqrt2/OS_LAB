/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 17 17:45:36 2017
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTabWidget>
#include <QToolBar>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget_INFO;
    QWidget *MemoryInfo;
    QGroupBox *groupBox;
    QProgressBar *progressBar_CPU;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QProgressBar *progressBar_RAM;
    QProgressBar *progressBar_SWAP;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_20;
    QLabel *label_RAM_Used;
    QLabel *label_RAM_Left;
    QLabel *label_RAM_Total;
    QLabel *label_SWAP_Total;
    QLabel *label_SWAP_Used;
    QLabel *label_SWAP_Left;
    QWidget *Process;
    QListWidget *listWidget_process;
    QPushButton *pushButton_pkill;
    QPushButton *pushButton_prefresh;
    QLabel *label;
    QLabel *label_pNum;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_pRun;
    QLabel *label_pSleep;
    QLabel *label_pZombie;
    QWidget *Module;
    QPushButton *pushButton_Model_install;
    QPushButton *pushButton_Model_remove;
    QPushButton *pushButton_Model_refresh;
    QListWidget *listWidget_model;
    QWidget *System;
    QGroupBox *groupBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_CPUName;
    QLabel *label_CPUType;
    QLabel *label_CPUFrequency;
    QLabel *label_CatheCapacity;
    QGroupBox *groupBox_4;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_SystemType;
    QLabel *label_SystemVersion;
    QLabel *label_GCCVersion;
    QWidget *tab;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *pushButton_reboot;
    QPushButton *pushButton_halt;
    QMenuBar *menuBar;
    QMenu *menuSysMontior;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(605, 438);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget_INFO = new QTabWidget(centralWidget);
        tabWidget_INFO->setObjectName(QString::fromUtf8("tabWidget_INFO"));
        tabWidget_INFO->setGeometry(QRect(0, -10, 611, 341));
        tabWidget_INFO->setCursor(QCursor(Qt::WaitCursor));
        tabWidget_INFO->setTabShape(QTabWidget::Triangular);
        tabWidget_INFO->setMovable(false);
        MemoryInfo = new QWidget();
        MemoryInfo->setObjectName(QString::fromUtf8("MemoryInfo"));
        groupBox = new QGroupBox(MemoryInfo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 591, 81));
        progressBar_CPU = new QProgressBar(groupBox);
        progressBar_CPU->setObjectName(QString::fromUtf8("progressBar_CPU"));
        progressBar_CPU->setGeometry(QRect(50, 30, 431, 23));
        progressBar_CPU->setValue(24);
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 30, 66, 17));
        groupBox_2 = new QGroupBox(MemoryInfo);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 80, 591, 231));
        progressBar_RAM = new QProgressBar(groupBox_2);
        progressBar_RAM->setObjectName(QString::fromUtf8("progressBar_RAM"));
        progressBar_RAM->setGeometry(QRect(50, 50, 431, 23));
        progressBar_RAM->setValue(24);
        progressBar_SWAP = new QProgressBar(groupBox_2);
        progressBar_SWAP->setObjectName(QString::fromUtf8("progressBar_SWAP"));
        progressBar_SWAP->setGeometry(QRect(50, 140, 431, 23));
        progressBar_SWAP->setValue(24);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 50, 66, 17));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(0, 140, 66, 17));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(50, 80, 66, 17));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(200, 80, 66, 17));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(380, 80, 66, 17));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(380, 170, 66, 17));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(50, 170, 66, 17));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(200, 170, 66, 17));
        label_RAM_Used = new QLabel(groupBox_2);
        label_RAM_Used->setObjectName(QString::fromUtf8("label_RAM_Used"));
        label_RAM_Used->setGeometry(QRect(90, 80, 66, 17));
        label_RAM_Left = new QLabel(groupBox_2);
        label_RAM_Left->setObjectName(QString::fromUtf8("label_RAM_Left"));
        label_RAM_Left->setGeometry(QRect(240, 80, 66, 17));
        label_RAM_Total = new QLabel(groupBox_2);
        label_RAM_Total->setObjectName(QString::fromUtf8("label_RAM_Total"));
        label_RAM_Total->setGeometry(QRect(420, 80, 66, 17));
        label_SWAP_Total = new QLabel(groupBox_2);
        label_SWAP_Total->setObjectName(QString::fromUtf8("label_SWAP_Total"));
        label_SWAP_Total->setGeometry(QRect(420, 170, 66, 17));
        label_SWAP_Used = new QLabel(groupBox_2);
        label_SWAP_Used->setObjectName(QString::fromUtf8("label_SWAP_Used"));
        label_SWAP_Used->setGeometry(QRect(90, 170, 66, 17));
        label_SWAP_Left = new QLabel(groupBox_2);
        label_SWAP_Left->setObjectName(QString::fromUtf8("label_SWAP_Left"));
        label_SWAP_Left->setGeometry(QRect(240, 170, 66, 17));
        tabWidget_INFO->addTab(MemoryInfo, QString());
        Process = new QWidget();
        Process->setObjectName(QString::fromUtf8("Process"));
        listWidget_process = new QListWidget(Process);
        listWidget_process->setObjectName(QString::fromUtf8("listWidget_process"));
        listWidget_process->setGeometry(QRect(0, 0, 421, 271));
        pushButton_pkill = new QPushButton(Process);
        pushButton_pkill->setObjectName(QString::fromUtf8("pushButton_pkill"));
        pushButton_pkill->setGeometry(QRect(20, 280, 98, 27));
        pushButton_prefresh = new QPushButton(Process);
        pushButton_prefresh->setObjectName(QString::fromUtf8("pushButton_prefresh"));
        pushButton_prefresh->setGeometry(QRect(170, 280, 98, 27));
        label = new QLabel(Process);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 30, 66, 17));
        label_pNum = new QLabel(Process);
        label_pNum->setObjectName(QString::fromUtf8("label_pNum"));
        label_pNum->setGeometry(QRect(490, 30, 66, 17));
        label_2 = new QLabel(Process);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 60, 66, 17));
        label_3 = new QLabel(Process);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 100, 66, 17));
        label_4 = new QLabel(Process);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 140, 66, 17));
        label_pRun = new QLabel(Process);
        label_pRun->setObjectName(QString::fromUtf8("label_pRun"));
        label_pRun->setGeometry(QRect(490, 60, 66, 17));
        label_pSleep = new QLabel(Process);
        label_pSleep->setObjectName(QString::fromUtf8("label_pSleep"));
        label_pSleep->setGeometry(QRect(490, 100, 66, 17));
        label_pZombie = new QLabel(Process);
        label_pZombie->setObjectName(QString::fromUtf8("label_pZombie"));
        label_pZombie->setGeometry(QRect(490, 140, 66, 17));
        tabWidget_INFO->addTab(Process, QString());
        Module = new QWidget();
        Module->setObjectName(QString::fromUtf8("Module"));
        pushButton_Model_install = new QPushButton(Module);
        pushButton_Model_install->setObjectName(QString::fromUtf8("pushButton_Model_install"));
        pushButton_Model_install->setGeometry(QRect(20, 280, 98, 27));
        pushButton_Model_remove = new QPushButton(Module);
        pushButton_Model_remove->setObjectName(QString::fromUtf8("pushButton_Model_remove"));
        pushButton_Model_remove->setGeometry(QRect(180, 280, 98, 27));
        pushButton_Model_refresh = new QPushButton(Module);
        pushButton_Model_refresh->setObjectName(QString::fromUtf8("pushButton_Model_refresh"));
        pushButton_Model_refresh->setGeometry(QRect(350, 280, 98, 27));
        listWidget_model = new QListWidget(Module);
        listWidget_model->setObjectName(QString::fromUtf8("listWidget_model"));
        listWidget_model->setGeometry(QRect(0, 0, 561, 271));
        tabWidget_INFO->addTab(Module, QString());
        System = new QWidget();
        System->setObjectName(QString::fromUtf8("System"));
        groupBox_3 = new QGroupBox(System);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 591, 171));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 30, 66, 17));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 60, 66, 17));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 90, 66, 17));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 120, 81, 17));
        label_CPUName = new QLabel(groupBox_3);
        label_CPUName->setObjectName(QString::fromUtf8("label_CPUName"));
        label_CPUName->setGeometry(QRect(140, 30, 321, 17));
        label_CPUType = new QLabel(groupBox_3);
        label_CPUType->setObjectName(QString::fromUtf8("label_CPUType"));
        label_CPUType->setGeometry(QRect(140, 60, 151, 17));
        label_CPUFrequency = new QLabel(groupBox_3);
        label_CPUFrequency->setObjectName(QString::fromUtf8("label_CPUFrequency"));
        label_CPUFrequency->setGeometry(QRect(140, 90, 66, 17));
        label_CatheCapacity = new QLabel(groupBox_3);
        label_CatheCapacity->setObjectName(QString::fromUtf8("label_CatheCapacity"));
        label_CatheCapacity->setGeometry(QRect(140, 120, 66, 17));
        groupBox_4 = new QGroupBox(System);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 180, 591, 121));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(70, 30, 111, 17));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(70, 60, 111, 17));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(70, 90, 111, 17));
        label_SystemType = new QLabel(groupBox_4);
        label_SystemType->setObjectName(QString::fromUtf8("label_SystemType"));
        label_SystemType->setGeometry(QRect(190, 30, 151, 17));
        label_SystemVersion = new QLabel(groupBox_4);
        label_SystemVersion->setObjectName(QString::fromUtf8("label_SystemVersion"));
        label_SystemVersion->setGeometry(QRect(190, 60, 281, 17));
        label_GCCVersion = new QLabel(groupBox_4);
        label_GCCVersion->setObjectName(QString::fromUtf8("label_GCCVersion"));
        label_GCCVersion->setGeometry(QRect(190, 90, 291, 17));
        tabWidget_INFO->addTab(System, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(20, 30, 66, 17));
        label_22 = new QLabel(tab);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(100, 30, 191, 17));
        label_23 = new QLabel(tab);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(100, 70, 191, 17));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(20, 70, 66, 17));
        label_25 = new QLabel(tab);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(100, 110, 191, 17));
        label_26 = new QLabel(tab);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(20, 110, 66, 17));
        label_27 = new QLabel(tab);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(100, 150, 191, 17));
        label_28 = new QLabel(tab);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(20, 150, 66, 17));
        tabWidget_INFO->addTab(tab, QString());
        pushButton_reboot = new QPushButton(centralWidget);
        pushButton_reboot->setObjectName(QString::fromUtf8("pushButton_reboot"));
        pushButton_reboot->setGeometry(QRect(380, 340, 98, 27));
        pushButton_halt = new QPushButton(centralWidget);
        pushButton_halt->setObjectName(QString::fromUtf8("pushButton_halt"));
        pushButton_halt->setGeometry(QRect(500, 340, 98, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 605, 26));
        menuSysMontior = new QMenu(menuBar);
        menuSysMontior->setObjectName(QString::fromUtf8("menuSysMontior"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuSysMontior->menuAction());

        retranslateUi(MainWindow);

        tabWidget_INFO->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
#ifndef QT_NO_TOOLTIP
        MemoryInfo->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\345\206\205\345\255\230\344\277\241\346\201\257</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        MemoryInfo->setWhatsThis(QApplication::translate("MainWindow", "<html><head/><body><p>\345\206\205\345\255\230\344\277\241\346\201\257</p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        groupBox->setTitle(QApplication::translate("MainWindow", "CPU", 0));
        label_11->setText(QApplication::translate("MainWindow", "CPU:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\206\205\345\255\230\345\222\214\344\272\244\346\215\242\345\210\206\345\214\272", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\206\205\345\255\230\357\274\232", 0));
        label_10->setText(QApplication::translate("MainWindow", "\344\272\244\346\215\242", 0));
        label_12->setText(QApplication::translate("MainWindow", "Used:", 0));
        label_13->setText(QApplication::translate("MainWindow", "Left:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Total:", 0));
        label_15->setText(QApplication::translate("MainWindow", "Total:", 0));
        label_16->setText(QApplication::translate("MainWindow", "Used:", 0));
        label_20->setText(QApplication::translate("MainWindow", "Left:", 0));
        label_RAM_Used->setText(QApplication::translate("MainWindow", "0", 0));
        label_RAM_Left->setText(QApplication::translate("MainWindow", "0", 0));
        label_RAM_Total->setText(QApplication::translate("MainWindow", "0", 0));
        label_SWAP_Total->setText(QApplication::translate("MainWindow", "0", 0));
        label_SWAP_Used->setText(QApplication::translate("MainWindow", "0", 0));
        label_SWAP_Left->setText(QApplication::translate("MainWindow", "0", 0));
        tabWidget_INFO->setTabText(tabWidget_INFO->indexOf(MemoryInfo), QApplication::translate("MainWindow", "\345\206\205\345\255\230\344\277\241\346\201\257", 0));
        pushButton_pkill->setText(QApplication::translate("MainWindow", "kill", 0));
        pushButton_prefresh->setText(QApplication::translate("MainWindow", "refresh", 0));
        label->setText(QApplication::translate("MainWindow", "\350\277\233\347\250\213\346\225\260\357\274\232", 0));
        label_pNum->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\225\260\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow", "\347\235\241\347\234\240\346\225\260\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow", "\346\265\206\346\255\273\346\225\260\357\274\232", 0));
        label_pRun->setText(QApplication::translate("MainWindow", "0", 0));
        label_pSleep->setText(QApplication::translate("MainWindow", "0", 0));
        label_pZombie->setText(QApplication::translate("MainWindow", "0", 0));
        tabWidget_INFO->setTabText(tabWidget_INFO->indexOf(Process), QApplication::translate("MainWindow", "\350\277\233\347\250\213\344\277\241\346\201\257", 0));
        pushButton_Model_install->setText(QApplication::translate("MainWindow", "Install", 0));
        pushButton_Model_remove->setText(QApplication::translate("MainWindow", "Romove", 0));
        pushButton_Model_refresh->setText(QApplication::translate("MainWindow", "refresh", 0));
        tabWidget_INFO->setTabText(tabWidget_INFO->indexOf(Module), QApplication::translate("MainWindow", "\346\250\241\345\235\227\344\277\241\346\201\257", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\244\204\347\220\206\345\231\250\344\277\241\346\201\257", 0));
        label_5->setText(QApplication::translate("MainWindow", "CPU\345\220\215\347\247\260\357\274\232", 0));
        label_6->setText(QApplication::translate("MainWindow", "CPU\347\261\273\345\236\213\357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "CPU\351\242\221\347\216\207\357\274\232", 0));
        label_8->setText(QApplication::translate("MainWindow", "Cache\345\244\247\345\260\217\357\274\232", 0));
        label_CPUName->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        label_CPUType->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        label_CPUFrequency->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        label_CatheCapacity->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\344\277\241\346\201\257", 0));
        label_17->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\347\261\273\345\236\213\357\274\232", 0));
        label_18->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\263\273\347\273\237\347\211\210\346\234\254\357\274\232", 0));
        label_19->setText(QApplication::translate("MainWindow", "GCC\347\274\226\350\257\221\345\231\250\357\274\232", 0));
        label_SystemType->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        label_SystemVersion->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        label_GCCVersion->setText(QApplication::translate("MainWindow", "\346\234\252\347\237\245", 0));
        tabWidget_INFO->setTabText(tabWidget_INFO->indexOf(System), QApplication::translate("MainWindow", "\347\263\273\347\273\237\344\277\241\346\201\257", 0));
        label_21->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\345\220\215\357\274\232", 0));
        label_22->setText(QApplication::translate("MainWindow", "Linux\344\270\213Qt\345\256\236\347\216\260\344\273\273\345\212\241\347\256\241\347\220\206\345\231\250", 0));
        label_23->setText(QApplication::translate("MainWindow", "ljheee  ", 0));
        label_24->setText(QApplication::translate("MainWindow", "\344\275\234\350\200\205\357\274\232", 0));
        label_25->setText(QApplication::translate("MainWindow", "2017-4-10", 0));
        label_26->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\357\274\232", 0));
        label_27->setText(QApplication::translate("MainWindow", "QQ554278334", 0));
        label_28->setText(QApplication::translate("MainWindow", "\350\201\224\347\263\273\357\274\232", 0));
        tabWidget_INFO->setTabText(tabWidget_INFO->indexOf(tab), QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        pushButton_reboot->setText(QApplication::translate("MainWindow", "reboot", 0));
        pushButton_halt->setText(QApplication::translate("MainWindow", "shutdown", 0));
        menuSysMontior->setTitle(QApplication::translate("MainWindow", "SysMontior", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
