#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Hashfunctions/hashfunction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	Hashfunction a;
	a.Foo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

