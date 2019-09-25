#include "tsp.h"

Tsp::Tsp()
{


}
Tsp::Tsp(const QVector<QVector<double> >& distance){

    Tsp(0,distance);
}

Tsp::Tsp(int startNode,QVector<QVector<double> > distance){

    m_distance = distance;
    N = distance.size();
    nStartNode = startNode;

    // The finished state is when the finished state mask has all bits are set to
    // one (meaning all the nodes have been visited).
    nFinishNode = (1 << N) - 1;
}

double Tsp::tspSolver(int i,int state,QVector<QVector<double> >memo,QVector<QVector<int> >& prev){

    // Done this tour. Return cost of going back to start node.
    if(state == nFinishNode){
        return m_distance[i][nStartNode];
    }
    \
    // Return cached answer if already computed.
    if(memo[i][state] != 0){
        return memo[i][state];
    }
    double minCost = 9999.99;
    int index = -1;

    for(int next = 0;next < N;next++){

        // Skip if the next node has already been visited.
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

    // 1 << N = 2^N
    int state = 1 << nStartNode;
    QVector<QVector<double> > memo(N,QVector<double>(1 << N ));
    QVector<QVector<int> > prev(N, QVector<int>(1 << N));

    minTourCost = tspSolver(nStartNode,state,memo,prev);

    //regenerate path
    //index = 0 as startNode is always zero
    int index = nStartNode;

    while(true) {
        tour.append(index);
        int nextIndex = prev[index][state];
        if(nextIndex == 0){
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

QVector<int> Tsp::getTour(){

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
