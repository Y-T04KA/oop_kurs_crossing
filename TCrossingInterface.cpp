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
}

void TCrossingInterface::receive(QByteArray msg) {
    QString input,answer;
    input = QString(msg);
    if (input.contains(separator)){
        //manual lights
        QStringList split = input.split(separator);
        int one = split[0].toShort();
        //something-something(split[0].toShort(),split[1].toShort(),split[2].toShort(),split[0].toShort());
        answer += "Светофор в ручном управлении";
    } else {
        //time or off
        answer += "Светофор в автоматическом режиме";
    }
    comm->send(QByteArray().append(answer.toUtf8()));
}
