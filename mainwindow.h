#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    // Not system methods and variables
    QSerialPort serial;
    QList<QSerialPortInfo> pNames;
    struct SettingsPort
    {
        QString name;   //  Name of Com port
        QString rate;   //  Baud rate   600 - 256000
        QString data;   //  Data bits   5-8
        QString prty;   //  Parity      none, odd, even, mark, space
        QString stpb;   //  Stop bits   1, 1,5, 2
        QString hshg;   //  Handshaking
    };
    SettingsPort configUsingPort;
    static const int MAX_RATES = 3;
    bool flagFind;
    bool flagConnect;
    int baudRates[MAX_RATES];
    void SearchPorts();
    void ChoiseBaudRate();
    // End n.s.m.
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButtonFind_clicked();
    void on_pushButtonConnect_clicked();
    void on_pushButtonSend_clicked();
    void on_pushButtonClearWindow_clicked();
};

#endif // MAINWINDOW_H
