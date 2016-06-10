#include "mainwindow.h"
#include "editor.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new Editor(this));
    showMaximized();
}

MainWindow::~MainWindow()
{

}
