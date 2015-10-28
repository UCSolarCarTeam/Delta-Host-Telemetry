#include <QByteArray>
#include <QDebug>
#include <QHostAddress>

#include "I_CommDevice.h"
#include "UdpMessageForwarder.h"

namespace
{
   const QHostAddress MULTICAST_ADDRESS = QHostAddress("239.255.43.21");
   const quint16 MULTICAST_PORT = 44550;
}

UdpMessageForwarder::UdpMessageForwarder(const I_CommDevice& device)
: device_(device)
{
   connect(&device_, SIGNAL(dataReceived(QByteArray)),
      this, SLOT(forwardData(QByteArray)));
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
   const quint64 dataWritten = socket_.writeDatagram(data, MULTICAST_ADDRESS, MULTICAST_PORT);
   if (dataWritten != static_cast<quint64>(data.size()))
   {
      qWarning() << "Unable to forward data";
   }
}
