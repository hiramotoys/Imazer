#ifndef LabelingWidget_H
#define LabelingWidget_H

#include <QWidget>
#include "RawImageWidget.h"
#include "LabeledImageWidget.h"
#include "RGBThresholdControlBox.h"
#include "ClassSelectBox.h"

class LabelingWidget : public QWidget{
  private:
    RawImageWidget *rawImageWidget;
    LabeledImageWidget *labeledImageWidget;
    RGBThresholdControlBox *rgbThBall;
    RGBThresholdControlBox *rgbThGreen;
    RGBThresholdControlBox *rgbThLines;
    RGBThresholdControlBox *rgbThGoalYellow;
    RGBThresholdControlBox *rgbThGoalBlue;
    ClassSelectBox *classSelectBox;
  public:
    LabelingWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~LabelingWidget();
    void updateRawImage(QImage *image);
    void clickedRawImage(const QPoint &point);
    void movedrgbThBallSlider();
    void movedrgbThGreenSlider();
    void movedrgbThLinesSlider();
    void movedrgbThGoalYellowSlider();
    void movedrgbThGoalBlueSlider();
};

#endif // LabelingWidget_H
