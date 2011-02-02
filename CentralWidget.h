#ifndef CentralWidget_H
#define CentralWidget_H
#include <QWidget>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ImageWidget.h"

class CentralWidget : public QWidget{
    Q_OBJECT
 private:
    ImageWidget *imageWidget;
    QHBoxLayout *centralLayout;
    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;
    QRadioButton *camera0Button;
    QRadioButton *camera1Button;
    QGroupBox *cameraButtonGroup;
    QVBoxLayout *cameraButtonLayout;
 public:
    CentralWidget(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~CentralWidget();
 protected:
    void initLayout();
    void initLeftLayout();
    void initRightLayout();
    void initCameraButton();
 protected slots:
    void changeToCameraHead();
    void changeToCameraMouth();
};
#endif // CentralWidget_H
