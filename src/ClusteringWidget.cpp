#include "ClusteringWidget.h"

ClusteringWidget::ClusteringWidget(QWidget *iParent, Qt::WindowFlags iFlags){
}

ClusteringWidget::~ClusteringWidget(){
}

void ClusteringWidget::clickedRawImage(const QPoint &point){
    thresholdControlBox->update(point);
}

void updateRawImage(QImage *image){
    // update raw image widget
    // threshhold updaterawimage() 
}
