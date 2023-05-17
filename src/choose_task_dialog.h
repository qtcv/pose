#ifndef CHOOSE_TASK_DIALOG_H
#define CHOOSE_TASK_DIALOG_H

#include <QDialog>

namespace Ui {
class ChooseTaskDialog;
}

class ChooseTaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTaskDialog(QWidget *parent = nullptr);
    ~ChooseTaskDialog();

private:
    Ui::ChooseTaskDialog *ui;
};

#endif // CHOOSE_TASK_DIALOG_H
