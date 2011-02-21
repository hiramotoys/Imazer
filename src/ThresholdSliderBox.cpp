#include "ThresholdSliderBox.h"

ThresholdSliderBox::ThresholdSliderBox(const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    this->colorAttributeID = colorAttributeID;
    setGeometry(rect);
    layout = new QVBoxLayout();
    frSlider = new QSlider();
    connect(frSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThFr(int)));
    toSlider = new QSlider();
    connect(toSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThTo(int)));
    setLayout(layout);
}

ThresholdSliderBox::~ThresholdSliderBox(){
}

void ThresholdSliderBox::changeThFr(int value){
    //parentWidget()->updateThFrBySlider(colorAttributeID, value);
}

void ThresholdSliderBox::changeThTo(int value){
    //parentWidget()->updateThToBySlider(colorAttributeID, value);
}

void ThresholdSliderBox::setValue(int fr, int to){
    frSlider->setValue(fr);
    toSlider->setValue(to);
}
