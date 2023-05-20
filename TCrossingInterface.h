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

class TCrossingInterface : public QApplication {
    Q_OBJECT
    TComms* comm;
    CrossingWidget* cw;
public:
    TCrossingInterface(int, char**);
public slots:
    void receive(QByteArray);
};


#endif //OOP_KURS_CROSSING_TCROSSINGINTERFACE_H
