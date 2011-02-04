#ifndef CentralWidget_H
#define CentralWidget_H
#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include "ImageWidget.h"

class CentralWidget : public QWidget{
    Q_OBJECT
 private:
    ImageWidget *imageWidget;
    QButtonGroup *buttonGroup;
    QVBoxLayout *centralLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *imageLayout;
    QGroupBox *imageGroup;
    QVBoxLayout *rightLayout;
    QRadioButton *camera0Button;
    QRadioButton *camera1Button;
    QVBoxLayout *cameraButtonLayout;
    QGroupBox *cameraButtonGroup;
    QSlider *brightnessSlider;
    QSlider *contrastSlider;
    QSlider *saturationSlider;
    QSlider *gainSlider;
    QVBoxLayout *cameraParamLayout;
    QGroupBox *cameraParamGroup;
 public:
    CentralWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~CentralWidget();
 protected:
    void initLayout();
    void initImageWidget();
    void initCameraParamWidget();

 protected slots:
    void changeToCameraHead();
    void changeToCameraMouth();
    void changeBrigtness(int value);
    void changeContrast(int value);
    void changeSaturation(int value);
    void changeGain(int value);
};
#endif // CentralWidget_H
