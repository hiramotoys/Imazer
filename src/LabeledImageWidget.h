#ifndef ClusteredImageWidget_H
#define ClusteredImageWidget_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>


class ClusteredImageWidget : public QWidget{
 private:
    QImage *image;
 public:    
    ClusteredImageWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~ClusteredImageWidget();
    void update(QImage *image);
    void paintEvent(QPaintEvent *event);
};

#endif // ClusteredImageWidget_H
