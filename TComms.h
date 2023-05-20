//
// Created by kiril on 20.05.2023.
//

#ifndef OOP_KURS_CROSSING_TCOMMS_H
#define OOP_KURS_CROSSING_TCOMMS_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>


struct TCommParams {
    QHostAddress rHost{};
    quint16 rPort{};
    QHostAddress sHost{};
    quint16 sPort{};
};

class TComms : public QUdpSocket
{
    Q_OBJECT
    bool ready;
    TCommParams params;
public:
    TComms(TCommParams&, QObject* parent = nullptr);
    bool isReady();
    signals:
            void received(QByteArray);
public slots:
            void send(QByteArray);
private slots:
            void receive();
};



#endif //OOP_KURS_CROSSING_TCOMMS_H
