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


    while(!in.atEnd()){
        QStringList line = in.readLine().split(" ");
        qPath[line[0].toInt()][line[1].toInt()] =  qPath[line[1].toInt()][line[0].toInt()] = line[2].toInt();
    }

    //uncomment to see the adjacency matrix
//    for(int i = 0;i < N; i++ ){
//        for(int j = 0; j < N; j++ ){
//            std::cout << qPath[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }

    Tsp tsp(0,qPath);
    tsp.solve();
    QVector<int> result = tsp.getTour();
    qDebug()<<result;
    double tourCost = tsp.getTourCost();
    std::cout << "min tour cost " << tourCost << std::endl;
    TPSDraw draw(result);
    draw.render();

    return a.exec();
}
