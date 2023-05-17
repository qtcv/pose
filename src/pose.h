#ifndef POSE_H
#define POSE_H

#include <QMainWindow>
#include <QTimer>
#include "login_dialog.h"
#include "points_dialog.h"

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
    void on_action_login_triggered();

    void on_action_points_triggered();

    void on_action_logout_triggered();

private:
    Ui::pose *ui;
};
#endif // POSE_H
