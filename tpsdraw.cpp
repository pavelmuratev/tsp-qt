#include "tpsdraw.h"

TPSDraw::TPSDraw(QList<QList<QPair<int,int>>> cities)
{
    this->cities = cities;
    this->view = new QGraphicsView();
}

void TPSDraw::render()
{
    qDebug()<<cities.size();
    for(int i = 0;i<this->cities.length();i++)
    {
        int minDist;
        minDist = getMinDistance(this->cities[i]);
        this->addRect(i*150,0,100,50,QPen(Qt::black),QBrush(Qt::red));
        QGraphicsTextItem *text = new QGraphicsTextItem(QString::number(i));
        text->setPos(i*150+50,12);
        text->setFont(QFont("Arial",12,0));
        this->addItem(text);
        if(i!=this->cities.length()-1)
        {
            this->addLine(i*150+100,25,i*150+150,25);
            QGraphicsTextItem* dist = new QGraphicsTextItem(QString::number(cities[i][minDist].second));
            qDebug()<<cities[i][minDist].second;
            dist->setFont(QFont("Arial",10,0));
            dist->setPos(i*150+110,25);
            this->addItem(dist);
        }
    }

    this->view->setScene(this);
    this->view->show();
}

int TPSDraw::getMinDistance(QList<QPair<int,int>> city)
{
    int min = INT_MAX;
    int index = 0;
    for(int i = 0;i<city.length();i++)
    {
        if(city[i].second<min)
        {
            min = city[i].second;
            index = i;
        }
    }
    return index;
}

void TPSDraw::setCities(QList<QList<QPair<int,int>>> cities)
{
    this->cities = cities;
}

QList<QList<QPair<int,int>>> TPSDraw::getCities()
{
    return this->cities;
}

QGraphicsView *TPSDraw::getView() const
{
    return view;
}
