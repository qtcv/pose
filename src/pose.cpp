#include "pose.h"
#include "ui_pose.h"

pose::pose(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pose)
{
    ui->setupUi(this);
}

pose::~pose()
{
    delete ui;
}

