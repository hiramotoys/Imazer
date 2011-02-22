#include "LabelingWidget.h"
#include <iostream>

LabelingWidget::LabelingWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    QRect rimgRect(0, 80, 320, 240);
    rawImageWidget = new RawImageWidget(rimgRect, this);
    QRect lbimgRect(0, 330, 320, 240);
    labeledImageWidget = new LabeledImageWidget(lbimgRect, this);
    std::cout << "init Labeling widget" << std::endl;
    QRect csRect(0, 0, 360, 70);
    classSelectorBox = new ClassSelectorBox(csRect, "Class Selector", this);
}

LabelingWidget::~LabelingWidget(){
}

void LabelingWidget::updateRawImage(QImage *image){
    rawImageWidget->update(image);
}

void LabelingWidget::clickedRawImage(const QPoint &point){
    int objid = classSelectorBox->getSelectedObjectID();
    std::cout << objid << std::endl;
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
