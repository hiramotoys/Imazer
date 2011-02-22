#ifndef RGBThresholdControlBox_H
#define RGBThresholdControlBox_H

#include <QGroupBox>
#include <QVBoxLayout>
#include "ThresholdSliderBox.h"
#include "Threshold.h"
#include "ColorAttributeID.h"

class RGBThresholdControlBox : public QGroupBox{
    Q_OBJECT
 private:
    QVBoxLayout *layout;
    ThresholdSliderBox *redSlider;
    ThresholdSliderBox *greenSlider;
    ThresholdSliderBox *blueSlider;
 public:
    Threshold r;
    Threshold g;
    Threshold b;
    RGBThresholdControlBox(const QString &title, QWidget *iParent=0);
    RGBThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent=0);
    ~RGBThresholdControlBox();
    void setThValue(const int cattribute, int fr, int to);
    void updateThFrBySlider(const int cattribute, int fr);
    void updateThToBySlider(const int cattribute, int to);
};

#endif // RGBThresholdControlBox
