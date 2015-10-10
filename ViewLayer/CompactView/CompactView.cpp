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
   connect(&mpptPresenter_, SIGNAL(mppt1VoltageInReceived(double)),
      this, SLOT(mppt1VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt1CurrentInReceived(double)),
      this, SLOT(mppt1CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt1VoltageOutReceived(double)),
      this, SLOT(mppt1VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt1CurrentOutReceived(double)),
      this, SLOT(mppt1CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt2VoltageInReceived(double)),
      this, SLOT(mppt2VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt2CurrentInReceived(double)),
      this, SLOT(mppt2CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt2VoltageOutReceived(double)),
      this, SLOT(mppt2VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt2CurrentOutReceived(double)),
      this, SLOT(mppt2CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt3VoltageInReceived(double)),
      this, SLOT(mppt3VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt3CurrentInReceived(double)),
      this, SLOT(mppt3CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt3VoltageOutReceived(double)),
      this, SLOT(mppt3VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt3CurrentOutReceived(double)),
      this, SLOT(mppt3CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt4VoltageInReceived(double)),
      this, SLOT(mppt4VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt4CurrentInReceived(double)),
      this, SLOT(mppt4CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt4VoltageOutReceived(double)),
      this, SLOT(mppt4VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt4CurrentOutReceived(double)),
      this, SLOT(mppt4CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt5VoltageInReceived(double)),
      this, SLOT(mppt5VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt5CurrentInReceived(double)),
      this, SLOT(mppt5CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt5VoltageOutReceived(double)),
      this, SLOT(mppt5VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt5CurrentOutReceived(double)),
      this, SLOT(mppt5CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt6VoltageInReceived(double)),
      this, SLOT(mppt6VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt6CurrentInReceived(double)),
      this, SLOT(mppt6CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt6VoltageOutReceived(double)),
      this, SLOT(mppt6VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt6CurrentOutReceived(double)),
      this, SLOT(mppt6CurrentOutReceived(double)));

   connect(&mpptPresenter_, SIGNAL(mppt7VoltageInReceived(double)),
      this, SLOT(mppt7VoltageInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt7CurrentInReceived(double)),
      this, SLOT(mppt7CurrentInReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt7VoltageOutReceived(double)),
      this, SLOT(mppt7VoltageOutReceived(double)));
   connect(&mpptPresenter_, SIGNAL(mppt7CurrentOutReceived(double)),
      this, SLOT(mppt7CurrentOutReceived(double)));

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

