#pragma once

#include <QSerialPort>
#include <QString>
#include "I_CommDevice.h"

class RadioConnectionService : public I_CommDevice
{
   Q_OBJECT
public:
   RadioConnectionService(QSerialPort& serialPort);
   virtual ~RadioConnectionService();

private slots:
   void handleSerialDataIncoming();
   bool connectToDataSource();

private:
   void setSerialParameters(QString serialPortName, int baudRate);

private:
   QSerialPort& serialPort_;
};
