#include "CompactUI.h"
#include "ui_CompactUI.h"

CompactUI::CompactUI()
    :ui(new Ui::CompactUI)
{
    mppt1CurrentIn=0;
    mppt1CurrentOut=0;
    mppt1VoltageOut=0;
    mppt1VoltageIn=0;
    mppt2CurrentIn=0;
    mppt2CurrentOut=0;
    mppt2VoltageOut=0;
    mppt2VoltageIn=0;
    mppt3CurrentIn=0;
    mppt3CurrentOut=0;
    mppt3VoltageOut=0;
    mppt3VoltageIn=0;
    mppt4CurrentIn=0;
    mppt4CurrentOut=0;
    mppt4VoltageOut=0;
    mppt4VoltageIn=0;
    mppt5CurrentIn=0;
    mppt5CurrentOut=0;
    mppt5VoltageOut=0;
    mppt5VoltageIn=0;
    mppt6CurrentIn=0;
    mppt6CurrentOut=0;
    mppt6VoltageOut=0;
    mppt6VoltageIn=0;
    mppt7CurrentIn=0;
    mppt7CurrentOut=0;
    mppt7VoltageOut=0;
    mppt7VoltageIn=0;

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
void CompactUI::setMppt1VoltageIn(double newVoltage)
{
   mppt1VoltageIn = newVoltage;
}
void CompactUI::setMppt1CurrentIn(double newCurrent)
{
   mppt1CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt1PowerOut()
{
   return *ui->mppt1PowerOut;
}
void CompactUI::setMppt1VoltageOut(double newVoltage)
{
   mppt1VoltageOut = newVoltage;
}
void CompactUI::setMppt1CurrentOut(double newCurrent)
{
   mppt1CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt2PowerIn()
{
   return *ui->mppt2PowerIn;
}
void CompactUI::setMppt2VoltageIn(double newVoltage)
{
   mppt2VoltageIn = newVoltage;
}
void CompactUI::setMppt2CurrentIn(double newCurrent)
{
   mppt2CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt2PowerOut()
{
   return *ui->mppt2PowerOut;
}
void CompactUI::setMppt2VoltageOut(double newVoltage)
{
   mppt2VoltageOut = newVoltage;
}
void CompactUI::setMppt2CurrentOut(double newCurrent)
{
   mppt2CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt3PowerIn()
{
   return *ui->mppt3PowerIn;
}
void CompactUI::setMppt3VoltageIn(double newVoltage)
{
   mppt3VoltageIn = newVoltage;
}
void CompactUI::setMppt3CurrentIn(double newCurrent)
{
   mppt3CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt3PowerOut()
{
   return *ui->mppt3PowerOut;
}
void CompactUI::setMppt3VoltageOut(double newVoltage)
{
   mppt3VoltageOut = newVoltage;
}
void CompactUI::setMppt3CurrentOut(double newCurrent)
{
   mppt3CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt4PowerIn()
{
   return *ui->mppt4PowerIn;
}
void CompactUI::setMppt4VoltageIn(double newVoltage)
{
   mppt4VoltageIn = newVoltage;
}
void CompactUI::setMppt4CurrentIn(double newCurrent)
{
   mppt4CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt4PowerOut()
{
   return *ui->mppt4PowerOut;
}
void CompactUI::setMppt4VoltageOut(double newVoltage)
{
   mppt4VoltageOut = newVoltage;
}
void CompactUI::setMppt4CurrentOut(double newCurrent)
{
   mppt4CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt5PowerIn()
{
   return *ui->mppt5PowerIn;
}
void CompactUI::setMppt5VoltageIn(double newVoltage)
{
   mppt5VoltageIn = newVoltage;
}
void CompactUI::setMppt5CurrentIn(double newCurrent)
{
   mppt5CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt5PowerOut()
{
   return *ui->mppt5PowerOut;
}
void CompactUI::setMppt5VoltageOut(double newVoltage)
{
   mppt5VoltageOut = newVoltage;
}
void CompactUI::setMppt5CurrentOut(double newCurrent)
{
   mppt5CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt6PowerIn()
{
   return *ui->mppt6PowerIn;
}
void CompactUI::setMppt6VoltageIn(double newVoltage)
{
   mppt6VoltageIn = newVoltage;
}
void CompactUI::setMppt6CurrentIn(double newCurrent)
{
   mppt6CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt6PowerOut()
{
   return *ui->mppt6PowerOut;
}
void CompactUI::setMppt6VoltageOut(double newVoltage)
{
   mppt6VoltageOut = newVoltage;
}
void CompactUI::setMppt6CurrentOut(double newCurrent)
{
   mppt6CurrentOut = newCurrent;
}

QLabel& CompactUI::setMppt7PowerIn()
{
   return *ui->mppt7PowerIn;
}
void CompactUI::setMppt7VoltageIn(double newVoltage)
{
   mppt7VoltageIn = newVoltage;
}
void CompactUI::setMppt7CurrentIn(double newCurrent)
{
   mppt7CurrentIn = newCurrent;
}
QLabel& CompactUI::setMppt7PowerOut()
{
   return *ui->mppt7PowerOut;
}
void CompactUI::setMppt7VoltageOut(double newVoltage)
{
   mppt7VoltageOut = newVoltage;
}
void CompactUI::setMppt7CurrentOut(double newCurrent)
{
   mppt7CurrentOut = newCurrent;
}
QLabel& CompactUI::setMppt1Efficiency()
{
   return *ui->mppt1Efficiency;
}
QLabel& CompactUI::setMppt2Efficiency()
{
   return *ui->mppt2Efficiency;
}
QLabel& CompactUI::setMppt3Efficiency()
{
   return *ui->mppt3Efficiency;
}
QLabel& CompactUI::setMppt4Efficiency()
{
   return *ui->mppt4Efficiency;
}
QLabel& CompactUI::setMppt5Efficiency()
{
   return *ui->mppt5Efficiency;
}
QLabel& CompactUI::setMppt6Efficiency()
{
   return *ui->mppt6Efficiency;
}
QLabel& CompactUI::setMppt7Efficiency()
{
   return *ui->mppt7Efficiency;
}
double CompactUI::getMppt1CurrentIn()
{
	return mppt1CurrentIn;
}
double CompactUI::getMppt1CurrentOut()
{
	return mppt1CurrentOut;
}
double CompactUI::getMppt2CurrentIn()
{
	return mppt2CurrentIn;
}
double CompactUI::getMppt2CurrentOut()
{
	return mppt2CurrentOut;
}
double CompactUI::getMppt3CurrentIn()
{
	return mppt3CurrentIn;
}
double CompactUI::getMppt3CurrentOut()
{
	return mppt3CurrentOut;
}
double CompactUI::getMppt4CurrentIn()
{
	return mppt4CurrentIn;
}
double CompactUI::getMppt4CurrentOut()
{
	return mppt4CurrentOut;
}
double CompactUI::getMppt5CurrentIn()
{
	return mppt5CurrentIn;
}
double CompactUI::getMppt5CurrentOut()
{
	return mppt5CurrentOut;
}
double CompactUI::getMppt6CurrentIn()
{
	return mppt6CurrentIn;
}
double CompactUI::getMppt6CurrentOut()
{
	return mppt6CurrentOut;
}
double CompactUI::getMppt7CurrentIn()
{
	return mppt7CurrentIn;
}
double CompactUI::getMppt7CurrentOut()
{
	return mppt7CurrentOut;
}
double CompactUI::getMppt1VoltageIn()
{
	return mppt1VoltageIn;
}
double CompactUI::getMppt1VoltageOut()
{
	return mppt1VoltageOut;
}
double CompactUI::getMppt2VoltageIn()
{
	return mppt2VoltageIn;
}
double CompactUI::getMppt2VoltageOut()
{
	return mppt2VoltageOut;
}
double CompactUI::getMppt3VoltageIn()
{
	return mppt3VoltageIn;
}
double CompactUI::getMppt3VoltageOut()
{
	return mppt3VoltageOut;
}
double CompactUI::getMppt4VoltageIn()
{
	return mppt4VoltageIn;
}
double CompactUI::getMppt4VoltageOut()
{
	return mppt4VoltageOut;
}
double CompactUI::getMppt5VoltageIn()
{
	return mppt5VoltageIn;
}
double CompactUI::getMppt5VoltageOut()
{
	return mppt5VoltageOut;
}
double CompactUI::getMppt6VoltageIn()
{
	return mppt6VoltageIn;
}
double CompactUI::getMppt6VoltageOut()
{
	return mppt6VoltageOut;
}
double CompactUI::getMppt7VoltageIn()
{
	return mppt7VoltageIn;
}
double CompactUI::getMppt7VoltageOut()
{
	return mppt7VoltageOut;
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
