#ifndef LabelingWidget_H
#define LabelingWidget_H

#include <QWidget>
#include <QRect>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QImage>
#include "RawImageWidget.h"
#include "LabeledImageWidget.h"
#include "RGBThresholdControlBox.h"
#include "HSVThresholdControlBox.h"
#include "ClassSelectorBox.h"

class LabelingWidget : public QWidget{
  private:
    QImage *image;
    RawImageWidget *rawImageWidget;
    LabeledImageWidget *labeledImageWidget;
    RGBThresholdControlBox *rgbThBall;
    RGBThresholdControlBox *rgbThGreen;
    RGBThresholdControlBox *rgbThLines;
    RGBThresholdControlBox *rgbThGoalYellow;
    RGBThresholdControlBox *rgbThGoalBlue;
    HSVThresholdControlBox *hsvThBall;
    HSVThresholdControlBox *hsvThGreen;
    HSVThresholdControlBox *hsvThLines;
    HSVThresholdControlBox *hsvThGoalYellow;
    HSVThresholdControlBox *hsvThGoalBlue;
    ClassSelectorBox *classSelectorBox;
    QGroupBox *sliderGroupBox;
    QHBoxLayout *sliderLayout;
  public:
    LabelingWidget(const QRect &rect, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~LabelingWidget();
    void initRGBThControlBox();
    void initHSVThControlBox();
    void updateRawImage(QImage *image);
    void clickedRawImage(const QPoint &point);
    void clickedLinesPixel(const QPoint &point);
    void updateThresholdToIncludeTheParam(int red, int green, int blue, RGBThresholdControlBox *rgbTh);
    bool isValueInClass(int red, int green, int blue, RGBThresholdControlBox *rgbTh);
    void movedrgbThBallSlider();
    void movedrgbThGreenSlider();
    void movedrgbThLinesSlider();
    void movedrgbThGoalYellowSlider();
    void movedrgbThGoalBlueSlider();
};

#endif // LabelingWidget_H
