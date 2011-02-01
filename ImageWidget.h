#ifndef ImageWidget_H
#define ImageWidget_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <string>

#include <alproxies/almemoryproxy.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alvisiondefinitions.h>
#include <alvision/alimage.h>
//class QHBoxLayout;
//class QLabel;

class ImageWidget : public QWidget{
    Q_OBJECT
 private:
    QHBoxLayout *layout;
    QLabel *label;
    int imagewidth;
    int imageheight;
    int cameraid;
    std::string imageClient;
    AL::ALPtr<AL::ALVideoDeviceProxy> videoProxy;
    AL::ALImage *alimage;
    
 public:
    ImageWidget(std::string IP, int PORT, int cameraid, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~ImageWidget();
    void paintEvent(QEvent *event);
    void timerEvent(QEvent *event);
    
 private:
    void registerImageClient(std::string IP, int PORT);
    void unregisterImageClient();
    
};

#endif // ImageWidget_H
