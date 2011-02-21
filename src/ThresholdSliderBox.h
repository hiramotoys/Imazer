#ifndef ThresholdSliderBox_H
#define ThresholdSliderBox_H

#include <QGroupBox>
#include <QVBoxLayout>
#include <QRect>
#include <QString>
#include <QWidget>
#include <QSlider>

class ThresholdSliderBox : public QGroupBox{
    Q_OBJECT
 private:
    QVBoxLayout *layout;
    QSlider *frSlider;
    QSlider *toSlider;
    int colorAttributeID;
 public:
    ThresholdSliderBox(const int colorAttributeID, const QRect &rect, const QString &title, QWidget *iParent=0);
    ~ThresholdSliderBox();
    void setFrValue(int fr);
    void setToValue(int to);
    void setValue(int fr, int to);
 protected slots:
    void changeThFr(int value);
    void changeThTo(int value);
};

#endif // ThresholdSliderBox
