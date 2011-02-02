#include "CentralWidget.h"
#include <alvision/alvisiondefinitions.h>
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
    camera0Button->setChecked(true);
    connect(camera0Button, SIGNAL(clicked()), this, SLOT(changeToCameraHead));
    camera1Button = new QRadioButton("mouth camera");
    connect(camera1Button, SIGNAL(clicked()), this, SLOT(changeToCameraMouth));
    cameraButtonLayout = new QVBoxLayout();
    cameraButtonLayout->addWidget(camera0Button);
    cameraButtonLayout->addWidget(camera1Button);
    cameraButtonGroup->setLayout(cameraButtonLayout);
    rightLayout->addWidget(cameraButtonGroup);
    centralLayout->addLayout(rightLayout);
}

void CentralWidget::changeToCameraHead(){
    imageWidget->setCameraProperty(AL::kCameraSelectID, 0);
}

void CentralWidget::changeToCameraMouth(){
    imageWidget->setCameraProperty(AL::kCameraSelectID, 1);
}
