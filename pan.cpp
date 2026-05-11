#include "pan.h"

//나는 이프로그래밍 과제를 다른 사람의 부적절한 도움 없이 완수하였습니다


Pan::Pan(int n, QLabel* _flagcnt,Timego* time, QWidget *parent):
    QWidget(parent)
  ,level(n),flagw(_flagcnt),timer(time){
    glay=new QGridLayout(this);
    setLayout(glay);
    switch(level){
    case 0:
        x=10; y=8;
        mines=10;
        setStyleSheet("MyButton {background: rgb(255,179,0)};font-size: 28px;");
        break;
    case 1:
        x=18; y=14;
        mines=40;
        setStyleSheet("MyButton {background: rgb(255,179,0);font-size: 16px;}");
        break;
    case 2:
        x=24; y=20;
        mines=99;
        setStyleSheet("MyButton {background: rgb(255,179,0);font-size: 12px;}");
        break;
    }
    MyButton::flags=mines;
    flagw->setText(QString(" Flags: %1").arg(MyButton::flags));

    glay->setHorizontalSpacing(1);
    glay->setVerticalSpacing(1);

    bts = new MyButton* [y];
    for (int i = 0; i < y; i++)
        bts[i] = new MyButton[x];

    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            glay->setColumnStretch(j,1); //equal column width
            bts[i][j].setMinimumSize(30,30);
            QSizePolicy temp = bts[i][j].sizePolicy();
            temp.setVerticalPolicy(temp.horizontalPolicy());
            bts[i][j].setSizePolicy(temp); //design optimization

            glay->addWidget(&(bts[i][j]),i,j);
            bts[i][j].cx=j;
            bts[i][j].cy=i; //self position info
            bts[i][j].setText(QString(" "));
            connect(&bts[i][j],SIGNAL(frefresh()),this,SLOT(frefresh_slot()));
            connect(&bts[i][j],SIGNAL(lost()),this,SLOT(lost_slot()));
            connect(&bts[i][j],SIGNAL(opensignal(int,int)),this,SLOT(open_slot(int,int)));
        }
    }

    std::vector<std::pair<int,int>> foo; //random mine algorithm begin
    for(int i=0;i<y;++i){
        for(int j=0;j<x;++j){
            foo.push_back(std::make_pair(i,j));
        }
    } //button position list vector
    qDebug()<<"random="<<foo.size();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(foo.begin(), foo.end(), std::default_random_engine(seed)); //first some element become mine
        for(int p=0;p<mines;++p){
            //qDebug()<<"random ("<<p<<")="<<foo.at(p);
            bts[foo.at(p).first][foo.at(p).second].type=-1;
            bts[foo.at(p).first][foo.at(p).second].label="!";

    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
        int sum=0;
        if(bts[i][j].type!=-1){
            if(i-1>-1 && j-1>-1){
                if(bts[i-1][j-1].type==-1) ++sum;
            }
            if(i-1>-1){
                if(bts[i-1][j].type==-1) ++sum;
            }
            if(i-1>-1 && j+1<x) {
                if(bts[i-1][j+1].type==-1) ++sum;
            }
            if(j-1>-1){
                if(bts[i][j-1].type==-1) ++sum;
            }
            if(j+1<x) {
                if(bts[i][j+1].type==-1) ++sum;
            }

            if(i+1<y && j-1>-1) {
                if(bts[i+1][j-1].type==-1) ++sum;
            }
            if(i+1<y) {
                if(bts[i+1][j].type==-1) ++sum;
            }
            if(i+1<y && j+1<x) {
                if(bts[i+1][j+1].type==-1) ++sum;
            }
            bts[i][j].type=sum; bts[i][j].label=QString::number(sum); //surrounding(8) mine count inject
        }
    }
}
} //end constructor

Pan::~Pan(){
    for (int i = 0; i < y; i++)
        delete[] bts[i];
    delete[] bts;
    delete glay;
}



void Pan::frefresh_slot(){ //refresh
    flagw->setText(QString(" Flags: %1").arg(MyButton::flags)); //flag refresh
    timer->gogo();
    //qDebug()<<MyButton::opencnt;
    if(MyButton::opencnt==x*y-mines){ //whether all opened
        MyButton::winlose=1;
        for(int i=0;i<y;i++){
            for(int j=0;j<x;j++){
                bts[i][j].open();
            }
        }
        flagw->setText(" You Win !");
        timer->stop();
    }
}
void Pan::lost_slot(){
    MyButton::winlose=-1;
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(bts[i][j].type==-1)
            bts[i][j].open(); //open all mine
        }
    }
    flagw->setText(" You Lost !");
    timer->stop();

}

void Pan::open_slot(int cx,int cy){ //check and open surrounding 8 blocks
    if(cy-1>-1 && cx-1>-1){
        bts[cy-1][cx-1].open();
    }
    if(cy-1>-1){
        bts[cy-1][cx].open();
    }
    if(cy-1>-1 && cx+1<x) {
        bts[cy-1][cx+1].open();
    }
    if(cx-1>-1){
        bts[cy][cx-1].open();
    }
    if(cx+1<x) {
        bts[cy][cx+1].open();
    }

    if(cy+1<y && cx-1>-1) {
        bts[cy+1][cx-1].open();
    }
    if(cy+1<y) {
        bts[cy+1][cx].open();
    }
    if(cy+1<y && cx+1<x) {
        bts[cy+1][cx+1].open();
    }

}


