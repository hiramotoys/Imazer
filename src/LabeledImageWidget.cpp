#include "LabeledImageWidget.h"
#include <QRectF>
#include <QPainter>
#include <iostream>


LabeledImageWidget::LabeledImageWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    int width = 320;
    int height = 240;
    image = new QImage(QSize(width, height), QImage::Format_RGB32);
}

LabeledImageWidget::~LabeledImageWidget(){
}

void LabeledImageWidget::paintEvent(QPaintEvent *event){
    if(image == NULL){
	QRectF rect(0, 0, 320, 240);
	QPainter painter(this);
	painter.setBrush(Qt::black);
	painter.drawRect(rect);
	std::cout << "black" << std::endl;
    }
    else{
	QPainter painter(this);
	painter.drawImage(painter.viewport(), *image);
    }
}

void LabeledImageWidget::update(){
    repaint();
}
