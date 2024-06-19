#include "mainwindow.h"
#include "ui_mainwindow.h"

extern int16_t TouchFlag , TouchX , TouchY ;
extern MainWindow * pMainWindow ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pMainWindow = this ;

    this->setGeometry(0 , 0 , MY_DISP_HOR_RES , MY_DISP_VER_RES + 25) ;

    ui->label->setGeometry(0 , 0 , MY_DISP_HOR_RES , MY_DISP_VER_RES) ;

    pImage = new QImage(MY_DISP_HOR_RES , MY_DISP_VER_RES , QImage::Format_RGB888) ;


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(onTimeout()));
    timer->start(10);


    lv_init();
    lv_port_disp_init() ;
    lv_port_indev_init();

    lvgl_example() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}
//鼠标移动触发
void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    TouchX = ev->x() ;
    TouchY = ev->y() ;
}
//鼠标按下触发
void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        TouchX = ev->x() ; TouchY = ev->y() ;
        TouchFlag = 1 ;
    }
}
//鼠标释放触发
void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        TouchX = ev->x() ; TouchY = ev->y() ;
        TouchFlag = 0 ;
    }
}
void MainWindow::onTimeout()
{
    lv_tick_inc(10) ;
    lv_task_handler();


    //QTime tim = QDateTime::currentDateTime().time() ;
    //AnalogClock_Set_Time(tim.hour()%12, tim.minute()%60 , tim.second()%60) ;
}
