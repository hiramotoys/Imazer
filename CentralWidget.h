#ifndef CentralWidget_H
#define CentralWidget_H
#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QLabel>
#include "ImageWidget.h"

class CentralWidget : public QWidget{
    Q_OBJECT
 private:
    ImageWidget *imageWidget;
    QRadioButton *camera0Button;
    QRadioButton *camera1Button;
    QVBoxLayout *cameraButtonLayout;
    QGroupBox *cameraButtonGroup;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QSlider *saturationSlider;
    QSlider *gainSlider;
    QLabel *brightnessLabel;
    QLabel *contrastLabel;
    QLabel *saturationLabel;
    QLabel *gainLabel;

 public:
    CentralWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~CentralWidget();
 protected:
    void initLayout();
    void initImageWidget();
    void initCameraParamWidget();
    int getBrightnessFromNao();
    int getContrastFromNao();
    int getSaturationFromNao();
    int getGainFromNao();
    void setBrightnessLabelText(int value);
    void setContrastLabelText(int value);
    void setSaturationLabelText(int value);
    void setGainLabelText(int value);
    void initLabelAndSliderValue();
    void initCameraSelectRadioButton();

 protected slots:
    void changeToCameraHead();
    void changeToCameraMouth();
    void changeBrigtness(int value);
    void changeContrast(int value);
    void changeSaturation(int value);
    void changeGain(int value);
};
#endif // CentralWidget_H
