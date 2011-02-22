#include "ThresholdSliderBox.h"

ThresholdSliderBox::ThresholdSliderBox(const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    this->colorAttributeID = colorAttributeID;
    setGeometry(rect);
    layout = new QVBoxLayout();
    frSlider = new QSlider(Qt::Horizontal);
    connect(frSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThFr(int)));
    layout->addWidget(frSlider);
    toSlider = new QSlider(Qt::Horizontal);
    connect(toSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThTo(int)));
    layout->addWidget(toSlider);
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
