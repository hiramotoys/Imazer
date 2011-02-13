#include "ClusteredImageWidget.h"

ClusteredImageWidget::ClusteredImageWidget(QWidget *iParent, Qt::WindowFlags iFlags){
}

ClusteredImageWidget::~ClusteredImageWidget(){
}

void ClusteredImageWidget::update(QImage *image){
    this->image = image;
}

void ClusteredImageWidget::paintEvent(QPaintEvent *event){
}
