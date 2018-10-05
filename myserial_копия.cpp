#include "myserial.h"

MySerial::MySerial()
{

}

// This button is "find all ports"
void MySerial::SearchPorts(QString *workStr)
{
   pNames = QSerialPortInfo::availablePorts();              // Get list ports
   ui->comboBoxComs->clear();                               // Clear a comboBox of ports
   for(int i = 0; i < pNames.size(); i++)
   {
     ui->comboBoxComs->addItem(pNames.at(i).portName());    // Append all ports
     // All information will give in the screen
     ui->textEditMain->append(pNames.at(i).portName());
     ui->textEditMain->append(pNames.at(i).description());
     ui->textEditMain->append(pNames.at(i).manufacturer());
     ui->textEditMain->append("*************************");
   }
}

// This button is "Choise baud rate"
void MySerial::ConnetToCom()
{
    QString port_name =  ui->comboBoxComs->itemText(ui->comboBoxComs->currentIndex());
    serial->setPortName(port_name);
    serial->setBaudRate(ui->comboBoxBaudRates->currentText().toInt());
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(serial->open(QIODevice::ReadWrite))
    {
        ui->textEditMain->append("Connected");
        QByteArray data;
        data = "Conect is available";
        serial->write(data);
    }
    else
    {
        ui->textEditMain->append("Error of connection");
    }
}
