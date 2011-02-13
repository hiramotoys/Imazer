#include "LabeledImageWidget.h"

LabeledImageWidget::LabeledImageWidget(QWidget *iParent, Qt::WindowFlags iFlags){
}

LabeledImageWidget::~LabeledImageWidget(){
}

void LabeledImageWidget::update(QImage *image){
    this->image = image;
}

void LabeledImageWidget::paintEvent(QPaintEvent *event){
}
