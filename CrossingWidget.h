//
// Created by kiril on 20.05.2023.
//

#ifndef OOP_KURS_CROSSING_CROSSINGWIDGET_H
#define OOP_KURS_CROSSING_CROSSINGWIDGET_H
#include <QWidget>
#include <QPainter>
#include <QLabel>

class CrossingWidget : public QWidget{
Q_OBJECT
unsigned ur,br,bl,ul;
QLabel* frame;
public:
    CrossingWidget(QWidget* parent = 0);
    void setLights(unsigned, unsigned , unsigned , unsigned );
protected:
    void paintEvent(QPaintEvent*);
};


#endif //OOP_KURS_CROSSING_CROSSINGWIDGET_H