void CompactView::updateMppt1PowerIn()
{
   double powerIn = ui_.getMppt1CurrentIn() * ui_.getMppt1VoltageIn();
   ui_.setMppt1PowerIn().setNum(powerIn);
}
void CompactView::updateMppt1PowerOut()
{
   double powerOut = ui_.getMppt1CurrentOut() * ui_.getMppt1VoltageOut();
   ui_.setMppt1PowerIn().setNum(powerOut);
}
void CompactView::updateMppt1Efficiency()
{
   double powerIn = ui_.setMppt1PowerIn().text().toDouble();
   double powerOut = ui_.setMppt1PowerOut().text().toDouble();
   ui_.setMppt1Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt2PowerIn()
{
   double powerIn = ui_.getMppt2CurrentIn() * ui_.getMppt2VoltageIn();
   ui_.setMppt2PowerIn().setNum(powerIn);
}
void CompactView::updateMppt2PowerOut()
{
   double powerOut = ui_.getMppt2CurrentOut() * ui_.getMppt2VoltageOut();
   ui_.setMppt2PowerIn().setNum(powerOut);
}
void CompactView::updateMppt2Efficiency()
{
   double powerIn = ui_.setMppt2PowerIn().text().toDouble();
   double powerOut = ui_.setMppt2PowerOut().text().toDouble();
   ui_.setMppt2Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt3PowerIn()
{
   double powerIn = ui_.getMppt3CurrentIn() * ui_.getMppt3VoltageIn();
   ui_.setMppt3PowerIn().setNum(powerIn);
}
void CompactView::updateMppt3PowerOut()
{
   double powerOut = ui_.getMppt3CurrentOut() * ui_.getMppt3VoltageOut();
   ui_.setMppt3PowerIn().setNum(powerOut);
}
void CompactView::updateMppt3Efficiency()
{
   double powerIn = ui_.setMppt3PowerIn().text().toDouble();
   double powerOut = ui_.setMppt3PowerOut().text().toDouble();
   ui_.setMppt3Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt4PowerIn()
{
   double powerIn = ui_.getMppt4CurrentIn() * ui_.getMppt4VoltageIn();
   ui_.setMppt4PowerIn().setNum(powerIn);
}
void CompactView::updateMppt4PowerOut()
{
   double powerOut = ui_.getMppt4CurrentOut() * ui_.getMppt4VoltageOut();
   ui_.setMppt4PowerIn().setNum(powerOut);
}
void CompactView::updateMppt4Efficiency()
{
   double powerIn = ui_.setMppt4PowerIn().text().toDouble();
   double powerOut = ui_.setMppt4PowerOut().text().toDouble();
   ui_.setMppt4Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt5PowerIn()
{
   double powerIn = ui_.getMppt5CurrentIn() * ui_.getMppt5VoltageIn();
   ui_.setMppt5PowerIn().setNum(powerIn);
}
void CompactView::updateMppt5PowerOut()
{
   double powerOut = ui_.getMppt5CurrentOut() * ui_.getMppt5VoltageOut();
   ui_.setMppt5PowerIn().setNum(powerOut);
}
void CompactView::updateMppt5Efficiency()
{
   double powerIn = ui_.setMppt5PowerIn().text().toDouble();
   double powerOut = ui_.setMppt5PowerOut().text().toDouble();
   ui_.setMppt5Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt6PowerIn()
{
   double powerIn = ui_.getMppt6CurrentIn() * ui_.getMppt6VoltageIn();
   ui_.setMppt6PowerIn().setNum(powerIn);
}
void CompactView::updateMppt6PowerOut()
{
   double powerOut = ui_.getMppt6CurrentOut() * ui_.getMppt6VoltageOut();
   ui_.setMppt6PowerIn().setNum(powerOut);
}
void CompactView::updateMppt6Efficiency()
{
   double powerIn = ui_.setMppt6PowerIn().text().toDouble();
   double powerOut = ui_.setMppt6PowerOut().text().toDouble();
   ui_.setMppt6Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::updateMppt7PowerIn()
{
   double powerIn = ui_.getMppt7CurrentIn() * ui_.getMppt7VoltageIn();
   ui_.setMppt7PowerIn().setNum(powerIn);
}
void CompactView::updateMppt7PowerOut()
{
   double powerOut = ui_.getMppt7CurrentOut() * ui_.getMppt7VoltageOut();
   ui_.setMppt7PowerIn().setNum(powerOut);
}
void CompactView::updateMppt7Efficiency()
{
   double powerIn = ui_.setMppt7PowerIn().text().toDouble();
   double powerOut = ui_.setMppt7PowerOut().text().toDouble();
   ui_.setMppt7Efficiency().setNum(powerOut / powerIn * 100);
}

void CompactView::mppt1VoltageInReceived(double mppt1VoltageIn)
{
   ui_.setMppt1VoltageIn(mppt1VoltageIn);
   updateMppt1PowerIn();
   updateMppt1Efficiency();
}
void CompactView::mppt1CurrentInReceived(double mppt1CurrentIn)
{
   ui_.setMppt1CurrentIn(mppt1CurrentIn);
   updateMppt1PowerIn();
   updateMppt1Efficiency();
}
void CompactView::mppt1VoltageOutReceived(double mppt1VoltageOut)
{
   ui_.setMppt1VoltageOut(mppt1VoltageOut);
   updateMppt1PowerOut();
   updateMppt1Efficiency();
}
void CompactView::mppt1CurrentOutReceived(double mppt1CurrentOut)
{
   ui_.setMppt1CurrentOut(mppt1CurrentOut);
   updateMppt1PowerOut();
   updateMppt1Efficiency();
}

void CompactView::mppt2VoltageInReceived(double mppt2VoltageIn)
{
   ui_.setMppt2VoltageIn(mppt2VoltageIn);
   updateMppt2PowerIn();
   updateMppt2Efficiency();
}
void CompactView::mppt2CurrentInReceived(double mppt2CurrentIn)
{
   ui_.setMppt2CurrentIn(mppt2CurrentIn);
   updateMppt2PowerIn();
   updateMppt2Efficiency();
}
void CompactView::mppt2VoltageOutReceived(double mppt2VoltageOut)
{
   ui_.setMppt2VoltageOut(mppt2VoltageOut);
   updateMppt2PowerOut();
   updateMppt2Efficiency();
}
void CompactView::mppt2CurrentOutReceived(double mppt2CurrentOut)
{
   ui_.setMppt2CurrentOut(mppt2CurrentOut);
   updateMppt2PowerOut();
   updateMppt2Efficiency();
}

void CompactView::mppt3VoltageInReceived(double mppt3VoltageIn)
{
   ui_.setMppt3VoltageIn(mppt3VoltageIn);
   updateMppt3PowerIn();
   updateMppt3Efficiency();
}
void CompactView::mppt3CurrentInReceived(double mppt3CurrentIn)
{
   ui_.setMppt3CurrentIn(mppt3CurrentIn);
   updateMppt3PowerIn();
   updateMppt3Efficiency();
}
void CompactView::mppt3VoltageOutReceived(double mppt3VoltageOut)
{
   ui_.setMppt3VoltageOut(mppt3VoltageOut);
   updateMppt3PowerOut();
   updateMppt3Efficiency();
}
void CompactView::mppt3CurrentOutReceived(double mppt3CurrentOut)
{
   ui_.setMppt3CurrentOut(mppt3CurrentOut);
   updateMppt3PowerOut();
   updateMppt3Efficiency();
}

void CompactView::mppt4VoltageInReceived(double mppt4VoltageIn)
{
   ui_.setMppt4VoltageIn(mppt4VoltageIn);
   updateMppt4PowerIn();
   updateMppt4Efficiency();
}
void CompactView::mppt4CurrentInReceived(double mppt4CurrentIn)
{
   ui_.setMppt4CurrentIn(mppt4CurrentIn);
   updateMppt4PowerIn();
   updateMppt4Efficiency();
}
void CompactView::mppt4VoltageOutReceived(double mppt4VoltageOut)
{
   ui_.setMppt4VoltageOut(mppt4VoltageOut);
   updateMppt4PowerOut();
   updateMppt4Efficiency();
}
void CompactView::mppt4CurrentOutReceived(double mppt4CurrentOut)
{
   ui_.setMppt4CurrentOut(mppt4CurrentOut);
   updateMppt4PowerOut();
   updateMppt4Efficiency();
}

void CompactView::mppt5VoltageInReceived(double mppt5VoltageIn)
{
   ui_.setMppt5VoltageIn(mppt5VoltageIn);
   updateMppt5PowerIn();
   updateMppt5Efficiency();
}
void CompactView::mppt5CurrentInReceived(double mppt5CurrentIn)
{
   ui_.setMppt5CurrentIn(mppt5CurrentIn);
   updateMppt5PowerIn();
   updateMppt5Efficiency();
}
void CompactView::mppt5VoltageOutReceived(double mppt5VoltageOut)
{
   ui_.setMppt5VoltageOut(mppt5VoltageOut);
   updateMppt5PowerOut();
   updateMppt5Efficiency();
}
void CompactView::mppt5CurrentOutReceived(double mppt5CurrentOut)
{
   ui_.setMppt5CurrentOut(mppt5CurrentOut);
   updateMppt5PowerOut();
   updateMppt5Efficiency();
}

void CompactView::mppt6VoltageInReceived(double mppt6VoltageIn)
{
   ui_.setMppt6VoltageIn(mppt6VoltageIn);
   updateMppt6PowerIn();
   updateMppt6Efficiency();
}
void CompactView::mppt6CurrentInReceived(double mppt6CurrentIn)
{
   ui_.setMppt6CurrentIn(mppt6CurrentIn);
   updateMppt6PowerIn();
   updateMppt6Efficiency();
}
void CompactView::mppt6VoltageOutReceived(double mppt6VoltageOut)
{
   ui_.setMppt6VoltageOut(mppt6VoltageOut);
   updateMppt6PowerOut();
   updateMppt6Efficiency();
}
void CompactView::mppt6CurrentOutReceived(double mppt6CurrentOut)
{
   ui_.setMppt6CurrentOut(mppt6CurrentOut);
   updateMppt6PowerOut();
   updateMppt6Efficiency();
}

void CompactView::mppt7VoltageInReceived(double mppt7VoltageIn)
{
   ui_.setMppt7VoltageIn(mppt7VoltageIn);
   updateMppt7PowerIn();
   updateMppt7Efficiency();
}
void CompactView::mppt7CurrentInReceived(double mppt7CurrentIn)
{
   ui_.setMppt7CurrentIn(mppt7CurrentIn);
   updateMppt7PowerIn();
   updateMppt7Efficiency();
}
void CompactView::mppt7VoltageOutReceived(double mppt7VoltageOut)
{
   ui_.setMppt7VoltageOut(mppt7VoltageOut);
   updateMppt7PowerOut();
   updateMppt7Efficiency();
}
void CompactView::mppt7CurrentOutReceived(double mppt7CurrentOut)
{
   ui_.setMppt7CurrentOut(mppt7CurrentOut);
   updateMppt7PowerOut();
   updateMppt7Efficiency();
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


