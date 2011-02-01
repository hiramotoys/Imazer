#include "MainWindow.h"

MainWindow::MainWindow(QWidget *iParent, Qt::WindowFlags iFlags) : QMainWindow(iParent, iFlags){
    setWindowTitle("Imazer");
    resize(350, 250);
    imageWidget = new ImageWidget("133", 9559, 1, this);
    setCentralWidget(imageWidget);
    show();
}

MainWindow::~MainWindow(){
}
