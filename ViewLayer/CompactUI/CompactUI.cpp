#include "CompactUI.h"
#include "ui_CompactUI.h"

CompactUI::CompactUI()
    :ui(new Ui::CompactUI)
{
    ui->setupUi(this);

    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell1Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell2Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell3Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell4Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell5Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell6Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell7Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU1Cell8Voltage);

    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell1Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell2Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell3Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell4Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell5Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell6Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell7Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU2Cell8Voltage);

    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell1Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell2Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell3Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell4Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell5Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell6Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell7Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU3Cell8Voltage);

    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell1Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell2Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell3Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell4Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell5Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell6Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell7Voltage);
    batteryCMUCellVoltageLabels_.append(ui->batteryCMU4Cell8Voltage);
}

CompactUI::~CompactUI()
{
    delete ui;
}

QLabel& CompactUI::setSetSpeed()
{
    return *ui->setSpeed;
}
QLabel& CompactUI::setSetCurrent()
{
    return *ui->setCurrent;
}
QLabel& CompactUI::setActualSpeed()
{
    return *ui->actualSpeed;
}
QLabel& CompactUI::setBusCurrent()
{
    return *ui->busCurrent;
}
QLabel& CompactUI::setBusVoltage()
{
    return *ui->busVoltage;
}
QLabel& CompactUI::setBatteryCurrent()
{
    return *ui->batteryCurrent;
}
QLabel& CompactUI::setBatteryVoltage()
{
    return *ui->batteryVoltage;
}
QLabel& CompactUI::setBatteryCMU1Temp()
{
    return *ui->batteryCMU1Temp;
}
QLabel& CompactUI::setBatteryCMU1Cell1Voltage()
{
    return *ui->batteryCMU1Cell1Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell2Voltage()
{
    return *ui->batteryCMU1Cell2Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell3Voltage()
{
    return *ui->batteryCMU1Cell3Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell4Voltage()
{
    return *ui->batteryCMU1Cell4Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell5Voltage()
{
    return *ui->batteryCMU1Cell5Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell6Voltage()
{
    return *ui->batteryCMU1Cell6Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell7Voltage()
{
    return *ui->batteryCMU1Cell7Voltage;
}
QLabel& CompactUI::setBatteryCMU1Cell8Voltage()
{
    return *ui->batteryCMU1Cell8Voltage;
}
QLabel& CompactUI::setBatteryCMU2Temp()
{
    return *ui->batteryCMU2Temp;
}
QLabel& CompactUI::setBatteryCMU2Cell1Voltage()
{
    return *ui->batteryCMU2Cell1Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell2Voltage()
{
    return *ui->batteryCMU2Cell2Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell3Voltage()
{
    return *ui->batteryCMU2Cell3Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell4Voltage()
{
    return *ui->batteryCMU2Cell4Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell5Voltage()
{
    return *ui->batteryCMU2Cell5Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell6Voltage()
{
    return *ui->batteryCMU2Cell6Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell7Voltage()
{
    return *ui->batteryCMU2Cell7Voltage;
}
QLabel& CompactUI::setBatteryCMU2Cell8Voltage()
{
    return *ui->batteryCMU2Cell8Voltage;
}
QLabel& CompactUI::setBatteryCMU3Temp()
{
    return *ui->batteryCMU3Temp;
}
QLabel& CompactUI::setBatteryCMU3Cell1Voltage()
{
    return *ui->batteryCMU3Cell1Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell2Voltage()
{
    return *ui->batteryCMU3Cell2Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell3Voltage()
{
    return *ui->batteryCMU3Cell3Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell4Voltage()
{
    return *ui->batteryCMU3Cell4Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell5Voltage()
{
    return *ui->batteryCMU3Cell5Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell6Voltage()
{
    return *ui->batteryCMU3Cell6Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell7Voltage()
{
    return *ui->batteryCMU3Cell7Voltage;
}
QLabel& CompactUI::setBatteryCMU3Cell8Voltage()
{
    return *ui->batteryCMU3Cell8Voltage;
}
QLabel& CompactUI::setBatteryCMU4Temp()
{
    return *ui->batteryCMU4Temp;
}
QLabel& CompactUI::setBatteryCMU4Cell1Voltage()
{
    return *ui->batteryCMU4Cell1Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell2Voltage()
{
    return *ui->batteryCMU4Cell2Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell3Voltage()
{
    return *ui->batteryCMU4Cell3Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell4Voltage()
{
    return *ui->batteryCMU4Cell4Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell5Voltage()
{
    return *ui->batteryCMU4Cell5Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell6Voltage()
{
    return *ui->batteryCMU4Cell6Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell7Voltage()
{
    return *ui->batteryCMU4Cell7Voltage;
}
QLabel& CompactUI::setBatteryCMU4Cell8Voltage()
{
    return *ui->batteryCMU4Cell8Voltage;
}

QLabel& CompactUI::setMppt1PowerIn()
{
   return *ui->mppt1PowerIn;
}
QLabel& CompactUI::setMppt1PowerOut()
{
   return *ui->mppt1PowerOut;
}
QLabel& CompactUI::setMppt1Efficiency()
{
    return *ui->mppt1Efficiency;
}

QLabel& CompactUI::setMppt2PowerIn()
{
   return *ui->mppt2PowerIn;
}
QLabel& CompactUI::setMppt2PowerOut()
{
   return *ui->mppt2PowerOut;
}
QLabel& CompactUI::setMppt2Efficiency()
{
    return *ui->mppt2Efficiency;
}

QLabel& CompactUI::setMppt3PowerIn()
{
   return *ui->mppt3PowerIn;
}
QLabel& CompactUI::setMppt3PowerOut()
{
   return *ui->mppt3PowerOut;
}
QLabel& CompactUI::setMppt3Efficiency()
{
    return *ui->mppt3Efficiency;
}

QLabel& CompactUI::setMppt4PowerIn()
{
   return *ui->mppt4PowerIn;
}
QLabel& CompactUI::setMppt4PowerOut()
{
   return *ui->mppt4PowerOut;
}
QLabel& CompactUI::setMppt4Efficiency()
{
    return *ui->mppt4Efficiency;
}


QLabel& CompactUI::setMppt5PowerIn()
{
   return *ui->mppt5PowerIn;
}
QLabel& CompactUI::setMppt5PowerOut()
{
   return *ui->mppt5PowerOut;
}
QLabel& CompactUI::setMppt5Efficiency()
{
    return *ui->mppt5Efficiency;
}

QLabel& CompactUI::setMppt6PowerIn()
{
   return *ui->mppt6PowerIn;
}
QLabel& CompactUI::setMppt6PowerOut()
{
   return *ui->mppt6PowerOut;
}
QLabel& CompactUI::setMppt6Efficiency()
{
    return *ui->mppt6Efficiency;
}

QLabel& CompactUI::setMppt7PowerIn()
{
   return *ui->mppt7PowerIn;
}
QLabel& CompactUI::setMppt7PowerOut()
{
   return *ui->mppt7PowerOut;
}
QLabel& CompactUI::setMppt7Efficiency()
{
    return *ui->mppt7Efficiency;
}

QList<QLabel*>& CompactUI::batteryCMUCellVoltageLabels()
{
    return batteryCMUCellVoltageLabels_;
}
QTextEdit& CompactUI::historyTextEdit()
{
   return *ui->historyTextEdit;
}
QLabel& CompactUI::setInputSerialConnectionStatus()
{
    return *ui->inputSerialConnectionStatus;
}
QLabel& CompactUI::setOutput3GConnectionStatus()
{
    return *ui->output3GConnectionStatus;
}
