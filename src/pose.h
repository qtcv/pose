#ifndef POSE_H
#define POSE_H

#include <QMainWindow>
#include <QTimer>
#include <QFileDialog>
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

    void on_open_act_triggered();

    void on_save_act_triggered();

    void on_play_btn_clicked();

private:
    Ui::pose *ui;

    QString _config_path = QString("config.ini");
    QString _user_name;
    QString _passwd;
    QString _source_path = QString("/Users/liuwen/Downloads/2023.mp4");;
    QString _default_open_dir;
    QString _default_save_dir;

};
#endif // POSE_H
