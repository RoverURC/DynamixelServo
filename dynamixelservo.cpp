#include "dynamixelservo.h"

DynamixelServo::DynamixelServo(quint8 id, QSerialPort *device, QObject *parent) :
  QObject(parent)
{
  this->device = device; //Przypisanie urządzenia
  this->id = id;
}

