#ifndef PORT_H
#define PORT_H

#include <QObject>

class Port : public QObject
{
    //В QML доступно только свойство
    int counter;
    Q_OBJECT
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
public:
    explicit Port(QObject *parent = nullptr);

    //Описание методов для доступа к свойству
    int getNumber() const;
    void setNumber(int number);



signals:
    //Сигнал изменения свойства
    void numberChanged();


public slots:
//    void counterChange();
protected:
    void timerEvent(QTimerEvent* event);
private:
    int mNumber;
};

#endif // PORT_H
