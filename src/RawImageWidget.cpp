#include "RawImageWidget.h"
#include "LabelingWidget.h"
#include <iostream>

RawImageWidget::RawImageWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    std::cout << "init rawimagewidget" << std::endl;
    this->image = NULL;
}

RawImageWidget::~RawImageWidget(){
}

void RawImageWidget::update(QImage *image){
    this->image = image;
    repaint();
}

void RawImageWidget::paintEvent(QPaintEvent *event){
    std::cout << "paint event" << std::endl;
    std::cout << this->image << std::endl;
    if(!this->image->isNull()){
	std::cout << "!NULL" << std::endl;
	QPainter painter(this);
	painter.drawImage(painter.viewport(), *image);
	std::cout << "painted" << std::endl;
    }
}

void RawImageWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
	((LabelingWidget*)parentWidget())->clickedRawImage(event->pos());
	std::cout << "clicked " << event->pos().x() << " " << event->pos().y() << std::endl;
    }
}
