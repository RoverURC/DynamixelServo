#ifndef DYNAMIXELSERVO_H
#define DYNAMIXELSERVO_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include <QBitArray>
class DynamixelServo : public QObject
{
  Q_OBJECT
public:
  explicit DynamixelServo(quint8 id, QSerialPort *device, QObject *parent = 0);
  ~DynamixelServo();

  bool setID(quint8 id);

  bool setSpeed(double Speed, bool now); //in percent  // Return true if operation succesfull,
                                         // If now is false then we need to use updateServo to set action
  bool setAngle(double angle, bool now); //0-300 degree
  bool setCCAngleLimit(double cCAngle); //min 0
  bool setCCWAngleLimit(double cCWAngle); //max 300

  bool updateServo(bool all); //this or broadcast
  bool doReset(bool all); //this or broadcast

  bool getPresentAngle(quint8 &value);
  bool getPresentVoltage(quint8 &value);
  bool getActualSpeed(quint8 &value);
  bool getSettedPosition(quint8 &value);

  bool test();

private:
  QSerialPort *device;  //Serial Port Device ( One for all UartServos)
  quint8 id; //1 - fabric, 2-250
  bool B2b(QByteArray &bytes, QBitArray &bits);
  bool b2B(QByteArray &bytes, QBitArray &bits);
  bool countCRC();

  QByteArray byteArray;
  QByteArray CRC;

 // QByteArray formatFrame(/*Tutaj chyba musisz dac te parametry ramki które są zmienne */); //Ta funkcja moze uzywac countCRC()
};

#endif // DYNAMIXELSERVO_H
