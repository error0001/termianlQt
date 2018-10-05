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
    ui->comboBox_2->addItem(QString::number(baudRates[0]));
    ui->comboBox_2->addItem(QString::number(baudRates[1]));
    ui->comboBox_2->addItem(QString::number(baudRates[2]));
}

// This button is "find all ports"
void MainWindow::SearchPorts()
{
   pNames = QSerialPortInfo::availablePorts();          // Get list ports
   ui->comboBox->clear();                               // Clear a comboBox of ports
   for(int i = 0; i < pNames.size(); i++)
   {
     ui->comboBox->addItem(pNames.at(i).portName());    // Append all ports
     // All information will give in the screen
     ui->textEdit->append(pNames.at(i).portName());
     ui->textEdit->append(pNames.at(i).description());
     ui->textEdit->append(pNames.at(i).manufacturer());
     ui->textEdit->append("*************************");
   }
   ui->pushButton->setEnabled(false);                   // Disable this push button
}

// This button is "Choise baud rate"
void MainWindow::ChoiseBaudRate()
{
    ui->pushButton_2->setEnabled(false);
    int temp = ui->comboBox->currentIndex();
    int temp2 = pNames.at(temp).serialNumber().toInt;
    //serial.setPort(22);  // ui->comboBox->currentText()
    serial.setBaudRate(ui->comboBox_2->currentText().toInt());
    ui->comboBox->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SearchPorts();
}

void MainWindow::on_pushButton_2_clicked()
{
    ChoiseBaudRate();
}


