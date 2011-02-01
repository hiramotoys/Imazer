#include "ImageWidget.h"


ImageWidget::ImageWidget(std::string IP, int PORT, int cameraid, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    resize(imagewidth, imageheight);
    
    //test
    label = new QLabel("test");
    layout = new QHBoxLayout();
    //
    this->cameraid = cameraid;
    videoProxy = AL::makeALPtr(new AL::ALVideoDeviceProxy(IP, PORT));
    startTimer(100);
    layout->addWidget(label);
    setLayout(layout);
}

ImageWidget::~ImageWidget(){
}

void ImageWidget::registerImageClient(std::string IP, int PORT){
    imageClient = videoProxy->subscribe("_client", AL::kQVGA, AL::kBGRColorSpace, 30);
    videoProxy->setParam(AL::kCameraSelectID, cameraid);
}

void ImageWidget::unregisterImageClient(){
    videoProxy->unsubscribe(imageClient);
}

