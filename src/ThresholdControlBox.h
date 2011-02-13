#ifndef ThresholdControlBox_H
#define ThresholdControlBox_H

#include <QGroupBox>
#include <QRect>
#include <QPoint>
#include <QImage>

class ThresholdControlBox : public QGroupBox{
 private:
    QImage *rawImage;
 public:
    ThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent=0);
    ~ThresholdControlBox();
    void updateImage(QImage *image);
    void update(const QPoint &point);
};

#endif // ThresholdControlBox
