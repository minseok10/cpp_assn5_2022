#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qboxlayout.h"
#include <QMainWindow>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include "timego.h"
#include "pan.h"


//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVBoxLayout *vlay;
    QHBoxLayout *hlay;
    QComboBox *level;
    Timego *time;
    QLabel *flagcnt;
    Pan *pan;
    QPushButton *rstbtn;

    void panGen();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void resett();


};
#endif // MAINWINDOW_H


