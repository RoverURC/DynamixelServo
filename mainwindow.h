#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <dynamixelservo.h>
#include <QMainWindow>
#include <QtCore/QtGlobal>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
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
  //QSerialPortInfo myPortInfo;
  DynamixelServo *myServo;

  bool initializePort();
};

#endif // MAINWINDOW_H
