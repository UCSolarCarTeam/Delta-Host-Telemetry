/**
 *  Schulich Delta Host Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Schulich Delta Host Telemetry
 *
 *  The Schulich Delta Host Telemetry is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Schulich Delta Host Telemetry is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Schulich Delta Host Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#pragma once

#include <QObject>
class QHostAddress;

#include "../../CommunicationLayer/CommDeviceControl/CommDefines.h"
class ConnectionController;
class RadioConnectionService;
class UdpConnectionService;
class UdpMessageForwarder;
class CommDeviceManager;
class I_CommunicationsMonitoringService;

class CommunicationPresenter : public QObject
{
	Q_OBJECT
public:
   explicit CommunicationPresenter(
      UdpMessageForwarder& udpMessageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService,
      CommDeviceManager& commDeviceManager,
      I_CommunicationsMonitoringService& communicationsMonitoringService);

   void connectToDataSource(CommDefines::Type type);
   void disconnectFromDataSource();

   void setMulticastNetwork(const QString& groupAddress, quint16 port);
   void setSerialParameters(const QString& serialPortName, int baudRate);


signals:
   void secondsSinceLastPacketReceivedUpdated(int secondsSinceLastPacketReceived);
   void packetsReceivedInLastMinuteUpdated(int packetsReceivedInLastMinute);
   void secondsSinceLastValidPacketReceivedUpdated(int secondsSinceLastValidPacketReceived);
   void validPacketsReceivedInLastMinuteUpdated(int validPacketsReceivedInLastMinute);
   void invalidPacketsReceivedInLastMinuteUpdated(int invalidPacketsReceivedInLastMinute);

   void connectionSucceeded();
   void connectionFailed(QString failureMessage);

private:
   void relayPacketInformation();
   void relayConnectionStatus();

private:
   UdpMessageForwarder& udpMessageForwarder_;
   ConnectionController& connectionController_;
   UdpConnectionService& udpConnectionService_;
   RadioConnectionService& radioConnectionService_;
   CommDeviceManager& commDeviceManager_;
   I_CommunicationsMonitoringService& communicationsMonitoringService_;
};
