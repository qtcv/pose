#include "pose.h"
#include "login_dialog.h"
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


void pose::on_action_login_triggered()
{
    LoginDialog login_dig(this);
    login_dig.resize(600, 600);
    login_dig.exec();
}

