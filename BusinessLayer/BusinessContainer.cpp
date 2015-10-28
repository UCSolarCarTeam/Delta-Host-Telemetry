#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"
#include "LoggerService/LoggerService.h"

BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer)
: loggerService_(new LoggerService(
   communicationContainer.packetSynchronizer(),
   communicationContainer.packetDecoder()))
, communicationsMonitoringService_(new CommunicationsMonitoringService(
   communicationContainer.packetChecksumChecker()))
{
}

BusinessContainer::~BusinessContainer()
{
}

I_CommunicationsMonitoringService& BusinessContainer::communicationsMonitoringService()
{
   return *communicationsMonitoringService_;
}
