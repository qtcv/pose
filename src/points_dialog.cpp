#include "points_dialog.h"
#include "ui_points_dialog.h"

PointsDialog::PointsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointsDialog)
{
    ui->setupUi(this);
}

PointsDialog::~PointsDialog()
{
    delete ui;
}

void PointsDialog::on_buy_points_btn_clicked()
{
    QMessageBox::about(this, "购买积分", "请联系xxx");
}

