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

#include <QHostAddress>

  #include "BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h"
  #include "CommunicationLayer/CommDeviceControl/CommDeviceManager.h"
  #include "CommunicationLayer/CommDeviceControl/ConnectionController.h"
  #include "CommunicationLayer/CommDeviceControl/I_ConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/RadioConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/UdpConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
  #include "CommunicationPresenter.h"

CommunicationPresenter::CommunicationPresenter(
      UdpMessageForwarder& udpMessageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService,
      CommDeviceManager& commDeviceManager,
      I_CommunicationsMonitoringService& communicationsMonitoringService)
: udpMessageForwarder_(udpMessageForwarder)
, connectionController_(connectionController)
, udpConnectionService_(udpConnectionService)
, radioConnectionService_(radioConnectionService)
, commDeviceManager_(commDeviceManager)
, communicationsMonitoringService_(communicationsMonitoringService)
{
   relayPacketInformation();
   relayConnectionStatus();
}


void CommunicationPresenter::connectToDataSource(CommDefines::Type type)
{
   udpMessageForwarder_.stop();
   connectionController_.setDeviceType(type);
   if(connectionController_.connectToDataSource())
   {
      communicationsMonitoringService_.start();
      commDeviceManager_.connectToDevice(type);
      if (type == CommDefines::Serial)
      {
         udpMessageForwarder_.start();
      }
   }
}

void CommunicationPresenter::disconnectFromDataSource()
{
   udpMessageForwarder_.stop();
   communicationsMonitoringService_.stop();
   connectionController_.disconnectFromDataSource();
}

void CommunicationPresenter::setMulticastNetwork(const QString& groupAddressString, quint16 port)
{
   QHostAddress groupAddress = QHostAddress(groupAddressString);

   udpMessageForwarder_.setMulticastNetwork(groupAddress, port);
   udpConnectionService_.setMulticastNetwork(groupAddress, port);
}

void CommunicationPresenter::setSerialParameters(const QString& serialPortName, int baudRate)
{
   radioConnectionService_.setSerialParameters(serialPortName, baudRate);
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
   connect(&connectionController_, SIGNAL(connectionSucceeded()),
           this, SIGNAL(connectionSucceeded()));
   connect(&connectionController_, SIGNAL(connectionFailed(QString)),
           this, SIGNAL(connectionFailed(QString)));
}
