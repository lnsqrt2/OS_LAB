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
    QString cpu_hz;
    QString p_name;
    QString pid;
    QString ppid;
    QString p_stat;
    QString p_mem;
    QString p_pri;
    QTimer *Timer;
    QTimer *Timer1;
    int tab_num;
    int item_num;
    int totalCpuTime;
    int idleTime;
    int cpu_rate;
    int info[20];
    int count;

private slots:
    void on_button_search_clicked();

    void on_button_kill_clicked();

    void on_button_refcpu_clicked();

private:
    Ui::TaskManager *ui;
    void show_info(int tab_num);
    void update_info();
    bool eventFilter(QObject *obj, QEvent *e);
    void draw(int tab_index);
    void cpu_drawdone();
};

#endif // TASKMANAGER_H
