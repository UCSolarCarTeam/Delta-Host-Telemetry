#pragma once

#include <QObject>
class QHostAddress;
class QString;

class I_CommDevice;
class I_CommunicationsMonitoringService;

class CommunicationPresenter : public QObject
{
   Q_OBJECT
public:
   explicit CommunicationPresenter(
      I_CommDevice& commDevice,
      I_CommunicationsMonitoringService& communicationsMonitoringService);

signals:
   void secondsSinceLastPacketReceivedUpdated(int secondsSinceLastPacketReceived);
   void packetsReceivedInLastMinuteUpdated(int packetsReceivedInLastMinute);
   void secondsSinceLastValidPacketReceivedUpdated(int secondsSinceLastValidPacketReceived);
   void validPacketsReceivedInLastMinuteUpdated(int validPacketsReceivedInLastMinute);
   void invalidPacketsReceivedInLastMinuteUpdated(int invalidPacketsReceivedInLastMinute);

   void connectionSucceeded();
   void connectionFailed(const QString& errorString);

private:
   void relayPacketInformation();
   void relayConnectionStatus();

private:
   I_CommDevice& commDevice_;
   I_CommunicationsMonitoringService& communicationsMonitoringService_;
};
