#include <QHostAddress>

#include "BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "CommunicationLayer/CommDeviceControl/I_CommDevice.h"
#include "CommunicationPresenter.h"

CommunicationPresenter::CommunicationPresenter(
      I_CommDevice& commDevice,
      I_CommunicationsMonitoringService& communicationsMonitoringService)
: commDevice_(commDevice)
, communicationsMonitoringService_(communicationsMonitoringService)
{
   relayPacketInformation();
   relayConnectionStatus();
}

void CommunicationPresenter::relayPacketInformation()
{
   connect(&communicationsMonitoringService_, SIGNAL(secondsSinceLastPacketReceivedUpdate(int)),
           this, SIGNAL(secondsSinceLastPacketReceivedUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(packetsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(packetsReceivedInLastMinuteUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(secondsSinceLastValidPacketReceivedUpdate(int)),
           this, SIGNAL(secondsSinceLastValidPacketReceivedUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(validPacketsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(validPacketsReceivedInLastMinuteUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(invalidPacketsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(invalidPacketsReceivedInLastMinuteUpdated(int)));
}

void CommunicationPresenter::relayConnectionStatus()
{
   connect(&commDevice_, SIGNAL(connectionSucceeded()),
           this, SIGNAL(connectionSucceeded()));
   connect(&commDevice_, SIGNAL(connectionFailed(const QString&)),
           this, SIGNAL(connectionFailed(const QString&)));
}
