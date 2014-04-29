#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QMutex>

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow),  myTimer(new QTimer(this))
{
  ui->setupUi(this);
  myPort=new QextSerialPort(QextSerialPort::EventDriven,this); //Make new QextSerialPort then close it
  myPort->close();

  connect(myPort,SIGNAL(readyRead()),this,SLOT(read()));
  //connect(myPort, SIGNAL(readChannelFinished()), this, SLOT(readFinished()));
  //connect(myTimer, SIGNAL(timeout()), this, SLOT(write()));
  myTimer->start(1000);
  angle =0;
  speed = 0;

  initializePort("/dev/ttyAMA0");

  myServo = new DynamixelServo(1,myPort);
  myServo->setStatusReturnPackage(2, true);
}


bool MainWindow::initializePort(QString portName)
{
  delete myPort;
  myPort= new QextSerialPort(portName);
  myPort->setBaudRate(BAUD9600);
  myPort->setFlowControl(FLOW_OFF);
  myPort->setParity(PAR_NONE);
  myPort->setDataBits(DATA_8);
  myPort->setStopBits(STOP_1);
  //port->setQueryMode(QextSerialPort::Polling);
  myPort->close();
  if (myPort->open(QIODevice::ReadWrite) == true){
      qDebug("port is opened");
  }
  else{
      qDebug("port is not open");
  }
    return true;
}
bool MainWindow::reinitializePort(QString portName)
{
    myPort->close();
    initializePort(portName);
    return true;
}


MainWindow::~MainWindow()
{
  myPort->close();
  delete ui;
}

void MainWindow::read(){

    QByteArray array = myPort->readAll();
    myPort->waitForReadyRead(100);
    array = myPort->readAll();
    qDebug()<<"odczytane dane";
    for(int i=0;i<array.size();i++){
        qDebug()<<(quint8)array[i];
    }
}

void MainWindow::write()
{
    angle += 10;
    double speed=10;
    if(myServo->temp == true)
        myServo->setSpeed(speed, false);
    myServo->temp=false;

    myServo->setAngle(angle, true);
    myServo->updateServo(true);
}


void MainWindow::on_pushButtonVMax_clicked()
{
    myServo->setSpeed(100, true);
}

void MainWindow::on_pushButtonVmin_clicked()
{
    myServo->setSpeed(5, true);
}

void MainWindow::on_pushButtonAngleMIN_clicked()
{
    myServo->setAngle(0, true);
}

void MainWindow::on_pushButtonAngleMax_clicked()
{
    myServo->setAngle(340, true);
}

void MainWindow::on_pushButton_torque_clicked()
{
    myServo->setTorqueOFF(true);
}

void MainWindow::on_pushButton_ccwwanglelimit_clicked()
{
    if(myServo->CCWAngleLimit)
    {   myServo->setCCWAngleLimit(0);
        myServo->CCWAngleLimit = false;}
    else
    {   myServo->setCCWAngleLimit(200.3);
        myServo->CCWAngleLimit = true;}
}

void MainWindow::on_pushButton_blinkLed_clicked()
{
    myServo->turnLed(false);
}

void MainWindow::on_pushButtonAngleNSpeed_clicked()
{
    this->angle +=10;
    this->speed +=1;
    myServo->setAngleAndSpeed(angle,speed, false);
    myServo->updateServo(true);

}

void MainWindow::on_pushButton_action_clicked()
{
    myServo->updateServo(false);
}

void MainWindow::on_pushButton_clicked()
{
    myServo->setAlarmLeds(true, true);
}

void MainWindow::on_pushButton_wheelmodeOFF_clicked()
{
    myServo->setWheelMode(false, false);
}

void MainWindow::on_pushButton_wheelmode_clicked()
{
    myServo->setWheelMode(true, true);
}

void MainWindow::on_pushButton_torqueLow_clicked()
{
    myServo->setMaxTorque(10);
}

void MainWindow::on_pushButton_wheelmodeon_clicked()
{

}

void MainWindow::on_pushButton_dir_L_clicked()
{
    myServo->setDirectionAndSpeed(CCW_DIRECTION, 10, true);
}

void MainWindow::on_pushButton_dir_R_clicked()
{
    myServo->setDirectionAndSpeed(CW_DIRECTION, 10, true);
}

void MainWindow::on_pushButton_stop_clicked()
{
    myServo->stop(true,false);
}

void MainWindow::on_pushButton_reinitialize_Port_clicked()
{
    this->reinitializePort("COM3");
}
