#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QWidget>
#include "CentralWidget.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
 private:
    CentralWidget *centralWidget;
 public:
    MainWindow(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~MainWindow();
};

#endif // MainWindow_H
