#ifndef DYNAMIXELSERVO_H
#define DYNAMIXELSERVO_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
class DynamixelServo : public QObject
{
  Q_OBJECT
public:
  explicit DynamixelServo(quint8 id, QSerialPort *device, QObject *parent = 0);

  bool setID(quint8 id);

  bool setSpeed(double cpeed, bool now); //in percent  // Return true if operation succesfull,
                                         // If now is false then we need to use updateServo to set action
  bool setAngle(double angle, bool now); //0-300 degree
  bool setCCAngleLimit(double cCAngle); //min 0
  bool setCCWAngleLimit(double cCWAngle); //max 300

  bool updateServo(bool all); //this or broadcast
  bool doReset(bool all); //this or broadcast

  //nie mam pojęcia jakie zwracane
  bool getPresentAngle(quint16 &value);
  bool getPresentVoltage(quint16 &value);
  double getActualSpeed(quint16 &value);
  double getSettedPosition(quint16 &value);

private:
  QSerialPort *device;  //Serial Port Device ( One for all UartServos)
  quint8 id; //1 - fabric, 2-250

  QByteArray byteArray;
  quint16 countCRC(/*Tutaj chyba musisz dac te parametry ramki które są zmienne */);
  QByteArray formatFrame(/*Tutaj chyba musisz dac te parametry ramki które są zmienne */); //Ta funkcja moze uzywac countCRC()
};

#endif // DYNAMIXELSERVO_H
