#ifndef ThresholdSliderBox_H
#define ThresholdSliderBox_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QRect>
#include <QString>
#include <QWidget>

class ThresholdSliderBox : QGoupBox{
 private:
    QVBoxLayout *layout;
    QSlider *frSlider;
    QSlider *toSlider;
 public:
    ThresholdSliderBox(const QRect &rect, const QString &title, QWidget *iParent=0);
    ~ThresholdSliderBox();
};

#endif // ThresholdSliderBox
