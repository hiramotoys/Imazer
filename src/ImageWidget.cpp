#include "ImageWidget.h"
#include <iostream>

ImageWidget::ImageWidget(QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    image = NULL;
}

ImageWidget::ImageWidget(std::string IP, int PORT, int cameraid, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    this->cameraid = cameraid;
    image = NULL;
    registerImageClient(IP, PORT);
    startTimer(100);
}

ImageWidget::~ImageWidget(){
    unregisterImageClient();
}

void ImageWidget::connectToNaoCamera(std::string IP, int PORT, int cameraid){
    this->cameraid = cameraid;
    registerImageClient(IP, PORT);
    startTimer(100);
}

void ImageWidget::paintEvent(QPaintEvent *event){
    if(this->image != NULL){
	QPainter painter(this);
	painter.drawImage(painter.viewport(), *image);
    }
}

void ImageWidget::timerEvent(QTimerEvent *event){
    updateImage();
    update();
}

void ImageWidget::setCameraProperty(int param, int value){
    videoProxy->setParam(param, value);
}

int ImageWidget::getCameraProperty(int param){
    return videoProxy->getParam(param);
}

void ImageWidget::setCamera(int cameraid){
    videoProxy->setParam(AL::kCameraSelectID, cameraid);
}

void ImageWidget::registerImageClient(std::string IP, int PORT){
    videoProxy = AL::makeALPtr(new AL::ALVideoDeviceProxy(IP, PORT));
    imageClient = videoProxy->subscribe("_client", AL::kQVGA, AL::kRGBColorSpace, 30);
    videoProxy->setParam(AL::kCameraSelectID, cameraid);
}

void ImageWidget::unregisterImageClient(){
    videoProxy->unsubscribe(imageClient);
}

void ImageWidget::updateImage(){
    alimagevalue = videoProxy->getImageRemote(imageClient);
    image = new QImage((const uchar*)alimagevalue[6].GetBinary(), //Pixel array
		       (int)alimagevalue[0], //width
		       (int)alimagevalue[1], //height
		       QImage::Format_RGB888);
}
