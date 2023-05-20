//
// Created by kiril on 20.05.2023.
//

#include "CrossingWidget.h"

CrossingWidget::CrossingWidget(QWidget *parent) {
    setFixedSize(600,600);
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
    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);

    //Upper-Right
    painter.drawRect(center+offset,center+offset,lwidth,lheight);

    //Bottom-Right
    painter.drawRect(center+offset,center-offset,lwidth,lheight);

    //Bottom-Left
    painter.drawRect(center-offset, center-offset, lwidth, lheight);

    //Upper-Left
    painter.drawRect(center-offset,center+offset,lwidth,lheight);

}
