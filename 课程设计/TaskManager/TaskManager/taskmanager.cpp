#include "taskmanager.h"
#include "ui_taskmanager.h"

TaskManager::TaskManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);
}

TaskManager::~TaskManager()
{
    delete ui;
}

void TaskManager::show_info()
{

}
