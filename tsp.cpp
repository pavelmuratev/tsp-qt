#include "tsp.h"

Tsp::Tsp()
{
    N = 0;
    nStartNode = 0;

}
Tsp::Tsp(QList<QList<double> > distance){
    Tsp(0,distance);
}

Tsp::Tsp(int startNode,QList<QList<double> > distance){

    m_distance = distance;
    N = distance.size();
    nStartNode = startNode;

    nFinishNode = (1 << N) - 1;

}

double Tsp::tspSolver(int i,int state,QList<QList<double> >memo,QList<QList<int> >prev){

    // Done this tour. Return cost of going back to start node.
    if(state == nFinishNode){
        return m_distance[i][nStartNode];
    }
    \
    // Return cached answer if already computed.
    if(memo[i][state] != NULL){
        return memo[i][state];
    }
    double minCost = 9999.99;
    int index = -1;

    for(int next = 0;next < N;next++){

        if ((state & (1 << next)) != 0) continue;

        int nextState = state | (1 << next);
        double newCost = m_distance[i][next] + tspSolver(next,nextState,memo,prev);
        if(newCost < minCost) {
            minCost = newCost;
            index = next;
        }
    }

    prev[i][state] = index;
    return memo[i][state] = minCost;

}

void Tsp::solve(){

    int state = 1 << nStartNode;
    QList<QList<double> > memo;
    QList<QList<int> > prev;

    minTourCost = tspSolver(nStartNode,state,memo,prev);

    //regenerate path
    int index = nStartNode;

    while(true) {
        tour.append(index);
        int nextIndex = prev[index][state];
        if(nextIndex == NULL){
            qDebug() << "next index is null";
            break;
        }
        int nextState = state | (1 << nextIndex);
        state = nextState;
        index = nextIndex;
    }
    tour.append(nStartNode);
    m_isSolved = true;

}

QList<int> Tsp::getTour(){

    if(! m_isSolved){
        solve();
    }
    return tour;
}
double Tsp::getTourCost(){

    if(! m_isSolved){
        solve();
    }
    return minTourCost;
}
