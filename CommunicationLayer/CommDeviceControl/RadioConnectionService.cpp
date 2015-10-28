#include <QDebug>
#include <QTimer>
#include "RadioConnectionService.h"

namespace
{
   const QString DEFAULT_PORT_NAME = "/dev/ttyAMA0";
   const int DEFAULT_BAUDRATE = 9600;
}

RadioConnectionService::RadioConnectionService(QSerialPort& serialPort)
: serialPort_(serialPort)
{
   setSerialParameters(DEFAULT_PORT_NAME, DEFAULT_BAUDRATE);
   // This makes sure that it is connected after everything is created.
   // Otherwise the error messages won't be sent to the GUI
   QTimer::singleShot(0, this, SLOT(connectToDataSource()));
}

RadioConnectionService::~RadioConnectionService()
{
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
      connect(&serialPort_, SIGNAL(readyRead()),
         this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
      emit connectionSucceeded();
      return true;
   }
   else
   {
      qDebug() << serialPort_.errorString();
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioConnectionService::handleSerialDataIncoming()
{
   QByteArray incomingData = serialPort_.readAll();
   if (incomingData.isEmpty())
   {
      return;
   }
   emit dataReceived(incomingData);
}
