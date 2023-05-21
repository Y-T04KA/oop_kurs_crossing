//
// Created by kiril on 20.05.2023.
//

#ifndef OOP_KURS_CROSSING_TCROSSINGINTERFACE_H
#define OOP_KURS_CROSSING_TCROSSINGINTERFACE_H
#include <QApplication>
#include <QObject>
#include "TComms.h"
#include "common.h"
#include "CrossingWidget.h"
#include <QTimer>

class TCrossingInterface : public QApplication {
    Q_OBJECT
    TComms* comm;
    CrossingWidget* cw;
    bool state = false;
    unsigned time = 2000;
    QTimer *timer = new QTimer(this);
    QTimer* oto = new QTimer(this);
    QTimer* ye = new QTimer(this);
public:
    TCrossingInterface(int, char**);
public slots:
    void receive(const QByteArray&);
    void blink();
    void autoCycle();
    void autoyell();
};


#endif //OOP_KURS_CROSSING_TCROSSINGINTERFACE_H
