#include "tpsdraw.h"

TPSDraw::TPSDraw(QVector<int> cities,double cost)
{
    this->cities = cities;
    this->view = new QGraphicsView();
    m_cost = cost;
}

void TPSDraw::render()
{

    for(int i = 0;i<this->cities.length();i++)
    {
        this->addRect(i*150,0,100,50,QPen(Qt::black),QBrush(Qt::blue));

        QGraphicsTextItem* num = new QGraphicsTextItem(QString::number(cities[i]));

        num->setPos(i*150+50,12);
        num->setFont(QFont("Arial",12,0));
        this->addItem(num);


        if(i!=this->cities.length()-1)
        {
            this->addLine(i*150+100,25,i*150+150,25);
        }

    }

    this->addRect(150,100,100,50,QPen(Qt::black),QBrush(Qt::blue));

    QGraphicsTextItem* cost = new QGraphicsTextItem(QString::number( m_cost ));

    cost->setPos(190,112);
    cost->setFont(QFont("Arial",12,0));
    this->addItem(cost);
    QGraphicsTextItem* costText = new QGraphicsTextItem(QString( "Tour cost: "));
    costText->setFont(QFont("Arial",15,0));
    costText->setPos(0,112);
    this->addItem(costText);


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
