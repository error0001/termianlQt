#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <myserial.h>


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    QList<QSerialPortInfo> aboutPorts;  // This list is used to save data about ports
    MySerial serial;    // Obj. at myserial.h
    QString allPorts;
    static const int MAX_RATES = 3;
    int baudRates[MAX_RATES];           // for comboBoxset baudrate
    bool flagFind;                      // for buttons
    bool flagConnect;                   // for buttons
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
