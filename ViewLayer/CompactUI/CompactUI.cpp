#include "CompactUI.h"
#include "ui_CompactUI.h"

CompactUI::CompactUI()
    :ui(new Ui::CompactUI)
{
    ui->setupUi(this);
}

CompactUI::~CompactUI()
{
    delete ui;
}

QLabel& CompactUI::setSpeedLabel()
{
    return *ui->setSpeed;
}
QLabel& CompactUI::setCurrentLabel()
{
    return *ui->setCurrent;
}
QLabel& CompactUI::actualSpeedLabel()
{
    return *ui->actualSpeed;
}
QLabel& CompactUI::busCurrentLabel()
{
    return *ui->busCurrent;
}
QLabel& CompactUI::busVoltageLabel()
{
    return *ui->busVoltage;
}
QLabel& CompactUI::batteryCurrentLabel()
{
    return *ui->batteryCurrent;
}
QLabel& CompactUI::batteryVoltageLabel()
{
    return *ui->batteryVoltage;
}
QLabel& CompactUI::batteryCMU1TempLabel()
{
    return *ui->batteryCMU1Temp;
}
QLabel& CompactUI::batteryCMU1Cell1VoltageLabel()
{
    return *ui->batteryCMU1Cell1Voltage;
}
QLabel& CompactUI::batteryCMU1Cell2VoltageLabel()
{
    return *ui->batteryCMU1Cell2Voltage;
}
QLabel& CompactUI::batteryCMU1Cell3VoltageLabel()
{
    return *ui->batteryCMU1Cell3Voltage;
}
QLabel& CompactUI::batteryCMU1Cell4VoltageLabel()
{
    return *ui->batteryCMU1Cell4Voltage;
}
QLabel& CompactUI::batteryCMU1Cell5VoltageLabel()
{
    return *ui->batteryCMU1Cell5Voltage;
}
QLabel& CompactUI::batteryCMU1Cell6VoltageLabel()
{
    return *ui->batteryCMU1Cell6Voltage;
}
QLabel& CompactUI::batteryCMU1Cell7VoltageLabel()
{
    return *ui->batteryCMU1Cell7Voltage;
}
QLabel& CompactUI::batteryCMU1Cell8VoltageLabel()
{
    return *ui->batteryCMU1Cell8Voltage;
}
QLabel& CompactUI::batteryCMU2TempLabel()
{
    return *ui->batteryCMU2Temp;
}
QLabel& CompactUI::batteryCMU2Cell1VoltageLabel()
{
    return *ui->batteryCMU2Cell1Voltage;
}
QLabel& CompactUI::batteryCMU2Cell2VoltageLabel()
{
    return *ui->batteryCMU2Cell2Voltage;
}
QLabel& CompactUI::batteryCMU2Cell3VoltageLabel()
{
    return *ui->batteryCMU2Cell3Voltage;
}
QLabel& CompactUI::batteryCMU2Cell4VoltageLabel()
{
    return *ui->batteryCMU2Cell4Voltage;
}
QLabel& CompactUI::batteryCMU2Cell5VoltageLabel()
{
    return *ui->batteryCMU2Cell5Voltage;
}
QLabel& CompactUI::batteryCMU2Cell6VoltageLabel()
{
    return *ui->batteryCMU2Cell6Voltage;
}
QLabel& CompactUI::batteryCMU2Cell7VoltageLabel()
{
    return *ui->batteryCMU2Cell7Voltage;
}
QLabel& CompactUI::batteryCMU2Cell8VoltageLabel()
{
    return *ui->batteryCMU2Cell8Voltage;
}
QLabel& CompactUI::batteryCMU3TempLabel()
{
    return *ui->batteryCMU3Temp;
}
QLabel& CompactUI::batteryCMU3Cell1VoltageLabel()
{
    return *ui->batteryCMU3Cell1Voltage;
}
QLabel& CompactUI::batteryCMU3Cell2VoltageLabel()
{
    return *ui->batteryCMU3Cell2Voltage;
}
QLabel& CompactUI::batteryCMU3Cell3VoltageLabel()
{
    return *ui->batteryCMU3Cell3Voltage;
}
QLabel& CompactUI::batteryCMU3Cell4VoltageLabel()
{
    return *ui->batteryCMU3Cell4Voltage;
}
QLabel& CompactUI::batteryCMU3Cell5VoltageLabel()
{
    return *ui->batteryCMU3Cell5Voltage;
}
QLabel& CompactUI::batteryCMU3Cell6VoltageLabel()
{
    return *ui->batteryCMU3Cell6Voltage;
}
QLabel& CompactUI::batteryCMU3Cell7VoltageLabel()
{
    return *ui->batteryCMU3Cell7Voltage;
}
QLabel& CompactUI::batteryCMU3Cell8VoltageLabel()
{
    return *ui->batteryCMU3Cell8Voltage;
}
QLabel& CompactUI::batteryCMU4TempLabel()
{
    return *ui->batteryCMU4Temp;
}
QLabel& CompactUI::batteryCMU4Cell1VoltageLabel()
{
    return *ui->batteryCMU4Cell1Voltage;
}
QLabel& CompactUI::batteryCMU4Cell2VoltageLabel()
{
    return *ui->batteryCMU4Cell2Voltage;
}
QLabel& CompactUI::batteryCMU4Cell3VoltageLabel()
{
    return *ui->batteryCMU4Cell3Voltage;
}
QLabel& CompactUI::batteryCMU4Cell4VoltageLabel()
{
    return *ui->batteryCMU4Cell4Voltage;
}
QLabel& CompactUI::batteryCMU4Cell5VoltageLabel()
{
    return *ui->batteryCMU4Cell5Voltage;
}
QLabel& CompactUI::batteryCMU4Cell6VoltageLabel()
{
    return *ui->batteryCMU4Cell6Voltage;
}
QLabel& CompactUI::batteryCMU4Cell7VoltageLabel()
{
    return *ui->batteryCMU4Cell7Voltage;
}
QLabel& CompactUI::batteryCMU4Cell8VoltageLabel()
{
    return *ui->batteryCMU4Cell8Voltage;
}

