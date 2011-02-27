#ifndef HSVThresholdControlBox_H
#define HSVThresholdControlBox_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QString>
#include <QWidget>
#include <QRect>
#include "ThresholdSliderBox.h"
#include "Threshold.h"
#include "ColorAttributeID.h"

class HSVThresholdControlBox : public QGroupBox{
    Q_OBJECT
 private:
    QVBoxLayout *layout;
    ThresholdSliderBox *hSlider;
    ThresholdSliderBox *sSlider;
    ThresholdSliderBox *vSlider;
 public:
    Threshold h;
    Threshold s;
    Threshold v;
    HSVThresholdControlBox(const QString &title, QWidget *iParent=0);
    HSVThresholdControlBox(const QRect &rect, const QString &title, QWidget *iParent=0);
    ~HSVThresholdControlBox();
    void updateThFrBySlider(const int cattribute, int fr);
    void updateThToBySlider(const int cattribute, int to);
    bool isIncluded(int h, int s, int v);
};

#endif // HSVThresholdControlBox
