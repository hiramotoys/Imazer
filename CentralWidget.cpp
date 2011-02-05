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

void CentralWidget::initIpAddressWidget(){
    //
}

void CentralWidget::initImageWidget(){
    imageWidget = new ImageWidget("133.19.23.76", 9559, 1, this);
    imageWidget->setGeometry(50, 40, 320, 240);
}

void CentralWidget::initCameraParamWidget(){
    cameraButtonGroup = new QGroupBox("camera parameters", this);
    cameraButtonGroup->setGeometry(400, 40, 200, 500);
    camera0Button = new QRadioButton("head camera");
    connect(camera0Button, SIGNAL(clicked()), this, SLOT(changeToCameraHead()));
    camera1Button = new QRadioButton("mouth camera");
    connect(camera1Button, SIGNAL(clicked()), this, SLOT(changeToCameraMouth()));
    initCameraSelectRadioButton();
    cameraButtonLayout = new QVBoxLayout();
    cameraButtonLayout->addWidget(camera0Button);
    cameraButtonLayout->addWidget(camera1Button);
    fpsLabel = new QLabel();
    fpsLabel->setText("fps");
    cameraButtonLayout->addWidget(fpsLabel);
    fpsSlider = new QSlider(Qt::Horizontal);
    fpsSlider->setRange(0, 30);
    connect(fpsSlider, SIGNAL(valueChanged(int)), this, SLOT(changeFps(int)));
    whiteBalanceLabel = new QLabel(); // white balance
    whiteBalanceLabel->setText("white balance");
    cameraButtonLayout->addWidget(whiteBalanceLabel);
    autoWbCheckBox = new QCheckBox("auto");
    connect(autoWbCheckBox, SIGNAL(toggled(bool)), this, SLOT(changeAutoWhiteBalanceStatus(bool)));
    cameraButtonLayout->addWidget(autoWbCheckBox);
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
    autoGainCheckBox = new QCheckBox("auto");
    connect(autoGainCheckBox, SIGNAL(toggled(bool)), this, SLOT(changeAutoGainStatus(bool)));
    cameraButtonLayout->addWidget(autoGainCheckBox);
    gainSlider = new QSlider(Qt::Horizontal);
    gainSlider->setRange(0, 255);
    connect(gainSlider, SIGNAL(valueChanged(int)), this, SLOT(changeGain(int)));
    cameraButtonLayout->addWidget(gainSlider);
    initLabelAndSliderValue();
    cameraButtonGroup->setLayout(cameraButtonLayout);
    initCheckBoxStatus();
}

int CentralWidget::getFpsFromNao(){
    return imageWidget->getCameraProperty(AL::kCameraFrameRateID);
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

void CentralWidget::setFpsLabelText(int value){
    std::stringstream strstream;
    strstream << "fps " << value;
    fpsLabel->setText(strstream.str().c_str());
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

void CentralWidget::initCameraSelectRadioButton(){
    int value = imageWidget->getCameraProperty(AL::kCameraSelectID);
    switch(value){
    case 0:
	camera0Button->setChecked(true);
	break;
    case 1:
	camera1Button->setChecked(true);
	break;
    }
	
}

void CentralWidget::initLabelAndSliderValue(){
    int value;
    value = getFpsFromNao(); // setup fps
    fpsSlider->setValue(value);
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

void CentralWidget::initCheckBoxStatus(){
    autoWbCheckBox->setChecked(imageWidget->getCameraProperty(AL::kCameraAutoWhiteBalanceID));
    autoGainCheckBox->setChecked(imageWidget->getCameraProperty(AL::kCameraAutoGainID));
    //ischecked = imageWidget->getCameraProperty(AL::kCameraAutoExpositionID);
}

void CentralWidget::changeToCameraHead(){
    std::cout << "set camera 0" << std::endl;
    imageWidget->setCameraProperty(AL::kCameraSelectID, 0);
}

void CentralWidget::changeToCameraMouth(){
    std::cout << "set camera 1" << std::endl;
    imageWidget->setCameraProperty(AL::kCameraSelectID, 1);
}

void CentralWidget::changeFps(int value){
    imageWidget->setCameraProperty(AL::kCameraFrameRateID, value);
    setFpsLabelText(value);
}

void CentralWidget::changeBrigtness(int value){
    imageWidget->setCameraProperty(AL::kCameraBrightnessID, value);
    setBrightnessLabelText(value);
}

void CentralWidget::changeContrast(int value){
    imageWidget->setCameraProperty(AL::kCameraContrastID, value);
    setContrastLabelText(value);
}

void CentralWidget::changeSaturation(int value){
    imageWidget->setCameraProperty(AL::kCameraSaturationID, value);
    setSaturationLabelText(value);
}

void CentralWidget::changeGain(int value){
    imageWidget->setCameraProperty(AL::kCameraGainID, value);
    setGainLabelText(value);
}

void CentralWidget::changeAutoWhiteBalanceStatus(bool ischecked){
    switch(ischecked){
    case true:
	imageWidget->setCameraProperty(AL::kCameraAutoWhiteBalanceID, 1);
	initLabelAndSliderValue();
	std::cout << "auto wb true" << std::endl;
	break;
    case false:
	imageWidget->setCameraProperty(AL::kCameraAutoWhiteBalanceID, 0);
	initLabelAndSliderValue();
	std::cout << "auto wb false" << std::endl;
	break;
    }
}

void CentralWidget::changeAutoGainStatus(bool ischecked){
    switch(ischecked){
    case true:
	imageWidget->setCameraProperty(AL::kCameraAutoGainID, 1);
	initLabelAndSliderValue();
	break;
    case false:
	imageWidget->setCameraProperty(AL::kCameraAutoGainID, 0);
	initLabelAndSliderValue();
	break;
    }     
}
