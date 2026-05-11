#include "mainwindow.h"
#include "ui_mainwindow.h"


//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet("background: rgb(102,102,92); font-size: 18px;"); //global designsheet

    vlay = new QVBoxLayout();
    hlay = new QHBoxLayout();
    pan = nullptr;
    level = new QComboBox(ui->centralwidget);
    level->addItems({"Easy","Medium","Hard"});
    level->setStyleSheet("background: white");
    time = new Timego(ui->centralwidget);
    flagcnt = new QLabel(ui->centralwidget);
    rstbtn = new QPushButton("Reset", ui->centralwidget);

    vlay->addLayout(hlay);


    hlay->addWidget(level);
    hlay->addWidget(flagcnt);
    hlay->addWidget(time);
    hlay->addWidget(rstbtn);
    ui->centralwidget->setLayout(vlay);

    resett(); //initial reset
    connect(level,SIGNAL(currentIndexChanged(int)),this,SLOT(resett()));
    connect(rstbtn,SIGNAL(pressed()),this,SLOT(resett()));


}


void MainWindow::resett()
{
    time->zero();
    MyButton::winlose=0;
    MyButton::opencnt=0;
    panGen();
}

void MainWindow::panGen(){ //game plate new generate
    if (pan!=nullptr){
        delete pan;
        pan = nullptr;
    }
    pan = new Pan(level->currentIndex(),flagcnt,time,ui->centralwidget);
    vlay->addWidget(pan);
}

MainWindow::~MainWindow()
{
    delete ui;
}
