#include "MotionControlerBox.h"

MotionControlerBox::MotionControlerBox(QRect &rect, const QString &text, QWidget *iParent) : QGroupBox(text, iParent){
    setGeometry(rect);
    layout = new QVBoxLayout();
    initWidget();
    setLayout(layout);
}

MotionControlerBox::~MotionControlerBox(){
    unregisterMotionClient();
}

void MotionControlerBox::connectToNao(std::string IP, int PORT){
    registerMotionClient(IP, PORT);
}

void MotionControlerBox::initWidget(){
    stiffnessLabel = new QLabel("stiffness");
    layout->addWidget(stiffnessLabel);
    headStiffnessCheckBox = new QCheckBox("head");
    layout->addWidget(headStiffnessCheckBox);
    allStiffnessCheckBox = new QCheckBox("all");
    layout->addWidget(allStiffnessCheckBox);
}

void MotionControlerBox::registerMotionClient(std::string IP, int PORT){
    motionProxy = AL::makeALPtr(new AL::ALMotionProxy(IP, PORT));
}

void MotionControlerBox::unregisterMotionClient(){
}

void MotionControlerBox::changeHeadStiffnessStatus(bool ischecked){
    switch(ischecked){
    case true:
	motionProxy->setStiffnesses("Head", 1.0);
	break;
    case false:
	motionProxy->setStiffnesses("Head", 0.0);
    }
}

void MotionControlerBox::changeAllStiffnessStatus(bool ischecked){
    switch(ischecked){
    case true:
	motionProxy->setStiffnesses("Body", 1.0);
	break;
    case false:
	motionProxy->setStiffnesses("Body", 0.0);
    }
}
