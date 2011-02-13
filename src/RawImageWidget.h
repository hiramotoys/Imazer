#ifndef RawImageWidget_H
#define RawImageWidget_H

#include <QWidget>
#include <QImage>
#include <QMouseEvent>

class RawImageWidget : public QWidget{
 private:
    QImage *image;
 public:
    RawImageWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~RawImageWidget();
    void update(QImage *image);
    void paintEvent(QPaintEvent *event);
 protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // RawImageWidget
