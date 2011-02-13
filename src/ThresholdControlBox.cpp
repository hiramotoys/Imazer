#include "ThresholdControlBox.h"

ThresholdControlBox::ThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent) : QGroupBox(title, iParent){
}

ThresholdControlBox::~ThresholdControlBox(){
}

void ThresholdControlBox::updateImage(QImage *image){
    rawImage = image;
}

void ThresholdControlBox::update(const QPoint &point){
    // update threshold
    // refresh slider bar
    // refresh clustered widget
}
