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
