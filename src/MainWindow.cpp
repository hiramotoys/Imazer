#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *iParent, Qt::WindowFlags iFlags) : QMainWindow(iParent, iFlags){
    setWindowTitle("Imazer");
    resize(1700, 700);
    centralWidget = new CentralWidget(this);
    setCentralWidget(centralWidget);
    show();
}

MainWindow::~MainWindow(){
}
