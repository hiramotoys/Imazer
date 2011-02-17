#include "ThresholdSliderBox"

ThresholdSliderBox::ThresholdSliderBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
    setGeometry(rect);
    layout = new QVBoxLayout();
    frSlider = new QSlider();
    connect(SIGNAL(valueChanged(int)), iParent, SLOT(changeThFr(int)));
    toSlider = new QSlider();
    connect(SIGNAL(valueChanged(int)), iParent, SLOT(changeThTo(int)));
    setLayout(layout);
}

ThresholdSliderBox::~ThresholdSliderBox(){
}
