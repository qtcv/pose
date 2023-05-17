#ifndef POINTS_DIALOG_H
#define POINTS_DIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class PointsDialog;
}

class PointsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointsDialog(QWidget *parent = nullptr);
    ~PointsDialog();

private slots:
    void on_buy_points_btn_clicked();

    void on_points_exit_btn_clicked();

private:
    Ui::PointsDialog *ui;
};

#endif // POINTS_DIALOG_H
