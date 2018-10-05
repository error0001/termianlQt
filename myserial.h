#ifndef MYSERIAL_H
#define MYSERIAL_H
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

class MySerial
{
private:
    // Not system methods and variables
    QSerialPort *serial;
    QList<QSerialPortInfo> portsInfo;
public:
    MySerial();
    bool Connet(QString, int);
    bool Disconect();
    ~MySerial();
};

#endif // MYSERIAL_H
