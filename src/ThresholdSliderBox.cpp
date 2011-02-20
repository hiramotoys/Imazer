#include "ThresholdSliderBox"

ThresholdSliderBox::ThresholdSliderBox(const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    this->colorAttributeID = colorAttributeID;
    setGeometry(rect);
    layout = new QVBoxLayout();
    frSlider = new QSlider();
    connect(SIGNAL(movedSlider(int)), this, SLOT(changeThFr(int)));
    toSlider = new QSlider();
    connect(SIGNAL(movedSlider(int)), this, SLOT(changeThTo(int)));
    setLayout(layout);
}

ThresholdSliderBox::~ThresholdSliderBox(){
}

void ThresholdSliderBox::changeThFr(int value){
    parentWidget()->updateThFrBySlider(colorAttributeID, value);
}

void ThresholdSliderBox::changeThTo(int value){
    parentWidget()->updateThToBySlider(colorAttributeID, value);
}
