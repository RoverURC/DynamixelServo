#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  //myPortInfo(),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
 // myPort = new QSerialPort(myPortInfo,this);
  myPort = new QSerialPort(this);
  initializePort();

          QByteArray BA("FF");
          BA.append("FF");
          BA.append("01");
          BA.append("05");
          BA.append("03");
          BA.append("1E");
          BA.append("00");
          BA.append("00");
          BA.append("D8");

  myPort->write(BA);

  myServo = new DynamixelServo(1,myPort);
  //myServo->test();

  //myServo->setAngle(wartość); //Tutaj możesz testowac funkcje, ale to ci sie wykona tylko przy starcie,
                       //bo to konstruktor głównego okna, możesz porobic buttony i okienka
                       // i stworzyc tutaj w MainWindow sloty w których wywołujesz funkcje
                       // i połączyć sygnały z tych buttonów ze slotami

}
bool MainWindow::initializePort()
{
    myPort->setBaudRate(QSerialPort::Baud115200);
    myPort->setDataBits(QSerialPort::Data8);
    myPort->setParity(QSerialPort::NoParity);
    myPort->setStopBits(QSerialPort::OneStop);
    myPort->setFlowControl(QSerialPort::NoFlowControl);

    QString name = "sad";
    myPort->setPortName("COM3");
    if(myPort->open(QIODevice::ReadWrite))
    {   if(true)
            return true;
        else
        {   myPort->close();
            return false;
        }
    }
    else
    {   myPort->error();
        return false;
    }
    return true;
}

MainWindow::~MainWindow()
{
  delete ui;
}
//Przykladowy slot
/*
void MainWindow::onButtonClick(){
  myServo->setAngle(this->ui->lineEditAngle->text().toInt());
}
*/
