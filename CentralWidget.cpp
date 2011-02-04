#include "CentralWidget.h"
#include <alvision/alvisiondefinitions.h>
#include <iostream>

CentralWidget::CentralWidget(QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    //resize(320, 480);
    initLayout();
}

CentralWidget::~CentralWidget(){
}

void CentralWidget::initLayout(){
    std::cout << "init layout" << std::endl;
    initImageWidget();
    initCameraParamWidget();
}

void CentralWidget::initImageWidget(){
    imageWidget = new ImageWidget("133.19.23.76", 9559, 1, this);
    imageWidget->setGeometry(50, 40, 320, 240);
}

void CentralWidget::initCameraParamWidget(){
    cameraButtonGroup = new QGroupBox("camera parameters", this);
    cameraButtonGroup->setGeometry(400, 40, 200, 500);
    camera0Button = new QRadioButton("head camera");
    camera0Button->setChecked(true);
    connect(camera0Button, SIGNAL(clicked()), this, SLOT(changeToCameraHead()));
    camera1Button = new QRadioButton("mouth camera");
    connect(camera1Button, SIGNAL(clicked()), this, SLOT(changeToCameraMouth()));
    cameraButtonLayout = new QVBoxLayout();
    cameraButtonLayout->addWidget(camera0Button);
    cameraButtonLayout->addWidget(camera1Button);
    //brightness
    brightnessLabel = new QLabel();
    brightnessLabel->setText("brightness");
    cameraButtonLayout->addWidget(brightnessLabel);
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(0, 255);
    //setBrightnessLabelText();
    connect(brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(changeBrigtness(int)));
    cameraButtonLayout->addWidget(brightnessSlider);
    //contrast
    contrastLabel = new QLabel();
    contrastLabel->setText("contrast");
    cameraButtonLayout->addWidget(contrastLabel);
    contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(0, 127);
    connect(contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(changeContrast(int)));
    cameraButtonLayout->addWidget(contrastSlider);
    //saturation
    saturationLabel = new QLabel();
    saturationLabel->setText("saturation");
    cameraButtonLayout->addWidget(saturationLabel);
    saturationSlider = new QSlider(Qt::Horizontal);
    saturationSlider->setRange(0, 255);
    connect(saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSaturation(int)));
    cameraButtonLayout->addWidget(saturationSlider);
    //gain
    gainLabel = new QLabel();
    gainLabel->setText("gain");
    cameraButtonLayout->addWidget(gainLabel);
    gainSlider = new QSlider(Qt::Horizontal);
    gainSlider->setRange(0, 255);
    connect(gainSlider, SIGNAL(valueChanged(int)), this, SLOT(changeGain(int)));
    cameraButtonLayout->addWidget(gainSlider);
    initLabelAndSliderValue();
    cameraButtonGroup->setLayout(cameraButtonLayout);
}

int CentralWidget::getBrightnessFromNao(){
    return imageWidget->getCameraProperty(AL::kCameraBrightnessID);
}

int CentralWidget::getContrastFromNao(){
    return imageWidget->getCameraProperty(AL::kCameraContrastID);
}

int CentralWidget::getSaturationFromNao(){
    return imageWidget->getCameraProperty(AL::kCameraSaturationID);
}

int CentralWidget::getGainFromNao(){
    return imageWidget->getCameraProperty(AL::kCameraGainID);
}

void CentralWidget::setBrightnessLabelText(int value){
    std::stringstream strstream;
    strstream << "brightness " << value;
    brightnessLabel->setText(strstream.str().c_str());
}

void CentralWidget::setContrastLabelText(int value){
    std::stringstream strstream;
    strstream << "contrast " << value;
    contrastLabel->setText(strstream.str().c_str());
}

void CentralWidget::setSaturationLabelText(int value){
    std::stringstream strstream;
    strstream << "saturation " << value;
    saturationLabel->setText(strstream.str().c_str());
}

void CentralWidget::setGainLabelText(int value){
    std::stringstream strstream;
    strstream << "gain " << value;
    gainLabel->setText(strstream.str().c_str());
}

void CentralWidget::initLabelAndSliderValue(){
    int value;
    value = getBrightnessFromNao(); // setup brightness info
    brightnessSlider->setValue(value);
    setBrightnessLabelText(value);
    value = getContrastFromNao(); // setup contrast info
    contrastSlider->setValue(value);
    setContrastLabelText(value);
    value = getSaturationFromNao(); // setup saturation info
    saturationSlider->setValue(value);
    setSaturationLabelText(value);
    value = getGainFromNao(); //setup gain info
    gainSlider->setValue(value);
    setGainLabelText(value);
}

void CentralWidget::changeToCameraHead(){
    std::cout << "set camera 0" << std::endl;
    imageWidget->setCameraProperty(AL::kCameraSelectID, 0);
}

void CentralWidget::changeToCameraMouth(){
    std::cout << "set camera 1" << std::endl;
    imageWidget->setCameraProperty(AL::kCameraSelectID, 1);
}

void CentralWidget::changeBrigtness(int value){
    imageWidget->setCameraProperty(AL::kCameraBrightnessID, value);
}

void CentralWidget::changeContrast(int value){
    imageWidget->setCameraProperty(AL::kCameraContrastID, value);
}

void CentralWidget::changeSaturation(int value){
    imageWidget->setCameraProperty(AL::kCameraSaturationID, value);
}

void CentralWidget::changeGain(int value){
    imageWidget->setCameraProperty(AL::kCameraGainID, value);
}
