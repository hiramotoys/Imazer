#ifndef ThresholdSliderBox_H
#define ThresholdSliderBox_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QRect>
#include <QString>
#include <QWidget>

class ThresholdSliderBox : QGoupBox{
    Q_OBJECT
 private:
    QVBoxLayout *layout;
    QSlider *frSlider;
    QSlider *toSlider;
    int colorAttributeID;
 public:
    ThresholdSliderBox(const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent=0);
    ~ThresholdSliderBox();
 protected slots:
    void changeThFr(int value);
    void changeThTo(int value);
};

#endif // ThresholdSliderBox
