#include "port.h"
#include <QDebug>

Port::Port(QObject *parent) : QObject(parent)
{

    serial = new QSerialPort();
    // Поиск доступнызх портов
    listSerial = QSerialPortInfo::availablePorts();
    QStringList s;
    foreach(QSerialPortInfo str, listSerial)
    {
        s << str.portName();
    }


    setPorts(s);


    mNumber = 0;

    setIndexPort(0);


    //    QString str[];

    startTimer(5000);
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

    //Получение списка доступных портов


    setNumber(mNumber+1);
}

void Port::myMethod()
{
    qDebug()<< "mymethod";
}

void Port::connectToSerial()
{
    qDebug() << "ПОДКЛЮЧЕНИЕ К " << mIndexPort;


    QByteArray data = "cxfdfdf";

    qDebug() << mIndexPort;
    serial->setPort(listSerial[mIndexPort]);
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QSerialPort::ReadWrite);

    if(serial->isWritable())
    {
        qDebug() << "Yes, i can write to port!";
    }

    if(serial->isOpen())
    {
        qDebug() << "ПОДКЛЮЧЕНО";
        serial->write(data);
    }


}

void Port::closeSerial()
{

    if(serial->isOpen())
    {
        qDebug() << "ОТКЛЮЧАЕМСЯ";
        serial->close();
    }

}

QStringList Port::getPorts()
{
    return mListPorts;
}

void Port::setPorts(QStringList p)
{
    mListPorts.clear();
    mListPorts = p;
    emit portsChanged();
}

void Port::setIndexPort(int index)
{
    mIndexPort = index;
    emit indexPortChanged();
}
