#ifndef LabeledImageWidget_H
#define LabeledImageWidget_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

class LabeledImageWidget : public QWidget{
  private:
    QImage *image;
  public:    
    LabeledImageWidget(const QRect &rect, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~LabeledImageWidget();
    void paintEvent(QPaintEvent *event);
    void update(QImage *update);
};

#endif // LabeledImageWidget_H
