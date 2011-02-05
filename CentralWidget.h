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
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include "ImageWidget.h"

class CentralWidget : public QWidget{
    Q_OBJECT
 private:
    QLabel *ipLabel;
    QLineEdit *ipLineEdit;
    QPushButton *ipConnectButton;
    ImageWidget *imageWidget;
    QRadioButton *camera0Button;
    QRadioButton *camera1Button;
    QVBoxLayout *cameraButtonLayout;
    QGroupBox *cameraButtonGroup;
    QSlider *fpsSlider;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QSlider *saturationSlider;
    QSlider *gainSlider;
    QLabel *fpsLabel;
    QLabel *whiteBalanceLabel;
    QLabel *brightnessLabel;
    QLabel *contrastLabel;
    QLabel *saturationLabel;
    QLabel *gainLabel;
    QCheckBox *autoWbCheckBox;
    QCheckBox *autoGainCheckBox;

 public:
    CentralWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~CentralWidget();
 protected:
    void initLayout();
    void initIpAddressWidget();
    void initImageWidget();
    void initCameraParamWidget();
    int getFpsFromNao();
    int getBrightnessFromNao();
    int getContrastFromNao();
    int getSaturationFromNao();
    int getGainFromNao();
    void setFpsLabelText(int value);
    void setBrightnessLabelText(int value);
    void setContrastLabelText(int value);
    void setSaturationLabelText(int value);
    void setGainLabelText(int value);
    void initCameraSelectRadioButton();
    void initLabelAndSliderValue();
    void initCheckBoxStatus();

 protected slots:
    void changeToCameraHead();
    void changeToCameraMouth();
    void changeFps(int value);
    void changeBrigtness(int value);
    void changeContrast(int value);
    void changeSaturation(int value);
    void changeGain(int value);
    void changeAutoWhiteBalanceStatus(bool ischecked);
    void changeAutoGainStatus(bool ischecked);
};
#endif // CentralWidget_H
