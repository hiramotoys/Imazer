#ifndef LabeledImageWidget_H
#define LabeledImageWidget_H

#include <QWidget>
#include <QImage>
#include <QPaintEvent>

class LabeledImageWidget : public QWidget{
  private:
    Q_OBJECT
  public:    
    QImage *image;
    LabeledImageWidget(const QRect &rect, QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~LabeledImageWidget();
    void paintEvent(QPaintEvent *event);
    void update();
};

#endif // LabeledImageWidget_H
