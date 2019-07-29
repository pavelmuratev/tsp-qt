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
    /*QList<QList<QPair<int,int>>> cities;
    QList<QPair<int,int>> city;
    QPair<int,int> pair;
    pair.first = 1;
    pair.second = 223;
    city.push_back(pair);
    pair.first = 2;
    pair.second = 22;
    city.push_back(pair);
    cities.push_back(city);
    city.pop_back();
    city.pop_back();
    pair.first = 0;
    pair.second = 223;
    city.push_back(pair);
    cities.push_back(city);
    city.pop_back();
    pair.first = 0;
    pair.second = 22;
    city.push_back(pair);
    cities.push_back(city);
    qDebug()<<cities;
    TPSDraw* tps = new TPSDraw(cities);
    tps->render();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

