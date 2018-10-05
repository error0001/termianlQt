#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Init all baud rates in the array
    baudRates[0] = 9600;
    baudRates[1] = 57600;
    baudRates[2] = 115200;
    // Init array of baud rates in the combobox
    ui->comboBoxBaudRates->addItem(QString::number(baudRates[0]));
    ui->comboBoxBaudRates->addItem(QString::number(baudRates[1]));
    ui->comboBoxBaudRates->addItem(QString::number(baudRates[2]));
    flagFind = true;
    flagConnect = true;
}

// This button is "find all ports"
void MainWindow::SearchPorts()
{
   pNames = QSerialPortInfo::availablePorts();          // Get list ports
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
void MainWindow::ChoiseBaudRate()
{
    //int temp = ui->comboBox->currentIndex();
    //int temp2 = pNames.at(temp).serialNumber().toInt;
    //serial.setPort(22);  // ui->comboBox->currentText()
    serial.setBaudRate(ui->comboBoxBaudRates->currentText().toInt());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFind_clicked()
{
    if(flagFind == true)
    {
        SearchPorts();
        ui->comboBoxComs->setEnabled(true);
        ui->pushButtonFind->setText("RESTART");
        flagFind = false;
    }
    else if(flagFind == false)
    {
        ui->comboBoxComs->setEnabled(false);
        ui->pushButtonFind->setText("FIND");
        ui->comboBoxComs->clear();                  // clear all items , all coms
        pNames.clear();                             // clear list
        ui->comboBoxComs->setEnabled(true);            // disable comboBox of comports
        flagFind = true;
    }
}

void MainWindow::on_pushButtonConnect_clicked()
{
    if (ui->comboBoxComs->itemText(0) != NULL)
    {
        if(flagConnect)
        {
            ChoiseBaudRate();
            ui->comboBoxComs->setEnabled(false);
            ui->comboBoxBaudRates->setEnabled(false);
            ui->pushButtonFind->setEnabled(false);
            ui->pushButtonConnect->setText("Disconect");
            flagConnect = false;
        }
        else if(flagConnect == false)
        {
            ui->pushButtonFind->setEnabled(true);          // disable find button
            ui->comboBoxComs->setEnabled(true);
            ui->comboBoxBaudRates->setEnabled(true);       // disable comboBox of BaudRates
            ui->pushButtonConnect->setText("Connect");      //
            flagConnect = true;
        }
    }
}

void MainWindow::on_pushButtonSend_clicked()
{

}

void MainWindow::on_pushButtonClearWindow_clicked()
{
    ui->textEditMain->clear();
}
