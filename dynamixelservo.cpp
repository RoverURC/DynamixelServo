#include "dynamixelservo.h"

DynamixelServo::DynamixelServo(quint8 id, QSerialPort *device, QObject *parent) :
  QObject(parent)
{
  this->device = device; //Przypisanie urządzenia
  this->id = id;
}
DynamixelServo::~DynamixelServo()
{}

bool DynamixelServo::setID(quint8 id)
{
    return true;
}
bool DynamixelServo::test()
{
    QByteArray BA("FF");
    BA.append("FF");
    BA.append("01");
    BA.append("05");
    BA.append("03");
    BA.append("1E");
    BA.append("00");
    BA.append("00");
    BA.append("D8");

    device->write("FFFF0105031E0000D8");
    return true;
}

/*bool DynamixelServo::setAngle(double angle, bool now)
{
    byteArray.clear();
    byteArray.append(0xFF);
    byteArray.append(0xFF);
    //id
    byteArray.append(this->id);
    byteArray.append(0x05);
    if(now == false)
    {
        byteArray.append(0x04);
    }
    else
    {
        byteArray.append(0x03);
    }
    byteArray.append(0x1E);
    quint16 intAngle = 300/(double)1024*angle; //it transform's angle in degrees
                                               //to proper value at quint for servo
    quint8 HB = intAngle/256;
    quint8 LB = intAngle-HB*256;
    QByteArray temp;
    temp.setNum(LB, 16);
    byteArray.append(temp);
    temp.setNum(HB, 16);
    byteArray.append(temp);

    return true;
}
bool DynamixelServo::countCRC()
{
    QBitArray bitArray; //temporary
    QBitArray CRC(8); //8 bits 0, 1 byte 0
    quint8 num1=0;
    quint8 num2=0;
    quint8 num4=0;
    quint8 num8=0;
    quint8 num16=0;
    quint8 num32=0;
    quint8 num64=0;
    quint8 num128=0;

    for(int b=2; b<byteArray.size(); b++)
    {   QByteArray B;
        B(byteArray[b]);
        int hex = B.toInt(&ok,16);

    }

    //convert every byte to bitArray, add to CRC; after all convert to byteArray
    for(int b=2; b<byteArray.size(); b++)
    {   if(B2b(byteArray[b],bitArray) == true)
        {   for(int i=0; i<8; i++)
            {   if(bitArray[0]==true)
                    num1++;
                if(bitArray[1]==true)
                                    num1++;
                if(bitArray[2]==true)
                                    num1++;
                if(bitArray[3]==true)
                                    num1++;
                if(bitArray[4]==true)
                                    num1++;
                if(bitArray[5]==true)
                                    num1++;
                if(bitArray[6]==true)
                                    num1++;
                if(bitArray[7]==true)
                                    num1++;
            }

        }

    }
    if(B2b(byteArray,bitArray) == true)
    {   for(int i=16; i<bitArray.size(); i++)
        {

        }

    }
    else
        return false;

    if(b2B(byteArray,bitArray) == true)
    {

    }
    else
        return false;
}
*/
bool DynamixelServo::setSpeed(double Speed, bool now)
{
    return true;
}
bool DynamixelServo::B2b(QByteArray &bytes, QBitArray &bits)
{
    // Create a bit array of the appropriate size
    QBitArray bitsTemp(bytes.count()*8);

    // Convert from QByteArray to QBitArray
    for(int i=0; i<bytes.count(); ++i)
        for(int b=0; b<8; ++b)
             bitsTemp.setBit(i*8+b, bytes.at(i)&(1<<(7-b)));
    bits=bitsTemp;
    return true;
}
bool DynamixelServo::b2B(QByteArray &bytes, QBitArray &bits)
{
    // Resulting byte array
    QByteArray bytesTemp;

    // Convert from QBitArray to QByteArray
    for(int b=0; b<bits.count(); ++b)
       bytesTemp[b/8] = (bytesTemp.at(b/8) | ((bits[b]?1:0)<<(b%8)));
    bytes=bytesTemp;
    return true;
}
