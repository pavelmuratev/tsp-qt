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
    TPSDraw(QList<QList<QPair<int,int>>> cities);
    void render();
    void setCities(QList<QList<QPair<int,int>>> cities);
    QList<QList<QPair<int,int>>> getCities();
    QGraphicsView *getView() const;

private:
    QGraphicsView* view;
    QList<QList<QPair<int,int>>> cities;
    int getMinDistance(QList<QPair<int,int>> city);
};

#endif // TPSDRAW_H
