#include "ThresholdSliderBox.h"
#include "HSVThresholdControlBox.h"

ThresholdSliderBox::ThresholdSliderBox(int min, int max, const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    this->colorAttributeID = colorAttributeID;
    setGeometry(rect);
    layout = new QVBoxLayout();
    frSlider = new QSlider(Qt::Horizontal);
    frSlider->setRange(min, max);
    connect(frSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThFr(int)));
    layout->addWidget(frSlider);
    toSlider = new QSlider(Qt::Horizontal);
    toSlider->setRange(min, max);
    connect(toSlider, SIGNAL(sliderMoved(int)), this, SLOT(changeThTo(int)));
    layout->addWidget(toSlider);
    setLayout(layout);
}

ThresholdSliderBox::~ThresholdSliderBox(){
}

void ThresholdSliderBox::changeThFr(int value){
    ((HSVThresholdControlBox *)(parentWidget()))->updateThFrBySlider(colorAttributeID, value);
}

void ThresholdSliderBox::changeThTo(int value){
    ((HSVThresholdControlBox *)(parentWidget()))->updateThToBySlider(colorAttributeID, value);
}

void ThresholdSliderBox::setValue(int fr, int to){
    frSlider->setValue(fr);
    toSlider->setValue(to);
}

void ThresholdSliderBox::setRange(int min, int max){
    frSlider->setRange(min, max);
    toSlider->setRange(min, max);
}
