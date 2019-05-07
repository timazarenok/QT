#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cw = new CountryWindow;
    bw = new BrandWindow;
    sw = new SizeWindow;
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::slotStartCountryWindow);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::slotsStartSizeWindow);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::slotStartBrandWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotStartCountryWindow()
{
    cw->show();
}

void MainWindow::slotStartBrandWindow()
{
    bw->show();
}

void MainWindow::slotsStartSizeWindow()
{
    sw->show();
}
