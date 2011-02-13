#include "RawImageWidget.h"
#include <iostream>

RawImageWidget::RawImageWidget(QWidget *iParent, Qt::WindowFlags iFlags){
}

RawImageWidget::~RawImageWidget(){
}

void update(QImage *image){
}

void paintEvent(QPaintEvent *event){
}

void mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
	parentWidget->clicledRawImage(event->pos());
	std::cout << "clicked " << event->pos().x() << " " << event->pos().y() << std::endl;
    }
}
