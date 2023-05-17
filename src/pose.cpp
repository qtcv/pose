#include "pose.h"
#include "ui_pose.h"

pose::pose(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pose)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(tr("AI pose"));
}

pose::~pose()
{
    delete ui;
}


void pose::on_logout_act_triggered()
{
    QMessageBox *box = new QMessageBox(this);
    box->setIcon(QMessageBox::Information);
    box->setWindowTitle("登出");
    box->setText(tr("登出成功"));
    QTimer::singleShot(1000, box, &QMessageBox::accept);
    box->exec();
}


void pose::on_points_act_triggered()
{
    PointsDialog points_dig(this);
    points_dig.resize(200, 200);
    points_dig.exec();
}


void pose::on_login_act_triggered()
{
    LoginDialog login_dig(this);
    login_dig.resize(600, 600);
    login_dig.exec();
}


void pose::on_choose_task_triggered()
{
    ChooseTaskDialog choose_task_dig(this);
    choose_task_dig.resize(600, 600);
    choose_task_dig.exec();
}

