#ifndef POSE_H
#define POSE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class pose; }
QT_END_NAMESPACE

class pose : public QMainWindow
{
    Q_OBJECT

public:
    pose(QWidget *parent = nullptr);
    ~pose();

private:
    Ui::pose *ui;
};
#endif // POSE_H
