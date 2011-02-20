#include "RawImageWidget.h"
#include "LabelingWidget.h"
#include <iostream>

RawImageWidget::RawImageWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    image->load("../test/00000018.png");
}

RawImageWidget::~RawImageWidget(){
}

void RawImageWidget::update(QImage *image){
    this->image = image;
    repaint();
}

void RawImageWidget::paintEvent(QPaintEvent *event){
    if(this->image != NULL){
	QPainter painter(this);
	painter.drawImage(painter.viewport(), *image);
    }
}

void RawImageWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
	((LabelingWidget*)parentWidget())->clickedRawImage(event->pos());
	std::cout << "clicked " << event->pos().x() << " " << event->pos().y() << std::endl;
    }
}
