#include "ClusteringWidget.h"

ClusteringWidget::ClusteringWidget(const QRect &rect, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    setGeometry(rect);
    initRawImageWidget();
    initThresholdControlBox();
}

ClusteringWidget::~ClusteringWidget(){
}

void ClusteringWidget::initRawImageWidget(){
    const QRect rect(0, 0, 320, 240);
    rawImageWidget = new RawImageWidget(rect, this);
}

void ClusteringWidget::initThresholdControlBox(){
    const QRect rect(340, 0, 100, 100);
    const QString str("ClassControlBox");
    thresholdControlBox = new ThresholdControlBox(rect, str, this);
}

void ClusteringWidget::clickedRawImage(const QPoint &point){
    thresholdControlBox->update(point);
}

void ClusteringWidget::updateRawImage(QImage *image){
    // update raw image widget
    // threshhold updaterawimage() 
}
