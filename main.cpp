#include "mainwindow.h"
#include "tsp.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QVector<QVector<double> > qPath = {{10000,10000,10000,10000,10000,10000},
                                {10000,10000,10000,10000,10000,10000},
                                {10000,10000,10000,10000,10000,10000},
                               {10000,10000,10000,10000,10000,10000},
                               {10000,10000,10000,10000,10000,10000},
                               {10000,10000,10000,10000,10000,10000}};


        // Create adjacency matrix
        qPath[1][4] = qPath[4][1] = 2;
        qPath[4][2] = qPath[2][4] = 4;
        qPath[2][3] = qPath[3][2] = 6;
        qPath[3][0] = qPath[0][3] = 8;
        qPath[0][5] = qPath[5][0] = 10;
        qPath[5][1] = qPath[1][5] = 12;


        Tsp tsp(0,qPath);
        tsp.solve();
        QVector<int> result = tsp.getTour();
        double tourCost = tsp.getTourCost();
        std::cout << "tour cost "  << tourCost << std::endl;

        for(int i = 0;i < result.size();i++){
            qDebug() << "path: " <<  result[i] << " ";

        }


    MainWindow w;
//    w.show();


    return a.exec();
}
