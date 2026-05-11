#include "mybutton.h"

//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


MyButton::MyButton(QWidget *parent):QPushButton(parent){
    connect(this,SIGNAL(rightClick()),this,SLOT(rclick()));
    connect(this,SIGNAL(clicked()),this,SLOT(lclick()));
};

MyButton::~MyButton()=default;

void MyButton::mousePressEvent(QMouseEvent *e){
 if(e->button() == Qt::RightButton){
 emit rightClick();
 }
 QPushButton::mousePressEvent(e);
}

void MyButton::rclick(){
    if(!winlose){
    if(!opened){
        if(flagon){
            setStyleSheet("");
            flagon=0;
            ++flags;
        }
        else{
            setStyleSheet("background: rgb(200,1,80)");
            flagon=1;
            --flags;
        }
    }
    emit frefresh();
    }
}


void MyButton::lclick(){
    if(!winlose){
        if(!opened){
            if(type==-1) emit lost(); //game lose
            else open();
        }
    }
}

void MyButton::open(){
    if(opened){
        if(winlose==1)
            setStyleSheet("background: cyan"); //for final win
    }
    else{
        if(type==0){
            setStyleSheet("background: azure");
            setText(QString(" "));
            opened=1;
            opencnt++;
            if(flagon){
            flagon=0;
            ++flags;
            }
            emit frefresh(); //refresh status
            emit opensignal(cx,cy); //it is opened

        } else if(type==-1){ //bomb present
            if(winlose==1)
                setStyleSheet("background: pink"); //final winning
            else
            setStyleSheet("background: red");

            setText(label);
            opened=1;
            if(flagon){ //restore flags if flagged
            flagon=0;
            ++flags;
            }
        } else{
            setText(label);
            setStyleSheet("background: wheat");
            opened=1;
            opencnt++;
            if(flagon){ //restore flags if flagged
            flagon=0;
            ++flags;
            }
            emit frefresh(); //refresh status

        }
    }
}

