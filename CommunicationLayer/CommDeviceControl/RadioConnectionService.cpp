#include "RadioConnectionService.h"
#include <QDebug>

namespace
{
   const QString DEFAULT_PORT_NAME = "/dev/ttyAMA0";
   // const QString DEFAULT_PORT_NAME = "COM5";
   const int DEFAULT_BAUDRATE = 9600;
}

RadioConnectionService::RadioConnectionService(QSerialPort& serialPort)
: serialPort_(serialPort)
{
   setSerialParameters(DEFAULT_PORT_NAME, DEFAULT_BAUDRATE);
   connectToDataSource();
}

RadioConnectionService::~RadioConnectionService()
{
   disconnectFromDataSource();
}

void RadioConnectionService::setSerialParameters(QString serialPortName, int baudRate)
{
   serialPort_.setPortName(serialPortName);
   serialPort_.setBaudRate(baudRate);
}

bool RadioConnectionService::connectToDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioConnectionService::disconnectFromDataSource()
{
   serialPort_.close();
   emit connectionFailed("DISCONNECTED");
}