QLabel& CompactUI::mppt1PowerInLabel()
{
   return *ui->mppt1PowerIn;
}
QLabel& CompactUI::mppt1PowerOutLabel()
{
   return *ui->mppt1PowerOut;
}
QLabel& CompactUI::mppt1EfficiencyLabel()
{
    return *ui->mppt1Efficiency;
}

QLabel& CompactUI::mppt2PowerInLabel()
{
   return *ui->mppt2PowerIn;
}
QLabel& CompactUI::mppt2PowerOutLabel()
{
   return *ui->mppt2PowerOut;
}
QLabel& CompactUI::mppt2EfficiencyLabel()
{
    return *ui->mppt2Efficiency;
}

QLabel& CompactUI::mppt3PowerInLabel()
{
   return *ui->mppt3PowerIn;
}
QLabel& CompactUI::mppt3PowerOutLabel()
{
   return *ui->mppt3PowerOut;
}
QLabel& CompactUI::mppt3EfficiencyLabel()
{
    return *ui->mppt3Efficiency;
}

QLabel& CompactUI::mppt4PowerInLabel()
{
   return *ui->mppt4PowerIn;
}
QLabel& CompactUI::mppt4PowerOutLabel()
{
   return *ui->mppt4PowerOut;
}
QLabel& CompactUI::mppt4EfficiencyLabel()
{
    return *ui->mppt4Efficiency;
}

QLabel& CompactUI::mppt5PowerInLabel()
{
   return *ui->mppt5PowerIn;
}
QLabel& CompactUI::mppt5PowerOutLabel()
{
   return *ui->mppt5PowerOut;
}
QLabel& CompactUI::mppt5EfficiencyLabel()
{
    return *ui->mppt5Efficiency;
}

QLabel& CompactUI::mppt6PowerInLabel()
{
   return *ui->mppt6PowerIn;
}
QLabel& CompactUI::mppt6PowerOutLabel()
{
   return *ui->mppt6PowerOut;
}
QLabel& CompactUI::mppt6EfficiencyLabel()
{
    return *ui->mppt6Efficiency;
}

QLabel& CompactUI::mppt7PowerInLabel()
{
   return *ui->mppt7PowerIn;
}
QLabel& CompactUI::mppt7PowerOutLabel()
{
   return *ui->mppt7PowerOut;
}
QLabel& CompactUI::mppt7EfficiencyLabel()
{
    return *ui->mppt7Efficiency;
}

QLabel& CompactUI::softwareOverCurrentLabel1()
{
   return *ui->softwareOverCurrentLabel1;
}
QLabel& CompactUI::hardwareOverCurrentLabel1()
{
   return *ui->hardwareOverCurrentLabel1;
}
QLabel& CompactUI::softwareOverCurrentLabel2()
{
   return *ui->softwareOverCurrentLabel2;
}
QLabel& CompactUI::hardwareOverCurrentLabel2()
{
   return *ui->hardwareOverCurrentLabel2;
}
QLabel& CompactUI::cellOverVoltageLabel()
{
   return *ui->cellOverVoltageLabel;
}
QLabel& CompactUI::cellUnderVoltageLabel()
{
   return *ui->cellUnderVoltageLabel;
}
QLabel& CompactUI::cellOverTemperatureLabel()
{
   return *ui->cellOverTemperatureLabel;
}
QLabel& CompactUI::cmuCommunicationsTimeoutLabel()
{
   return *ui->cmuCommunicationsTimeoutLabel;
}
QLabel& CompactUI::inputSerialConnectionStatusLabel()
{
    return *ui->inputSerialConnectionStatus;
}
QLabel& CompactUI::output3GConnectionStatusLabel()
{
    return *ui->output3GConnectionStatus;
}
