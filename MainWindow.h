#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>
#include <QWidget>

class MainWindow : public QMainWindow{
    Q_OBJECT
 public:
    MainWindow(QWidget *iParent=0, Qt::WindowFlags iFlags=0);
    ~MainWindow();
};

#endif // MainWindow_H
