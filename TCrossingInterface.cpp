//
// Created by kiril on 20.05.2023.
//

#include "TCrossingInterface.h"

TCrossingInterface::TCrossingInterface(int argc, char* argv[]) : QApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"),10000, QHostAddress("127.0.0.1"),10001 };
    comm = new TComms(pars, this);
    cw = new CrossingWidget();
    cw->show();
    connect(comm, SIGNAL(received(QByteArray)), this, SLOT(receive(QByteArray)));
    connect(timer, SIGNAL(timeout()), this, SLOT(blink()));
    connect(oto, SIGNAL(timeout()), this, SLOT(autoCycle()));
    connect(ye, SIGNAL(timeout()), this, SLOT(autoyell()));
}

void TCrossingInterface::receive(const QByteArray& msg) {
    QString input,answer;
    timer->stop();
    oto->stop();
    ye->stop();
    input = QString(msg);
    if (input.contains(separator)){
        QStringList split = input.split(separator);
        if (split[0]==split[1] && split[1]==split[2] && split[2]==split[3] && split[3]=="2"){
            timer->start(1000);
        } else cw->setLights(split[0].toShort(),split[1].toShort(),split[2].toShort(),split[3].toShort());
        cw->update();
    } else {
        if (input=="0") { cw->setLights(0,0,0,0);
        cw->update();} else{
            time = input.toInt()*1000;
            oto->start(time);
            ye->setInterval(time);
            QTimer::singleShot(time-time/10,ye,SLOT(start()));
        }
    }
    comm->send(QByteArray().append(answer.toUtf8()));
}

void TCrossingInterface::blink() {
    if (state){
        cw->setLights(0,0,0,0);
        cw->update();
        state=false;
    } else {
        cw->setLights(2,2,2,2);
        cw->update();
        state=true;
    }
}

void TCrossingInterface::autoCycle() {
    if (state){
        cw->setLights(1,3,1,3);
        cw->update();
        state= false;
    } else {
        cw->setLights(3,1,3,1);
        cw->update();
        state=true;
    };
}

void TCrossingInterface::autoyell() {
    cw->setLights(2,2,2,2);
    cw->update();
}
