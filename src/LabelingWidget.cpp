#include "LabelingWidget.h"
#include <iostream>

LabelingWidget::LabelingWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    QRect rimgRect(0, 0, 320, 240);
    rawImageWidget = new RawImageWidget(rimgRect, this);
    QRect lbimgRect(0, 250, 320, 240);
    labeledImageWidget = new LabeledImageWidget(lbimgRect, this);
    std::cout << "init Labeling widget" << std::endl;
}

LabelingWidget::~LabelingWidget(){
}

void LabelingWidget::updateRawImage(QImage *image){
    rawImageWidget->update(image);
}

void LabelingWidget::clickedRawImage(const QPoint &point){
}

void LabelingWidget::movedrgbThBallSlider(){
}

void LabelingWidget::movedrgbThGreenSlider(){
}

void LabelingWidget::movedrgbThLinesSlider(){
}

void LabelingWidget::movedrgbThGoalYellowSlider(){
}

void LabelingWidget::movedrgbThGoalBlueSlider(){
}
