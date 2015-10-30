#pragma once

#include <QSerialPort>
#include <QString>
#include "I_CommDevice.h"

class RadioCommDevice : public I_CommDevice
{
   Q_OBJECT
public:
   RadioCommDevice(QSerialPort& serialPort);
   virtual ~RadioCommDevice();

private slots:
   void handleSerialDataIncoming();
   bool connectToDataSource();

private:
   void setSerialParameters(QString serialPortName, int baudRate);

private:
   QSerialPort& serialPort_;
};
