#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <QObject>
#include <QVector>
#include <QDebug>
#include <QVector>


class Tsp
{
public:
    Tsp();
    Tsp(const QVector<QVector<double> > &distance);
    Tsp(int startNode,QVector<QVector<double> > distance);

    QVector<int> getTour();
    double getTourCost();
    void solve();
    double tspSolver(int i, int state, QVector<QVector<double> >memo, QVector<QVector<int> > &prev);


private:
    int N;
    int nStartNode;
    int nFinishNode;
    QVector<QVector<double> > m_distance;
    double minTourCost = 99999.99;

    QVector<int> tour;
    bool m_isSolved = false;

};

#endif // TSP_H
