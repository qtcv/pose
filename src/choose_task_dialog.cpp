#include "choose_task_dialog.h"
#include "ui_choose_task_dialog.h"

ChooseTaskDialog::ChooseTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseTaskDialog)
{
    ui->setupUi(this);
}

ChooseTaskDialog::~ChooseTaskDialog()
{
    delete ui;
}
