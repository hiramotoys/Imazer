#include "LabeledImageWidget.h"
#include <QRectF>
#include <QPainter>
#include <iostream>


LabeledImageWidget::LabeledImageWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
}

LabeledImageWidget::~LabeledImageWidget(){
}

void LabeledImageWidget::paintEvent(QPaintEvent *event){
    QRectF rect(0, 0, 320, 240);
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(rect);
    std::cout << "black" << std::endl;
}

void LabeledImageWidget::update(QImage *update){
}
