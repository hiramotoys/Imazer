#ifndef ClusteringWidget_H
#define ClusteringWidget_H

#include <QWidget>
#include <QPoint>
#include <QRect>
#include "RawImageWidget.h"
#include "ThresholdControlBox.h"

class ClusteringWidget : public QWidget{
 private:
    RawImageWidget *rawImageWidget;
    ThresholdControlBox *thresholdControlBox;
 public:
    ClusteringWidget(const QRect &rect, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~ClusteringWidget();
    void clickedRawImage(const QPoint &point);
    void updateRawImage(QImage *image);
};

#endif // ClusteringWidget
