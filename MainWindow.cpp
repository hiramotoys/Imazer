#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *iParent, Qt::WindowFlags iFlags) : QMainWindow(iParent, iFlags){
    setWindowTitle("Imazer");
    resize(640, 480);
    std::cout << "resized" << std::endl;
    centralWidget = new CentralWidget(this);
    setCentralWidget(centralWidget);
    std::cout << "centralWodget" << std::endl;
    show();
}

MainWindow::~MainWindow(){
}
