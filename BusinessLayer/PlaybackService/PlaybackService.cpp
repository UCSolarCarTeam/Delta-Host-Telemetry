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
#include <QDataStream>
#include <QDateTime>
#include <QDebug>
#include <QFile>

#include "PlaybackService.h"
#include "../../CommunicationLayer/PacketUnstuffer/I_DataInjectionService.h"

namespace
{
   const int NUMBER_OF_MESSAGES_TO_INJECT = 20;
}

PlaybackService::PlaybackService(I_DataInjectionService& injectionService)
: injectionService_(injectionService)
{
}

PlaybackService::~PlaybackService()
{
}

void PlaybackService::loadFile(const QString& fileName)
{
   QFile file(fileName);
   if (!file.open(QIODevice::ReadOnly))
   {
      const QString errorText = QString("Unable to open file for playback").arg(fileName);
      qWarning() << errorText;
      return;
   }

   data_.clear();
   QDataStream dataStreamIn(&file);

   while (!dataStreamIn.atEnd())
   {
      QDateTime date;
      QByteArray data;

      dataStreamIn >> date >> data;
      data_ << QPair<QDateTime, QByteArray>(date, data);
   }

   qDebug() << "Loaded" << data_.length() << "messages.";

   if (data_.length() == 0)
   {
      qWarning("Could not read data in file");
   }
   else
   {
      emit positionRangeUpdated(0, data_.length() - 1);
      emit dateUpdated(data_.at(0).first);
   }
}

void PlaybackService::loadPosition(int position)
{
   if (position < 0 || position >= data_.length())
   {
      return;
   }

   injectPriorMessagesBeforePosition(position);
   emit dateUpdated(data_.at(position).first);
}

void PlaybackService::injectPriorMessagesBeforePosition(int position)
{
   int positionOfFirstMessage = position - NUMBER_OF_MESSAGES_TO_INJECT;
   if (positionOfFirstMessage < 0)
   {
      positionOfFirstMessage = 0;
   }

   for (int i = positionOfFirstMessage; i <= position; i++)
   {
      injectionService_.injectFramedData(data_.at(i).second);
   }
}
