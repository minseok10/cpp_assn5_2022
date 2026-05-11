#include "timego.h"


//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


void Timego::gogo(){
    if(!running){
    timer.setInterval(80); timer.start(); //update rate arbitary
    timex.restart(); }
    running=1;
}

void Timego::zero(){
    timer.stop(); setText("0.0"); timex.invalidate(); running=0;
}

void Timego::stop(){
    timer.stop(); timex.invalidate(); running=0;
}

void Timego::up(){
    if(timex.isValid())
        setText(QString::number(timex.elapsed()/1000.0, 'f', 1)); //update time
    else setText("error"); //should not shown
}


