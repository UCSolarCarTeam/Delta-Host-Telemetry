#include "CompactView.h"
#include "../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../PresenterLayer/CommunicationPresenter/CommunicationPresenter.h"
#include "../../PresenterLayer/PowerPresenter/PowerPresenter.h"
#include "../../PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "../../PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "../../PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "../CompactUI/CompactUI.h"
#include <QDateTime>

CompactView::CompactView(BatteryPresenter& batteryPresenter,
                      VehiclePresenter& vehiclePresenter,
                      PowerPresenter& powerPresenter,
                      CommunicationPresenter& communicationPresenter,
                      FaultsPresenter& faultsPresenter,
                      MpptPresenter& mpptPresenter,
                      CompactUI& ui)
  : batteryPresenter_(batteryPresenter)
  , vehiclePresenter_(vehiclePresenter)
  , powerPresenter_(powerPresenter)
  , communicationPresenter_(communicationPresenter)
  , faultsPresenter_(faultsPresenter)
  , mpptPresenter_(mpptPresenter)
  , ui_(ui)
{
   connect(&mpptPresenter_, SIGNAL(mppt1PowerInReceived(double)),
      this, SLOT(mppt1PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt1PowerOutReceived(double)),
      this, SLOT(mppt1PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt1EfficiencyReceived(double)),
      this, SLOT(mppt1EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt2PowerInReceived(double)),
      this, SLOT(mppt2PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt2PowerOutReceived(double)),
      this, SLOT(mppt2PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt2EfficiencyReceived(double)),
      this, SLOT(mppt2EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt3PowerInReceived(double)),
      this, SLOT(mppt3PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt3PowerOutReceived(double)),
      this, SLOT(mppt3PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt3EfficiencyReceived(double)),
      this, SLOT(mppt3EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt4PowerInReceived(double)),
      this, SLOT(mppt4PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt4PowerOutReceived(double)),
      this, SLOT(mppt4PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt4EfficiencyReceived(double)),
      this, SLOT(mppt4EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt5PowerInReceived(double)),
      this, SLOT(mppt5PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt5PowerOutReceived(double)),
      this, SLOT(mppt5PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt5EfficiencyReceived(double)),
      this, SLOT(mppt5EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt6PowerInReceived(double)),
      this, SLOT(mppt6PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt6PowerOutReceived(double)),
      this, SLOT(mppt6PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt6EfficiencyReceived(double)),
      this, SLOT(mppt6EfficiencyReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt7PowerInReceived(double)),
      this, SLOT(mppt7PowerInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt7PowerOutReceived(double)),
      this, SLOT(mppt7PowerOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt7EfficiencyReceived(double)),
      this, SLOT(mppt7EfficiencyReceived(double)));

    connect(&vehiclePresenter_, SIGNAL(driverSetSpeedMetersPerSecondReceived(double)),
            this, SLOT(driverSetSpeedMetersPerSecondReceived(double)));
    connect(&vehiclePresenter_, SIGNAL(driverSetCurrentReceived(double)),
            this, SLOT(driverSetCurrentReceived(double)));
    connect(&vehiclePresenter_, SIGNAL(vehicleVelocityMetersPerSecondReceived(double)),
            this, SLOT(vehicleVelocityMetersPerSecondReceived(double)));
    connect(&powerPresenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));
    connect(&powerPresenter_, SIGNAL(busCurrentAReceived(double)),
            this, SLOT(busCurrentAReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryCurrentReceived(double)),
            this, SLOT(batteryCurrentReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryVoltageReceived(double)),
            this, SLOT(batteryVoltageReceived(double)));

    connect(&batteryPresenter_, SIGNAL(mod0CellTemperatureReceived(double)),
            this, SLOT(mod0CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
            this, SLOT(mod0CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod1CellTemperatureReceived(double)),
            this, SLOT(mod1CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
            this, SLOT(mod1CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod2CellTemperatureReceived(double)),
            this, SLOT(mod2CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
            this, SLOT(mod2CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod3CellTemperatureReceived(double)),
            this, SLOT(mod3CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
            this, SLOT(mod3CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));

    connect(&communicationPresenter_, SIGNAL(connectionSucceeded()),
            this, SLOT(connectionSucceeded()));
    connect(&communicationPresenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));

}
CompactView::~CompactView()
{
}
bool CompactView::isValuesGarbage(QList<double> values)
{
    foreach(double value, values){
        if(value < -10000 || value > 10000){
            return true;
        }
    }
    return false;
}

void CompactView::mppt1PowerInReceived(double mppt1PowerIn)
{
   ui_.setMppt1PowerIn().setNum(mppt1PowerIn);
}
void CompactView::mppt1PowerOutReceived(double mppt1PowerOut)
{
   ui_.setMppt1PowerOut().setNum(mppt1PowerOut);;
}
void CompactView::mppt1EfficiencyReceived(double mppt1Efficiency)
{
   ui_.setMppt1Efficiency().setNum(mppt1Efficiency);;
}

void CompactView::mppt2PowerInReceived(double mppt2PowerIn)
{
   ui_.setMppt2PowerIn().setNum(mppt2PowerIn);
}
void CompactView::mppt2PowerOutReceived(double mppt2PowerOut)
{
   ui_.setMppt2PowerOut().setNum(mppt2PowerOut);;
}
void CompactView::mppt2EfficiencyReceived(double mppt2Efficiency)
{
   ui_.setMppt2Efficiency().setNum(mppt2Efficiency);;
}


void CompactView::mppt3PowerInReceived(double mppt3PowerIn)
{
   ui_.setMppt3PowerIn().setNum(mppt3PowerIn);
}
void CompactView::mppt3PowerOutReceived(double mppt3PowerOut)
{
   ui_.setMppt3PowerOut().setNum(mppt3PowerOut);;
}
void CompactView::mppt3EfficiencyReceived(double mppt3Efficiency)
{
   ui_.setMppt3Efficiency().setNum(mppt3Efficiency);;
}


void CompactView::mppt4PowerInReceived(double mppt4PowerIn)
{
   ui_.setMppt4PowerIn().setNum(mppt4PowerIn);
}
void CompactView::mppt4PowerOutReceived(double mppt4PowerOut)
{
   ui_.setMppt4PowerOut().setNum(mppt4PowerOut);;
}
void CompactView::mppt4EfficiencyReceived(double mppt4Efficiency)
{
   ui_.setMppt4Efficiency().setNum(mppt4Efficiency);;
}


void CompactView::mppt5PowerInReceived(double mppt5PowerIn)
{
   ui_.setMppt5PowerIn().setNum(mppt5PowerIn);
}
void CompactView::mppt5PowerOutReceived(double mppt5PowerOut)
{
   ui_.setMppt5PowerOut().setNum(mppt5PowerOut);;
}
void CompactView::mppt5EfficiencyReceived(double mppt5Efficiency)
{
   ui_.setMppt5Efficiency().setNum(mppt5Efficiency);;
}


void CompactView::mppt6PowerInReceived(double mppt6PowerIn)
{
   ui_.setMppt6PowerIn().setNum(mppt6PowerIn);
}
void CompactView::mppt6PowerOutReceived(double mppt6PowerOut)
{
   ui_.setMppt6PowerOut().setNum(mppt6PowerOut);;
}
void CompactView::mppt6EfficiencyReceived(double mppt6Efficiency)
{
   ui_.setMppt6Efficiency().setNum(mppt6Efficiency);;
}


void CompactView::mppt7PowerInReceived(double mppt7PowerIn)
{
   ui_.setMppt7PowerIn().setNum(mppt7PowerIn);
}
void CompactView::mppt7PowerOutReceived(double mppt7PowerOut)
{
   ui_.setMppt7PowerOut().setNum(mppt7PowerOut);;
}
void CompactView::mppt7EfficiencyReceived(double mppt7Efficiency)
{
   ui_.setMppt7Efficiency().setNum(mppt7Efficiency);;
}

void CompactView::motorOneFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){
    ui_.historyTextEdit().append("Motor One Desaturation Fault - " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.railUnderVoltageLockOut()){
     ui_.historyTextEdit().append("Motor One Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.configReadError()){
    ui_.historyTextEdit().append("Motor One Config Read Error- " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.watchdogCausedLastReset()){
    ui_.historyTextEdit().append("Motor One WatchDog Caused Last Reset- " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.badMotorPositionHallSequence()){
    ui_.historyTextEdit().append("Motor One Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.dcBusOverVoltage()){
    ui_.historyTextEdit().append("Motor One DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.softwareOverCurrent()){
    ui_.historyTextEdit().append("Motor One Software Over Current - " + QDateTime::currentDateTime().toString());
   }

   if(motorFaults.hardwareOverCurrent()){
    ui_.historyTextEdit().append("Motor One Hardware Over Current - " + QDateTime::currentDateTime().toString());
   }
}

void CompactView::motorOneLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
    ui_.historyTextEdit().append("Motor One Output Voltage PWM - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.motorCurrentLimit()){
    ui_.historyTextEdit().append("Motor One Motor Current Limit- " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.velocityLimit()){
    ui_.historyTextEdit().append("Motor One Velocity Limit- " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busCurrentLimit()){
    ui_.historyTextEdit().append("Motor One Bus Current Limit- " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busVoltageUpperLimit()){
    ui_.historyTextEdit().append("Motor One Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busVoltageLowerLimit()){
    ui_.historyTextEdit().append("Motor One Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
    ui_.historyTextEdit().append("Motor One IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
   }
}

void CompactView::motorTwoFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){
    ui_.historyTextEdit().append("Motor Two Desaturation Fault - " + QDateTime::currentDateTime().toString());

   }

    if(motorFaults.railUnderVoltageLockOut()){
      ui_.historyTextEdit().append("Motor Two Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.configReadError()){
      ui_.historyTextEdit().append("Motor Two Config Read Error- " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.watchdogCausedLastReset()){
      ui_.historyTextEdit().append("Motor Two Watchdog Caused Last Reset - " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.badMotorPositionHallSequence()){
      ui_.historyTextEdit().append("Motor Two Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.dcBusOverVoltage()){
      ui_.historyTextEdit().append("Motor Two DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.softwareOverCurrent()){
      ui_.historyTextEdit().append("Motor Two Software Over Current - " + QDateTime::currentDateTime().toString());
 
    }

    if(motorFaults.hardwareOverCurrent()){
      ui_.historyTextEdit().append("Motor Two Hardware Over Current - " + QDateTime::currentDateTime().toString());
 
    }
}

void CompactView::motorTwoLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
    ui_.historyTextEdit().append("Motor Two Output Voltage PWM - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.motorCurrentLimit()){
    ui_.historyTextEdit().append("Motor Two Motor Current Limit- " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.velocityLimit()){
    ui_.historyTextEdit().append("Motor Two velocityLimit - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busCurrentLimit()){
    ui_.historyTextEdit().append("Motor Two Bus Current Limit- " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busVoltageUpperLimit()){
    ui_.historyTextEdit().append("Motor Two Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.busVoltageLowerLimit()){
    ui_.historyTextEdit().append("Motor Two Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
    ui_.historyTextEdit().append("Motor Two IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
   }
}

void CompactView::batteryFaultsReceived(BatteryFaults batteryFaults)
{
   if(batteryFaults.cellOverVoltage()){
    ui_.historyTextEdit().append("Battery Cell Over Voltage - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.cellUnderVoltage()){
    ui_.historyTextEdit().append("Battery Cell Under Voltage - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.cellOverTemperature()){
    ui_.historyTextEdit().append("Battery Cell Over Temperature - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.measurementUntrusted()){
    ui_.historyTextEdit().append("Battery Measurement Untrusted - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.cmuCommTimeout()){
    ui_.historyTextEdit().append("Battery CMU Comm Timeout - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.vehicleCommTimeout()){
    ui_.historyTextEdit().append("Battery Vehicle Comm Timeout - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.bmuIsInSetupMode()){
    ui_.historyTextEdit().append("Battery BMU in Setup Mode - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.cmuCanBusPowerStatus()){
    ui_.historyTextEdit().append("Battery CMU Can Bus Power Status - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.packIsolationTestFailure()){
    ui_.historyTextEdit().append("Battery Pack Isolation Test Failure - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.softwareOverCurrentMeasured()){
    ui_.historyTextEdit().append("Battery Software Over Current Measured - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.canSupplyIsLow()){
    ui_.historyTextEdit().append("Battery Can Supply is Low - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.contactorIsStuck()){
    ui_.historyTextEdit().append("Battery Contactor is Stuck - " + QDateTime::currentDateTime().toString());
   }

   if(batteryFaults.cmuDetectedExtraCellPresent()){
    ui_.historyTextEdit().append("Battery CMU Detected Extra Cell - " + QDateTime::currentDateTime().toString());
   }

}

void CompactView::driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double driverSetSpeedKph = driverSetSpeedMetersPerSecond * 3.6;
    ui_.setSetSpeed().setNum(driverSetSpeedKph);
}
void CompactView::driverSetCurrentReceived(double driverSetCurrent)
{
    ui_.setSetCurrent().setNum(driverSetCurrent);
}
void CompactView::vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double vehicleVelocityKph = vehicleVelocityMetersPerSecond * 3.6;
    ui_.setActualSpeed().setNum(vehicleVelocityKph);
}
void CompactView::busCurrentAReceived(double busCurrentA)
{
   ui_.setBusCurrent().setNum(busCurrentA);
}
void CompactView::busVoltageReceived(double busVoltage)
{
    ui_.setBusVoltage().setNum(busVoltage);
}
void CompactView::batteryCurrentReceived(double batteryCurrent)
{
    ui_.setBatteryCurrent().setNum(batteryCurrent);
}
void CompactView::batteryVoltageReceived(double batteryVoltage)
{
    ui_.setBatteryVoltage().setNum(batteryVoltage);
}



void CompactView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{
    ui_.setBatteryCMU1Temp().setNum(mod0PcbTemperature);
}

void CompactView::mod0CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.setBatteryCMU1Cell1Voltage().setText("Err");
        ui_.setBatteryCMU1Cell2Voltage().setText("Err");
        ui_.setBatteryCMU1Cell3Voltage().setText("Err");
        ui_.setBatteryCMU1Cell4Voltage().setText("Err");
        ui_.setBatteryCMU1Cell5Voltage().setText("Err");
        ui_.setBatteryCMU1Cell6Voltage().setText("Err");
        ui_.setBatteryCMU1Cell7Voltage().setText("Err");
        ui_.setBatteryCMU1Cell8Voltage().setText("Err");
    } else {
        ui_.setBatteryCMU1Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.setBatteryCMU1Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.setBatteryCMU1Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.setBatteryCMU1Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.setBatteryCMU1Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.setBatteryCMU1Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.setBatteryCMU1Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.setBatteryCMU1Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void CompactView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
     ui_.setBatteryCMU2Temp().setNum(mod1PcbTemperature);
}

void CompactView::mod1CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.setBatteryCMU2Cell1Voltage().setText("Err");
        ui_.setBatteryCMU2Cell2Voltage().setText("Err");
        ui_.setBatteryCMU2Cell3Voltage().setText("Err");
        ui_.setBatteryCMU2Cell4Voltage().setText("Err");
        ui_.setBatteryCMU2Cell5Voltage().setText("Err");
        ui_.setBatteryCMU2Cell6Voltage().setText("Err");
        ui_.setBatteryCMU2Cell7Voltage().setText("Err");
        ui_.setBatteryCMU2Cell8Voltage().setText("Err");
    } else {
        ui_.setBatteryCMU2Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.setBatteryCMU2Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.setBatteryCMU2Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.setBatteryCMU2Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.setBatteryCMU2Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.setBatteryCMU2Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.setBatteryCMU2Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.setBatteryCMU2Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void CompactView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.setBatteryCMU3Temp().setNum(mod2PcbTemperature);
}

void CompactView::mod2CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.setBatteryCMU3Cell1Voltage().setText("Err");
        ui_.setBatteryCMU3Cell2Voltage().setText("Err");
        ui_.setBatteryCMU3Cell3Voltage().setText("Err");
        ui_.setBatteryCMU3Cell4Voltage().setText("Err");
        ui_.setBatteryCMU3Cell5Voltage().setText("Err");
        ui_.setBatteryCMU3Cell6Voltage().setText("Err");
        ui_.setBatteryCMU3Cell7Voltage().setText("Err");
        ui_.setBatteryCMU3Cell8Voltage().setText("Err");
    } else {
        ui_.setBatteryCMU3Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.setBatteryCMU3Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.setBatteryCMU3Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.setBatteryCMU3Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.setBatteryCMU3Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.setBatteryCMU3Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.setBatteryCMU3Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.setBatteryCMU3Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void CompactView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{
    ui_.setBatteryCMU4Temp().setNum(mod3PcbTemperature);
}

void CompactView::mod3CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.setBatteryCMU4Cell1Voltage().setText("Err");
        ui_.setBatteryCMU4Cell2Voltage().setText("Err");
        ui_.setBatteryCMU4Cell3Voltage().setText("Err");
        ui_.setBatteryCMU4Cell4Voltage().setText("Err");
        ui_.setBatteryCMU4Cell5Voltage().setText("Err");
        ui_.setBatteryCMU4Cell6Voltage().setText("Err");
        ui_.setBatteryCMU4Cell7Voltage().setText("Err");
        ui_.setBatteryCMU4Cell8Voltage().setText("Err");
    } else {
        ui_.setBatteryCMU4Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.setBatteryCMU4Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.setBatteryCMU4Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.setBatteryCMU4Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.setBatteryCMU4Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.setBatteryCMU4Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.setBatteryCMU4Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.setBatteryCMU4Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void CompactView::highlightMinMaxVoltages()
{
    QLabel* newMaxVoltageLabel = ui_.batteryCMUCellVoltageLabels()[0];
    double newMaxVoltage = newMaxVoltageLabel->text().toFloat();
    QLabel* newMinVoltageLabel = ui_.batteryCMUCellVoltageLabels()[0];
    double newMinVoltage = newMinVoltageLabel->text().toFloat();

    foreach(QLabel* cursorVoltageLabel, ui_.batteryCMUCellVoltageLabels())
    {
        double cursorVoltage = cursorVoltageLabel->text().toFloat();
        cursorVoltageLabel->setStyleSheet("");
        if(cursorVoltage > 0)
        {
            if(cursorVoltage > newMaxVoltage)
            {
                newMaxVoltageLabel = cursorVoltageLabel;
                newMaxVoltage = cursorVoltage;
            }
            if(cursorVoltage < newMinVoltage)
            {
                newMinVoltageLabel = cursorVoltageLabel;
                newMinVoltage = cursorVoltage;
            }
        }
    }
    newMaxVoltageLabel->setStyleSheet("font-weight: bold; background-color: rgb(100, 100, 100);");
    newMinVoltageLabel->setStyleSheet("font-weight: bold; background-color: rgb(100, 100, 100);");
    highlightUntrustedVoltages();
}

void CompactView::highlightUntrustedVoltages()
{
    foreach(QLabel* cursorVoltageLabel, ui_.batteryCMUCellVoltageLabels())
    {
        if(cursorVoltageLabel->text().toFloat() < 0)
        {
            QString stylesheet = cursorVoltageLabel->styleSheet();
            cursorVoltageLabel->setStyleSheet(stylesheet + "color: yellow");
            cursorVoltageLabel->setText(cursorVoltageLabel->text().right(1));
        }
    }
}

void CompactView::connectionFailed(QString failureMessage)
{
    ui_.setInputSerialConnectionStatus().setText(failureMessage);
    ui_.setInputSerialConnectionStatus().setStyleSheet("text-align: centre; color: rgb(255, 40, 40); background-color: rgb(70,70,70);"); // red text
}

void CompactView::connectionSucceeded()
{
    ui_.setInputSerialConnectionStatus().setText("Connected");
    ui_.setInputSerialConnectionStatus().setStyleSheet("text-align: centre; color: rgb(0, 255, 0); background-color: rgb(70,70,70);");
}
