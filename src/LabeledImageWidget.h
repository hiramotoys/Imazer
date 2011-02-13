#ifndef LabeledImageWidget_H
#define LabeledImageWidget_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>


class LabeledImageWidget : public QWidget{
 private:
    QImage *image;
 public:    
    LabeledImageWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~LabeledImageWidget();
    void update(QImage *image);
    void paintEvent(QPaintEvent *event);
};

#endif // LabeledImageWidget_H
