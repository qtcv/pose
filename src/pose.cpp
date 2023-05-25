#include "pose.h"
#include "ui_pose.h"


pose::pose(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pose)
{
    ui->setupUi(this);
    ui->statusbar->showMessage(tr("AI pose"));

    m_pTimer = new QTimer;
    m_pTimer->setInterval(30);
    connect(m_pTimer, &QTimer::timeout, this, &pose::playTimer);

    InitVideo();
}

pose::~pose()
{
    delete ui;
}


// 延时函数
void delay(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


void pose::on_logout_act_triggered()
{
    QMessageBox *box = new QMessageBox(this);
    box->setIcon(QMessageBox::Information);
    box->setWindowTitle("登出");
    box->setText(tr("登出成功"));
    QTimer::singleShot(1000, box, &QMessageBox::accept);
    box->exec();
}


void pose::on_points_act_triggered()
{
    PointsDialog points_dig(this);
    points_dig.resize(200, 200);
    points_dig.exec();
}


void pose::on_login_act_triggered()
{
    LoginDialog login_dig(this);
    login_dig.resize(600, 600);
    login_dig.exec();
}


void pose::on_choose_task_triggered()
{
    ChooseTaskDialog choose_task_dig(this);
    choose_task_dig.resize(600, 600);
    choose_task_dig.exec();
}


void pose::on_open_act_triggered()
{
    _source_path = QFileDialog::getOpenFileName(this, QString("选择视频文件"), _default_open_dir);
    if (_source_path.isEmpty())
    {
        return;
    }
    else
    {
        qDebug() << "视频文件:" << _source_path << "\n";
    }
}


void pose::on_save_act_triggered()
{
    QString save_dir = QFileDialog::getExistingDirectory(this, QString("选择保存目录"), _default_save_dir);
    if (save_dir.isEmpty())
    {
        return;
    }
    else
    {
        qDebug() << "保存目录:" << save_dir << "\n";
    }
}


void pose::on_play_btn_clicked()
{
    m_pTimer->start();
}

void pose::playTimer()
{
    Mat frame;

    //从cap中读取一帧数据，存到fram中
    *m_pVideo >> frame;
    if ( frame.empty() )
    {
        return;
    }
    cv::cvtColor(frame, frame, COLOR_BGR2RGB);//图像格式转换
    QImage disImage = QImage((const unsigned char*)(frame.data),frame.cols,frame.rows,frame.cols*frame.channels(),QImage::Format_RGB888);
    ui->video_label->setPixmap(QPixmap::fromImage(disImage));//显示图像
}

void pose::InitVideo()
{
    qInfo() << _source_path;
    m_pVideo = new VideoCapture(_source_path.toStdString());
}

