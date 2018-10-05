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
    //serial = new QSerialPort(this);
}





MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonFind_clicked()
{
    ui->comboBoxComs->clear();  // Clear a comboBox of ports
    aboutPorts = QSerialPortInfo::availablePorts(); // get ports info
    if(flagFind == true)
    {
         // All information will give in the screen
        for(int i = 0; i < aboutPorts.size(); i++)
        {
            ui->comboBoxComs->addItem(aboutPorts.at(i).portName()); // Append all ports
            ui->textEditMain->append(aboutPorts.at(i).portName());
            ui->textEditMain->append(aboutPorts.at(i).description());
            ui->textEditMain->append(aboutPorts.at(i).manufacturer());
            ui->textEditMain->append("*************************");
        }

        ui->comboBoxComs->setEnabled(true);
        ui->pushButtonFind->setText("Restart");
        flagFind = false;
    }
    else if(flagFind == false)
    {
        ui->comboBoxComs->setEnabled(false);
        ui->pushButtonFind->setText("Find ports");
        ui->comboBoxComs->clear();  // clear all items , all coms
        aboutPorts.clear(); // clear list
        ui->comboBoxComs->setEnabled(true); // disable comboBox of comports
        flagFind = true;
    }
}

void MainWindow::on_pushButtonConnect_clicked()
{
    if (ui->comboBoxComs->itemText(0) != NULL)
    {
        if(flagConnect)
        {
            // Connect to port, set port name and baud rate;
            QString current_port = ui->comboBoxComs->itemText( ui->comboBoxComs->currentIndex() );
            int current_rate = ui->comboBoxBaudRates->currentText().toInt();
            if( serial.Connet(current_port,current_rate) )
            {
                ui->comboBoxComs->setEnabled(false);
                ui->comboBoxBaudRates->setEnabled(false);
                ui->pushButtonFind->setEnabled(false);
                ui->pushButtonConnect->setText("Disconect");
                flagConnect = false;
            }
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

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{

}
