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


void pose::on_action_login_triggered()
{
    LoginDialog login_dig(this);
    login_dig.resize(600, 600);
    login_dig.exec();
}


void pose::on_action_points_triggered()
{
    PointsDialog points_dig(this);
    points_dig.resize(200, 200);
    points_dig.exec();
}


void pose::on_action_logout_triggered()
{
    QMessageBox *box = new QMessageBox(this);
    box->setIcon(QMessageBox::Information);
    box->setWindowTitle("登出");
    box->setText(tr("登出成功"));
    QTimer::singleShot(1000, box, &QMessageBox::accept);
    box->exec();
}

