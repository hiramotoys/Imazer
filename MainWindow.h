#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QWidget>
#include "ImageWidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
 private:
    ImageWidget *imageWidget;
 public:
    MainWindow(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~MainWindow();
};

#endif // MainWindow_H
