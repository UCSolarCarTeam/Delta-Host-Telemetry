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

#include <QByteArray>
#include <QDebug>

#include "I_CommDevice.h"
#include "UdpMessageForwarder.h"

UdpMessageForwarder::UdpMessageForwarder(const I_CommDevice& device)
: device_(device)
{
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::setMulticastNetwork(const QHostAddress& groupAddress, quint16 port)
{
   groupAddress_ = groupAddress;
   port_ = port;
}

void UdpMessageForwarder::start()
{
   connect(&device_, SIGNAL(dataReceived(QByteArray)),
      this, SLOT(forwardData(QByteArray)), Qt::UniqueConnection);
}

void UdpMessageForwarder::stop()
{
   disconnect(&device_, 0, this, 0);
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
   const quint64 dataWritten = socket_.writeDatagram(data, groupAddress_, port_);
   if (dataWritten != static_cast<quint64>(data.size()))
   {
      qWarning() << "Unable to forward data";
   }
}
