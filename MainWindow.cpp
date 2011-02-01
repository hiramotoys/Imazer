#include "MainWindow.h"

MainWindow::MainWindow(QWidget *iParent, Qt::WindowFlags iFlags) : QMainWindow(iParent, iFlags){
    setWindowTitle("Imazer");
    resize(350, 250);
    show();
}

MainWindow::~MainWindow(){
}
