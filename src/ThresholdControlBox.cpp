#include "ThresholdControlBox.h"

ThresholdControlBox::ThresholdControlBox(QRect &rect, const QString &title, QWidget *iParent){
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
