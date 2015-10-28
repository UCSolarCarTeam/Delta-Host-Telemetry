#pragma once

#include <QObject>
#include <QUdpSocket>
class I_CommDevice;

class UdpMessageForwarder : public QObject
{
   Q_OBJECT
public:
   UdpMessageForwarder(const I_CommDevice& device);
   virtual ~UdpMessageForwarder();

private slots:
   void forwardData(QByteArray data);

private:
   const I_CommDevice& device_;

   QUdpSocket socket_;
};
