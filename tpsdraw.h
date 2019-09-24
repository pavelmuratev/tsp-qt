#ifndef TPSDRAW_H
#define TPSDRAW_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMap>
#include <QDebug>
#include <QList>
#include <QGraphicsTextItem>

class TPSDraw : public QGraphicsScene
{
public:
    TPSDraw(QVector<int> cities, double cost);
    void render();
    void setCities(QVector<int> cities);
    QVector<int> getCities();
    QGraphicsView *getView() const;

private:
    QGraphicsView* view;
    QVector<int> cities;
    double m_cost;
};

#endif // TPSDRAW_H
