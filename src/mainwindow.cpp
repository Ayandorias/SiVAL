#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : NW::MainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mainMenu() {

}
