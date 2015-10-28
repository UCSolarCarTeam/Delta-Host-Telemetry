#pragma once

#include <QScopedPointer>

class DataContainer;
class CommunicationContainerPrivate;

class I_DataInjectionService;
class I_PacketChecksumChecker;
class I_PacketDecoder;
class I_PacketSynchronizer;
class I_CommDevice;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   I_PacketSynchronizer& packetSynchronizer();
   I_PacketDecoder& packetDecoder();
   I_PacketChecksumChecker& packetChecksumChecker();
   I_DataInjectionService& dataInjectionService();
   I_CommDevice& commDevice();

private:
   // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
   QScopedPointer<CommunicationContainerPrivate> impl_;
};
