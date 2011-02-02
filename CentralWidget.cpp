#include "CentralWidget.h"
#include <iostream>

CentralWidget::CentralWidget(QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    resize(640, 480);
    initLayout();
}

CentralWidget::~CentralWidget(){
}

void CentralWidget::initLayout(){
    std::cout << "init layout" << std::endl;
    centralLayout = new QHBoxLayout();
    initLeftLayout();
    initRightLayout();
    setLayout(centralLayout);
}

void CentralWidget::initLeftLayout(){
    leftLayout = new QVBoxLayout();
    imageWidget = new ImageWidget("133.19.23.78", 9559, 1);
    leftLayout->addWidget(imageWidget);
    centralLayout->addLayout(leftLayout);
}

void CentralWidget::initRightLayout(){
    rightLayout = new QVBoxLayout();
    cameraButtonGroup = new QGroupBox("camera select");
    camera0Button = new QRadioButton("head camera");
    camera1Button = new QRadioButton("mouth camera");
    cameraButtonLayout = new QVBoxLayout();
    cameraButtonLayout->addWidget(camera0Button);
    cameraButtonLayout->addWidget(camera1Button);
    cameraButtonGroup->setLayout(cameraButtonLayout);
    rightLayout->addWidget(cameraButtonGroup);
    centralLayout->addLayout(rightLayout);
}

void CentralWidget::initCameraButton(){
}

