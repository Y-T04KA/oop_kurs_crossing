//
// Created by kiril on 20.05.2023.
//

#include "CrossingWidget.h"

CrossingWidget::CrossingWidget(QWidget *parent) {
    setFixedSize(600,800);
    ur = 0; br = 0; bl = 0; ul = 0;
    frame = new QLabel(this);
    frame->setObjectName("label_but_picture");
    frame->setGeometry(QRect(0, 0, 600, 600));
    frame->setPixmap(QPixmap("/Frame.png"));
    frame->setScaledContents(true);
}

void CrossingWidget::setLights(unsigned int ur_, unsigned int br_, unsigned int bl_, unsigned int ul_) {
    ur = ur_; br = br_; bl = bl_; ul = ul_;
}

void CrossingWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    int center = 300;
    int offset = 100;
    int lheight = 240;
    int lwidth = 80;
    ///
    auto c = Qt::red;
    painter.setBrush(c);
    ////
    painter.setBrush(Qt::black);
    painter.setPen(Qt::white);

    int base_right = center+2*offset-lwidth;
    int base_left = center-2*offset;
    int baseu = center+50-3*offset;
    int baseb = center+offset;
    int yellowOffset = 3*(lwidth/3);
    int greenOffset = 6*(lwidth/3);
    //Upper-Right lightframe
    painter.drawRect(base_right,baseu,lwidth,lheight);
    //Bottom-Right lightframe
    painter.drawRect(base_right,baseb,lwidth,lheight);
    //Bottom-Left lightframe
    painter.drawRect(base_left, baseb, lwidth, lheight);
    //Upper-Left lightframe
    painter.drawRect(base_left,baseu,lwidth,lheight);

    //Upper-Right lightbulbs
    switch (ur) {
        case 1:{//red
            painter.setBrush(Qt::red);
            painter.drawEllipse(base_right,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        case 2:{//yellow
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseu,lwidth,lwidth);
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(base_right,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        case 3:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::green);
            painter.drawEllipse(base_right,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        default:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseu+greenOffset,lwidth,lwidth);
        }
            break;
    };
    switch (br) {
        case 1:{//red
            painter.setBrush(Qt::red);
            painter.drawEllipse(base_right,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        case 2:{//yellow
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseb,lwidth,lwidth);
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(base_right,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        case 3:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::green);
            painter.drawEllipse(base_right,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        default:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_right,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_right,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_right,baseb+greenOffset,lwidth,lwidth);
        }
            break;
    };
    switch (bl) {
        case 1:{//red
            painter.setBrush(Qt::red);
            painter.drawEllipse(base_left,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        case 2:{//yellow
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseb,lwidth,lwidth);
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(base_left,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        case 3:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::green);
            painter.drawEllipse(base_left,baseb+greenOffset,lwidth,lwidth);
        }
            break;
        default:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseb,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseb+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseb+greenOffset,lwidth,lwidth);
        }
            break;
    };
    switch (ul) {
        case 1:{//red
            painter.setBrush(Qt::red);
            painter.drawEllipse(base_left,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        case 2:{//yellow
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseu,lwidth,lwidth);
            painter.setBrush(Qt::yellow);
            painter.drawEllipse(base_left,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        case 3:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::green);
            painter.drawEllipse(base_left,baseu+greenOffset,lwidth,lwidth);
        }
            break;
        default:{
            painter.setBrush(Qt::darkRed);
            painter.drawEllipse(base_left,baseu,lwidth,lwidth);
            painter.setBrush(Qt::darkYellow);
            painter.drawEllipse(base_left,baseu+yellowOffset,lwidth,lwidth);
            painter.setBrush(Qt::darkGreen);
            painter.drawEllipse(base_left,baseu+greenOffset,lwidth,lwidth);
        }
            break;
    }



}
