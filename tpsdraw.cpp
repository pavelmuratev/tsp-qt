#include "tpsdraw.h"

TPSDraw::TPSDraw(QVector<int> cities)
{
    this->cities = cities;
    this->view = new QGraphicsView();
}

void TPSDraw::render()
{

    for(int i = 0;i<this->cities.length();i++)
    {
        qDebug()<<i;
        this->addRect(i*150,0,100,50,QPen(Qt::black),QBrush(Qt::red));

        QGraphicsTextItem* num = new QGraphicsTextItem(QString::number(cities[i]));
        num->setPos(i*150+50,12);
        num->setFont(QFont("Arial",12,0));
        this->addItem(num);
        if(i!=this->cities.length()-1)
        {
            this->addLine(i*150+100,25,i*150+150,25);
        }
    }
    this->view->setScene(this);
    this->view->show();
}

void TPSDraw::setCities(QVector<int> cities)
{
    this->cities = cities;
}

QVector<int> TPSDraw::getCities()
{
    return this->cities;
}

QGraphicsView *TPSDraw::getView() const
{
    return view;
}
