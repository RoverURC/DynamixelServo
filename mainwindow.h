#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dynamixelservo.h>
#include <QMainWindow>
#include <QtCore/QtGlobal>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  QSerialPort *myPort;

  DynamixelServo *myServo;
  QTimer *myTimer;

  bool initializePort(QString portName);
  bool reinitializePort(QString portName);
  int angle;
  int speed;

public slots:
  void read();
  void write();
  void readFinished();

private slots:
  void on_pushButtonVMax_clicked();
  void on_pushButtonVmin_clicked();
  void on_pushButtonAngleMIN_clicked();
  void on_pushButtonAngleMax_clicked();
  void on_pushButton_torque_clicked();
  void on_pushButton_ccwwanglelimit_clicked();
  void on_pushButton_blinkLed_clicked();
  void on_pushButtonAngleNSpeed_clicked();
  void on_pushButton_action_clicked();
  void on_pushButton_clicked();
  void on_pushButton_wheelmode_clicked();
  void on_pushButton_wheelmodeOFF_clicked();
  void on_pushButton_wheelmodeon_clicked();
  void on_pushButton_torqueLow_clicked();
  void on_pushButton_dir_L_clicked();
  void on_pushButton_dir_R_clicked();
  void on_pushButton_stop_clicked();
  void on_pushButton_reinitialize_Port_clicked();
};

#endif // MAINWINDOW_H
