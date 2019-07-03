#ifndef PORT_H
#define PORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVariant>

class Port : public QObject
{
    //В QML доступно только свойство и сигналы
    int counter;
    Q_OBJECT
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QStringList listPorts READ getPorts WRITE setPorts NOTIFY portsChanged)
    Q_PROPERTY(int indexPort WRITE setIndexPort NOTIFY indexPortChanged)


public:
    explicit Port(QObject *parent = nullptr);

    //Описание методов для доступа к свойству
    int getNumber() const;
    void setNumber(int number);

    QStringList getPorts();
    void setPorts (QStringList p);
    void setIndexPort(int);




signals:
    //Сигнал изменения свойства
    void numberChanged();
    void portsChanged();
    void indexPortChanged();

    void sendToQML(int,QString);


public slots:
//    void counterChange();
     void myMethod();
     void connectToSerial();
     void closeSerial();
protected:
    void timerEvent(QTimerEvent* event);
private:
    int mNumber;
    int mIndexPort;
    QSerialPort * serial;
    QStringList mListPorts;
    QList<QSerialPortInfo> listSerial;

};
#endif // PORT_H
