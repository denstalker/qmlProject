#include "port.h"
#include <QDebug>

Port::Port(QObject *parent) : QObject(parent)
{
    mNumber = 0;
    QSerialPort serial;

    QList<QSerialPortInfo> listSerial;

    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QSerialPort::ReadWrite);


    listSerial = QSerialPortInfo::availablePorts();

    foreach(QSerialPortInfo str, listSerial)
    {
        qDebug() << str.portName();
    }
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

