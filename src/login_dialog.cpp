#include "login_dialog.h"
#include "ui_login_dialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_login_Button_clicked()
{
    if((ui->username_edit->text() == "test") && (ui->passwd_edit->text() == "123"))
    {
        this->hide();
        qInfo() << "YES";
    }
    else {
        QMessageBox::critical(this, "critical", "密码错误");
        qInfo() << "NO";
    }

}

