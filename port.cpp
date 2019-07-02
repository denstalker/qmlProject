#include "port.h"
#include <QDebug>

Port::Port(QObject *parent) : QObject(parent)
{
    mNumber = 0;
    startTimer(1000);
//    connect(this, SIGNAL(counterChanged()),this,SLOT(counterChange()));

}

int Port::getNumber() const
{
    return mNumber;
}

void Port::setNumber(int number)
{
    mNumber = number;
    emit numberChanged();
}

void Port::timerEvent(QTimerEvent *event)
{
    qDebug() << "timerEvent";
    setNumber(mNumber+1);
}

