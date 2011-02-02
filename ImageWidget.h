#ifndef ImageWidget_H
#define ImageWidget_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPainter>
#include <string>

#include <alproxies/almemoryproxy.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alvisiondefinitions.h>
#include <alvision/alimage.h>


class ImageWidget : public QWidget{
    Q_OBJECT
 private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QLabel *label;
    int imagewidth;
    int imageheight;
    int cameraid;
    std::string imageClient;
    AL::ALPtr<AL::ALVideoDeviceProxy> videoProxy;
    AL::ALValue alimagevalue;
    QImage *image;
    
 public:
    ImageWidget(std::string IP, int PORT, int cameraid, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~ImageWidget();
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    
 private:
    void registerImageClient(std::string IP, int PORT);
    void unregisterImageClient();
    void updateImage();
    
};

#endif // ImageWidget_H
