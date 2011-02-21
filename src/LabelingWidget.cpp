#include "LabelingWidget.h"

LabelingWidget::LabelingWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    QRect rimageWidget(0, 0, 320, 240);
    rawImageWidget = new RawImageWidget(rimageWidget, this);
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
