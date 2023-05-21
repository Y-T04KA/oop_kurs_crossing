//
// Created by kiril on 20.05.2023.
//

#include "TComms.h"

TComms::TComms(TCommParams& pars, QObject* parent) :QUdpSocket(parent) {
    params = pars;
    ready = bind(params.rHost, params.rPort, QAbstractSocket::ShareAddress | QAbstractSocket::ReuseAddressHint);
    if (ready) connect(this, SIGNAL(readyRead()), this, SLOT(receive()));
}


void TComms::send(const QByteArray& msg) {
    if (ready) {
        writeDatagram(msg, params.sHost, params.sPort);
    }
}

void TComms::receive() {
    if (hasPendingDatagrams()) {
        quint64 size = pendingDatagramSize();
        QByteArray msg(size, '\0');
        readDatagram(msg.data(), size);
        emit received(msg);
    }
}