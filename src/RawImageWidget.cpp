#include "RawImageWidget.h"
#include "ClusteringWidget.h"
#include <iostream>

RawImageWidget::RawImageWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
}

RawImageWidget::~RawImageWidget(){
}

void RawImageWidget::update(QImage *image){
}

void RawImageWidget::paintEvent(QPaintEvent *event){
}

void RawImageWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
	((ClusteringWidget*)parentWidget())->clickedRawImage(event->pos());
	std::cout << "clicked " << event->pos().x() << " " << event->pos().y() << std::endl;
    }
}
