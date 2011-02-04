#include "ImageWidget.h"
#include <iostream>

ImageWidget::ImageWidget(std::string IP, int PORT, int cameraid, QWidget *iParent, Qt::WindowFlags iFlags) : QWidget(iParent, iFlags){
    imagewidth = 320;
    imageheight = 240;
    this->cameraid = cameraid;
    //resize(imagewidth, imageheight);
    image = NULL;
    registerImageClient(IP, PORT);
    startTimer(100);
}

ImageWidget::~ImageWidget(){
    unregisterImageClient();
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
