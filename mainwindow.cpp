#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  //myPortInfo(),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
 // initializePort(); // Zamplementuj tą funkcję
 // myPort = new QSerialPort(myPortInfo,this);
  //myServo = new DynamixelServo(1,myPort,this);

  //myServo->setAngle(wartość); //Tutaj możesz testowac funkcje, ale to ci sie wykona tylko przy starcie,
                       //bo to konstruktor głównego okna, możesz porobic buttony i okienka
                       // i stworzyc tutaj w MainWindow sloty w których wywołujesz funkcje
                       // i połączyć sygnały z tych buttonów ze slotami

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
