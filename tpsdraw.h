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
    TPSDraw(QVector<int> cities);
    void render();
    void setCities(QVector<int> cities);
    QVector<int> getCities();
    QGraphicsView *getView() const;

private:
    QGraphicsView* view;
    QVector<int> cities;
};

#endif // TPSDRAW_H
