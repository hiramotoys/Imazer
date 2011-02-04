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
    //camera select
    cameraButtonGroup = new QGroupBox("camera select", this);
    cameraButtonGroup->setGeometry(400, 40, 200, 500);
    camera0Button = new QRadioButton("head camera");
    camera0Button->setChecked(true);
    connect(camera0Button, SIGNAL(clicked()), this, SLOT(changeToCameraHead()));
    camera1Button = new QRadioButton("mouth camera");
    connect(camera1Button, SIGNAL(clicked()), this, SLOT(changeToCameraMouth()));
    cameraButtonLayout = new QVBoxLayout();
    cameraButtonLayout->addWidget(camera0Button);
    cameraButtonLayout->addWidget(camera1Button);
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(0, 255);
    connect(brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(changeBrigtness(int)));
    cameraButtonLayout->addWidget(brightnessSlider);
    contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(0, 127);
    connect(contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(changeContrast(int)));
    cameraButtonLayout->addWidget(contrastSlider);
    saturationSlider = new QSlider(Qt::Horizontal);
    saturationSlider->setRange(0, 255);
    connect(saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSaturation(int)));
    cameraButtonLayout->addWidget(saturationSlider);
    gainSlider = new QSlider(Qt::Horizontal);
    gainSlider->setRange(0, 255);
    connect(gainSlider, SIGNAL(valueChanged(int)), this, SLOT(changeGain(int)));
    cameraButtonLayout->addWidget(gainSlider);
    cameraButtonGroup->setLayout(cameraButtonLayout);
    //rightLayout->addWidget(cameraButtonGroup);
    /*
    //camera param
    cameraParamGroup = new QGroupBox("camera parameters");
    cameraParamLayout = new QVBoxLayout();
    brightnessSlider = new QSlider(Qt::Horizontal);
    brightnessSlider->setRange(0, 255);
    connect(brightnessSlider, SIGNAL(valueChanged(int)), this, SLOT(changeBrigtness(int)));
    cameraParamLayout->addWidget(brightnessSlider);
    contrastSlider = new QSlider(Qt::Horizontal);
    contrastSlider->setRange(0, 127);
    connect(contrastSlider, SIGNAL(valueChanged(int)), this, SLOT(changeContrast(int)));
    cameraParamLayout->addWidget(contrastSlider);
    saturationSlider = new QSlider(Qt::Horizontal);
    saturationSlider->setRange(0, 255);
    connect(saturationSlider, SIGNAL(valueChanged(int)), this, SLOT(changeSaturation(int)));
    cameraParamLayout->addWidget(saturationSlider);
    gainSlider = new QSlider(Qt::Horizontal);
    gainSlider->setRange(0, 255);
    connect(gainSlider, SIGNAL(valueChanged(int)), this, SLOT(changeGain(int)));
    cameraParamLayout->addWidget(gainSlider);
    cameraParamGroup->setLayout(cameraParamLayout);
    rightLayout->addWidget(cameraParamGroup);
    //add to central widget
    centralLayout->addLayout(rightLayout);*/
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
