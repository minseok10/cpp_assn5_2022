#include "mybutton.h"

int MyButton::flags = 0; //static member var
int MyButton::winlose = 0; //static member var
int MyButton::opencnt = 0; //static member var

static QString boxStyle(const QString& color)
{
    return QString("background: %1; color: black; border: 1px solid rgb(65,65,58); margin: 0px; padding: 0px;").arg(color);
}

//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


MyButton::MyButton(QWidget *parent):QPushButton(parent){
    connect(this,SIGNAL(rightClick()),this,SLOT(rclick()));
    connect(this,SIGNAL(clicked()),this,SLOT(lclick()));
};

MyButton::~MyButton()=default;

void MyButton::mousePressEvent(QMouseEvent *e){
 if(e->button() == Qt::RightButton){
 emit rightClick();
 return;
 }
 QPushButton::mousePressEvent(e);
}

void MyButton::rclick(){
    if(!winlose){
    if(!opened){
        if(flagon){
            setStyleSheet(boxStyle("rgb(255,179,0)"));
            flagon=0;
            ++flags;
        }
        else{
            if(flags <= 0)
                return;
            setStyleSheet(boxStyle("rgb(200,1,80)"));
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
            if(flagon)
                return;
            if(opencnt == 0)
                emit firstClick(cx,cy);
            if(type==-1) emit lost(); //game lose
            else open();
        }
    }
}

void MyButton::open(){
    if(opened){
        if(winlose==1)
            setStyleSheet(boxStyle("cyan")); //for final win
    }
    else{
        if(type==0){
            setStyleSheet(boxStyle("azure"));
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
                setStyleSheet(boxStyle("pink")); //final winning
            else
            setStyleSheet(boxStyle("red"));

            setText(label);
            opened=1;
            if(flagon){ //restore flags if flagged
            flagon=0;
            ++flags;
            }
        } else{
            setText(label);
            setStyleSheet(boxStyle("wheat"));
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

