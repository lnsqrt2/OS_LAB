#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QWidget>
#include <QFile>
#include <QTime>

namespace Ui {
class TaskManager;
}

class TaskManager : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManager(QWidget *parent = 0);
    ~TaskManager();

    QFile file;
    QString pc_name;
    QString boot_time;
    QString run_time;
    QString cpu_name;
    QString cpu_version;
    QTimer *Timer;
    int tab_num;

private:
    Ui::TaskManager *ui;
    void show_info(int tab_num);
    void update_info();
};

#endif // TASKMANAGER_H
