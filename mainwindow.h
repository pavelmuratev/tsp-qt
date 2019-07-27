#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QVBoxLayout>
#include <QDebug>
#include "tpsdraw.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

private:
    Ui::MainWindow *ui;
    TPSDraw* tpsDraw;
};

#endif // MAINWINDOW_H
