#ifndef POSE_H
#define POSE_H

#include <QMainWindow>
#include <QTimer>
#include "login_dialog.h"
#include "points_dialog.h"
#include "choose_task_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class pose; }
QT_END_NAMESPACE

class pose : public QMainWindow
{
    Q_OBJECT

public:
    pose(QWidget *parent = nullptr);
    ~pose();

private slots:

    void on_logout_act_triggered();

    void on_points_act_triggered();

    void on_login_act_triggered();

    void on_choose_task_triggered();

private:
    Ui::pose *ui;
};
#endif // POSE_H
