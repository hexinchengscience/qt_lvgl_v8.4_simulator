#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMouseEvent>
#include <QDateTime>
#include <QLabel>
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "example/lvgl_example.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Ui::MainWindow *ui;
    QImage *pImage ;
protected:
    //重写虚函数
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *ev);
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *ev);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *ev);

private slots:

   void onTimeout() ;

private:

    QTimer *timer;

};
#endif // MAINWINDOW_H
