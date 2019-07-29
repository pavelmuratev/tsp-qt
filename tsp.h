#ifndef TSP_H
#define TSP_H

#include <QObject>
#include <QList>
#include <QDebug>


class Tsp
{
public:
    Tsp();
    Tsp(QList<QList<double> > distance);
    Tsp(int startNode,QList<QList<double> > distance);

    QList<int> getTour();
    double getTourCost();
    void solve();
    double tspSolver(int i,int state,QList<QList<double> >memo,QList<QList<int> >prev);


private:
    int N;
    int nStartNode;
    int nFinishNode;
    QList<QList<double> > m_distance;
    double minTourCost = 99999.99;

    QList<int> tour;
    bool m_isSolved = false;

};

#endif // TSP_H
