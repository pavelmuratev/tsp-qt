#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(4);
    test.push_back(3);
    TPSDraw* tps = new TPSDraw(test);
    tps->render();
}

MainWindow::~MainWindow()
{
    delete ui;
}

