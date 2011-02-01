#ifndef ImageWidget_H
#define ImageWidget_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

//class QHBoxLayout;
//class QLabel;

class ImageWidget : public QWidget{
    Q_OBJECT
 private:
    QHBoxLayout *layout;
    QLabel *label;
 public:
    ImageWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~ImageWidget();
};

#endif // ImageWidget_H
