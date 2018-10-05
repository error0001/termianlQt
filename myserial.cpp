#include "myserial.h"

MySerial::MySerial()
{

}

// This button is "Choise baud rate"
bool MySerial::Connet(QString in_port_name, int in_rate)
{
    //QString port_name =  ui->comboBoxComs->itemText(ui->comboBoxComs->currentIndex());
    try//if (in_port_name != NULL)  // test to incoming data
    {
        serial->setPortName(in_port_name);
        serial->setBaudRate((qint32)in_rate);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        if(serial->open(QIODevice::ReadWrite))
        {
            QByteArray data;
            data = "Conect is available";
            serial->write(data);
            return true;
        }
        else
        {
            return false;
        }
    }
    catch()
    {
        return false;
    }
}

MySerial::~MySerial()
{
    delete serial;
}
