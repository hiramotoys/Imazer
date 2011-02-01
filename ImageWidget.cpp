#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    label = new QLabel("test");
    layout = new QHBoxLayout();
    layout->addWidget(label);
    setLayout(layout);
}

ImageWidget::~ImageWidget(){
}


