#include "mainwindow.h"
#include "tsp.h"
#include <QApplication>
#include <QFileDialog>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString path = QFileDialog::getOpenFileName(nullptr,"Open Image", "../", "Text Files (*.txt)");
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    int N = in.readLine().toInt();
    QVector<QVector<double> > qPath(N);
    for(int i = 0;i<qPath.size();i++){
        qPath[i].fill(10000,N);
    }

    for(int i = 0; i<N; i++) {
        QStringList line = in.readLine().split(" ");
        qPath[line[0].toInt()][line[1].toInt()] =  qPath[line[1].toInt()][line[0].toInt()] = line[2].toInt();
    }

    Tsp tsp(0,qPath);
    tsp.solve();
    QVector<int> result = tsp.getTour();
    qDebug()<<result;
    double tourCost = tsp.getTourCost();
    TPSDraw draw(result);
    draw.render();

    return a.exec();
}
