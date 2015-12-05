#include "CompactView.h"
#include "PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "PresenterLayer/CommunicationPresenter/CommunicationPresenter.h"
#include "PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "PresenterLayer/MpptPresenter/MpptPresenter.h"
#include "PresenterLayer/PowerPresenter/PowerPresenter.h"
#include "PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "ViewLayer/CompactUI/I_CompactUI.h"
#include <QDateTime>

CompactView::CompactView(BatteryPresenter& batteryPresenter,
                         VehiclePresenter& vehiclePresenter,
                         PowerPresenter& powerPresenter,
                         CommunicationPresenter& communicationPresenter,
                         FaultsPresenter& faultsPresenter,
                         MpptPresenter& mpptPresenter,
                         I_CompactUI& ui)
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
   connect(&communicationPresenter_, SIGNAL(connectionFailed(const QString&)),
      this, SLOT(connectionFailed(const QString&)));

   connect(&faultsPresenter_, SIGNAL(motorOneFaultsReceived(MotorFaults)),
      this, SLOT(motorOneFaultsReceived(MotorFaults)));
   connect(&faultsPresenter_, SIGNAL(motorTwoFaultsReceived(MotorFaults)),
      this, SLOT(motorTwoFaultsReceived(MotorFaults)));
   connect(&faultsPresenter_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
      this, SLOT(batteryFaultsReceived(BatteryFaults)));

   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell1VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell2VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell3VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell4VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell5VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell6VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell7VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU1Cell8VoltageLabel());

   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell1VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell2VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell3VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell4VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell5VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell6VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell7VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU2Cell8VoltageLabel());

   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell1VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell2VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell3VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell4VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell5VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell6VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell7VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU3Cell8VoltageLabel());

   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell1VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell2VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell3VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell4VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell5VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell6VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell7VoltageLabel());
   batteryCMUCellVoltageLabels_.append(&ui_.batteryCMU4Cell8VoltageLabel());
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
bool CompactView::isLabelRed(QLabel& label)
{
   if(label.styleSheet().contains("red")){
      return true;
   } else {
      return false;
   }
}
void CompactView::setFaultFlagRed(QLabel& faultLabel)
{
    faultLabel.setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(176, 13, 13), stop: 1 red);font-size: 18px;margin:5px;");
}
void CompactView::setFaultFlagGreen(QLabel& faultLabel)
{
    faultLabel.setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 green);font-size: 18px;margin:5px;");
}
void CompactView::setConnectionLabelSuccessful(QLabel& connectionLabel)
{
    connectionLabel.setStyleSheet("text-align: centre;centre; color: rgb(0, 255, 0);background-color: rgb(70,70,70);margin: 15px;margin-top: 0px;margin-bottom: 15px;font-size: 14px;");
}
void CompactView::setConnectionLabelFailed(QLabel& connectionLabel)
{
    connectionLabel.setStyleSheet("text-align: centre;color: rgb(255, 40, 40);background-color: rgb(70,70,70);margin: 15px;margin-top: 0px;margin-bottom: 15px;font-size: 14px;");
}

void CompactView::mppt1PowerInReceived(double mppt1PowerIn)
{
   ui_.mppt1PowerInLabel().setNum(mppt1PowerIn);
}
void CompactView::mppt1PowerOutReceived(double mppt1PowerOut)
{
   ui_.mppt1PowerOutLabel().setNum(mppt1PowerOut);;
}
void CompactView::mppt1EfficiencyReceived(double mppt1Efficiency)
{
   ui_.mppt1EfficiencyLabel().setNum(mppt1Efficiency);;
}

void CompactView::mppt2PowerInReceived(double mppt2PowerIn)
{
   ui_.mppt2PowerInLabel().setNum(mppt2PowerIn);
}
void CompactView::mppt2PowerOutReceived(double mppt2PowerOut)
{
   ui_.mppt2PowerOutLabel().setNum(mppt2PowerOut);;
}
void CompactView::mppt2EfficiencyReceived(double mppt2Efficiency)
{
   ui_.mppt2EfficiencyLabel().setNum(mppt2Efficiency);;
}

void CompactView::mppt3PowerInReceived(double mppt3PowerIn)
{
   ui_.mppt3PowerInLabel().setNum(mppt3PowerIn);
}
void CompactView::mppt3PowerOutReceived(double mppt3PowerOut)
{
   ui_.mppt3PowerOutLabel().setNum(mppt3PowerOut);;
}
void CompactView::mppt3EfficiencyReceived(double mppt3Efficiency)
{
   ui_.mppt3EfficiencyLabel().setNum(mppt3Efficiency);;
}

void CompactView::mppt4PowerInReceived(double mppt4PowerIn)
{
   ui_.mppt4PowerInLabel().setNum(mppt4PowerIn);
}
void CompactView::mppt4PowerOutReceived(double mppt4PowerOut)
{
   ui_.mppt4PowerOutLabel().setNum(mppt4PowerOut);;
}
void CompactView::mppt4EfficiencyReceived(double mppt4Efficiency)
{
   ui_.mppt4EfficiencyLabel().setNum(mppt4Efficiency);;
}

void CompactView::mppt5PowerInReceived(double mppt5PowerIn)
{
   ui_.mppt5PowerInLabel().setNum(mppt5PowerIn);
}
void CompactView::mppt5PowerOutReceived(double mppt5PowerOut)
{
   ui_.mppt5PowerOutLabel().setNum(mppt5PowerOut);;
}
void CompactView::mppt5EfficiencyReceived(double mppt5Efficiency)
{
   ui_.mppt5EfficiencyLabel().setNum(mppt5Efficiency);;
}

void CompactView::mppt6PowerInReceived(double mppt6PowerIn)
{
   ui_.mppt6PowerInLabel().setNum(mppt6PowerIn);
}
void CompactView::mppt6PowerOutReceived(double mppt6PowerOut)
{
   ui_.mppt6PowerOutLabel().setNum(mppt6PowerOut);;
}
void CompactView::mppt6EfficiencyReceived(double mppt6Efficiency)
{
   ui_.mppt6EfficiencyLabel().setNum(mppt6Efficiency);;
}

void CompactView::mppt7PowerInReceived(double mppt7PowerIn)
{
   ui_.mppt7PowerInLabel().setNum(mppt7PowerIn);
}
void CompactView::mppt7PowerOutReceived(double mppt7PowerOut)
{
   ui_.mppt7PowerOutLabel().setNum(mppt7PowerOut);;
}
void CompactView::mppt7EfficiencyReceived(double mppt7Efficiency)
{
   ui_.mppt7EfficiencyLabel().setNum(mppt7Efficiency);;
}

void CompactView::driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond)
{
   //Convert meters per second to kilometers per hour
   double driverSetSpeedKph = driverSetSpeedMetersPerSecond * 3.6;
   ui_.setSpeedLabel().setNum(driverSetSpeedKph);
}
void CompactView::driverSetCurrentReceived(double driverSetCurrent)
{
   ui_.setCurrentLabel().setNum(driverSetCurrent);
}
void CompactView::vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond)
{
   //Convert meters per second to kilometers per hour
   double vehicleVelocityKph = vehicleVelocityMetersPerSecond * 3.6;
   ui_.actualSpeedLabel().setNum(vehicleVelocityKph);
}
void CompactView::busCurrentAReceived(double busCurrentA)
{
   ui_.busCurrentLabel().setNum(busCurrentA);
}
void CompactView::busVoltageReceived(double busVoltage)
{
   ui_.busVoltageLabel().setNum(busVoltage);
}
void CompactView::batteryCurrentReceived(double batteryCurrent)
{
   ui_.batteryCurrentLabel().setNum(batteryCurrent);
}
void CompactView::batteryVoltageReceived(double batteryVoltage)
{
   ui_.batteryVoltageLabel().setNum(batteryVoltage);
}

void CompactView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{
   ui_.batteryCMU1TempLabel().setNum(mod0PcbTemperature);
}

void CompactView::mod0CellVoltagesReceived(QList<double> cellVoltages)
{
   if (isValuesGarbage(cellVoltages)){
      ui_.batteryCMU1Cell1VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell2VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell3VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell4VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell5VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell6VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell7VoltageLabel().setText("Err");
      ui_.batteryCMU1Cell8VoltageLabel().setText("Err");
   } else {
      ui_.batteryCMU1Cell1VoltageLabel().setText(QString::number(cellVoltages[0], 'f', 3));
      ui_.batteryCMU1Cell2VoltageLabel().setText(QString::number(cellVoltages[1], 'f', 3));
      ui_.batteryCMU1Cell3VoltageLabel().setText(QString::number(cellVoltages[2], 'f', 3));
      ui_.batteryCMU1Cell4VoltageLabel().setText(QString::number(cellVoltages[3], 'f', 3));
      ui_.batteryCMU1Cell5VoltageLabel().setText(QString::number(cellVoltages[4], 'f', 3));
      ui_.batteryCMU1Cell6VoltageLabel().setText(QString::number(cellVoltages[5], 'f', 3));
      ui_.batteryCMU1Cell7VoltageLabel().setText(QString::number(cellVoltages[6], 'f', 3));
      ui_.batteryCMU1Cell8VoltageLabel().setText(QString::number(cellVoltages[7], 'f', 3));
   }
}

void CompactView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
   ui_.batteryCMU2TempLabel().setNum(mod1PcbTemperature);
}

void CompactView::mod1CellVoltagesReceived(QList<double> cellVoltages)
{
   if (isValuesGarbage(cellVoltages)){
      ui_.batteryCMU2Cell1VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell2VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell3VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell4VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell5VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell6VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell7VoltageLabel().setText("Err");
      ui_.batteryCMU2Cell8VoltageLabel().setText("Err");
   } else {
      ui_.batteryCMU2Cell1VoltageLabel().setText(QString::number(cellVoltages[0], 'f', 3));
      ui_.batteryCMU2Cell2VoltageLabel().setText(QString::number(cellVoltages[1], 'f', 3));
      ui_.batteryCMU2Cell3VoltageLabel().setText(QString::number(cellVoltages[2], 'f', 3));
      ui_.batteryCMU2Cell4VoltageLabel().setText(QString::number(cellVoltages[3], 'f', 3));
      ui_.batteryCMU2Cell5VoltageLabel().setText(QString::number(cellVoltages[4], 'f', 3));
      ui_.batteryCMU2Cell6VoltageLabel().setText(QString::number(cellVoltages[5], 'f', 3));
      ui_.batteryCMU2Cell7VoltageLabel().setText(QString::number(cellVoltages[6], 'f', 3));
      ui_.batteryCMU2Cell8VoltageLabel().setText(QString::number(cellVoltages[7], 'f', 3));
   }
}

void CompactView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
   ui_.batteryCMU3TempLabel().setNum(mod2PcbTemperature);
}

void CompactView::mod2CellVoltagesReceived(QList<double> cellVoltages)
{
   if (isValuesGarbage(cellVoltages)){
      ui_.batteryCMU3Cell1VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell2VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell3VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell4VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell5VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell6VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell7VoltageLabel().setText("Err");
      ui_.batteryCMU3Cell8VoltageLabel().setText("Err");
   } else {
      ui_.batteryCMU3Cell1VoltageLabel().setText(QString::number(cellVoltages[0], 'f', 3));
      ui_.batteryCMU3Cell2VoltageLabel().setText(QString::number(cellVoltages[1], 'f', 3));
      ui_.batteryCMU3Cell3VoltageLabel().setText(QString::number(cellVoltages[2], 'f', 3));
      ui_.batteryCMU3Cell4VoltageLabel().setText(QString::number(cellVoltages[3], 'f', 3));
      ui_.batteryCMU3Cell5VoltageLabel().setText(QString::number(cellVoltages[4], 'f', 3));
      ui_.batteryCMU3Cell6VoltageLabel().setText(QString::number(cellVoltages[5], 'f', 3));
      ui_.batteryCMU3Cell7VoltageLabel().setText(QString::number(cellVoltages[6], 'f', 3));
      ui_.batteryCMU3Cell8VoltageLabel().setText(QString::number(cellVoltages[7], 'f', 3));
   }
}

void CompactView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{
   ui_.batteryCMU4TempLabel().setNum(mod3PcbTemperature);
}

void CompactView::mod3CellVoltagesReceived(QList<double> cellVoltages)
{
   if (isValuesGarbage(cellVoltages)){
      ui_.batteryCMU4Cell1VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell2VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell3VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell4VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell5VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell6VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell7VoltageLabel().setText("Err");
      ui_.batteryCMU4Cell8VoltageLabel().setText("Err");
   } else {
      ui_.batteryCMU4Cell1VoltageLabel().setText(QString::number(cellVoltages[0], 'f', 3));
      ui_.batteryCMU4Cell2VoltageLabel().setText(QString::number(cellVoltages[1], 'f', 3));
      ui_.batteryCMU4Cell3VoltageLabel().setText(QString::number(cellVoltages[2], 'f', 3));
      ui_.batteryCMU4Cell4VoltageLabel().setText(QString::number(cellVoltages[3], 'f', 3));
      ui_.batteryCMU4Cell5VoltageLabel().setText(QString::number(cellVoltages[4], 'f', 3));
      ui_.batteryCMU4Cell6VoltageLabel().setText(QString::number(cellVoltages[5], 'f', 3));
      ui_.batteryCMU4Cell7VoltageLabel().setText(QString::number(cellVoltages[6], 'f', 3));
      ui_.batteryCMU4Cell8VoltageLabel().setText(QString::number(cellVoltages[7], 'f', 3));
   }
}

void CompactView::highlightMinMaxVoltages()
{
   QLabel* newMaxVoltageLabel = batteryCMUCellVoltageLabels_[0];
   double newMaxVoltage = newMaxVoltageLabel->text().toFloat();
   QLabel* newMinVoltageLabel = batteryCMUCellVoltageLabels_[0];
   double newMinVoltage = newMinVoltageLabel->text().toFloat();

   foreach(QLabel* cursorVoltageLabel, batteryCMUCellVoltageLabels_)
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
   foreach(QLabel* cursorVoltageLabel, batteryCMUCellVoltageLabels_)
   {
      if(cursorVoltageLabel->text().toFloat() < 0)
      {
         QString stylesheet = cursorVoltageLabel->styleSheet();
         cursorVoltageLabel->setStyleSheet(stylesheet + "color: yellow");
         cursorVoltageLabel->setText(cursorVoltageLabel->text().right(1));
      }
   }
}

void CompactView::connectionFailed(const QString& errorString)
{
    ui_.inputSerialConnectionStatusLabel().setText(errorString);
    setConnectionLabelFailed(ui_.inputSerialConnectionStatusLabel());
}
void CompactView::connectionSucceeded()
{
   ui_.inputSerialConnectionStatusLabel().setText("Connected");
   setConnectionLabelSuccessful(ui_.inputSerialConnectionStatusLabel());
}

void CompactView::motorOneFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.softwareOverCurrent() && !isLabelRed(ui_.softwareOverCurrentLabel1())){
      setFaultFlagRed(ui_.softwareOverCurrentLabel1());
   } else{
      setFaultFlagGreen(ui_.softwareOverCurrentLabel1());
   }

   if(motorFaults.hardwareOverCurrent() && !isLabelRed(ui_.hardwareOverCurrentLabel1())){
      setFaultFlagRed(ui_.hardwareOverCurrentLabel1());
   } else {
      setFaultFlagGreen(ui_.hardwareOverCurrentLabel1());
   }
}
void CompactView::motorTwoFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.softwareOverCurrent() && !isLabelRed(ui_.softwareOverCurrentLabel2())){
      setFaultFlagRed(ui_.softwareOverCurrentLabel2());
   } else {
      setFaultFlagGreen(ui_.softwareOverCurrentLabel2());
   }

   if(motorFaults.hardwareOverCurrent() && !isLabelRed(ui_.hardwareOverCurrentLabel2())){
      setFaultFlagRed(ui_.hardwareOverCurrentLabel2());
   } else {
      setFaultFlagGreen(ui_.hardwareOverCurrentLabel2());
   }
}
void CompactView::batteryFaultsReceived(BatteryFaults batteryFaults)
{
   if(batteryFaults.cellOverVoltage() && !isLabelRed(ui_.cellOverVoltageLabel())){
      setFaultFlagRed(ui_.cellOverVoltageLabel());
   } else {
      setFaultFlagGreen(ui_.cellOverVoltageLabel());
   }

   if(batteryFaults.cellUnderVoltage() && !isLabelRed(ui_.cellUnderVoltageLabel())){
      setFaultFlagRed(ui_.cellUnderVoltageLabel());
   } else {
      setFaultFlagGreen(ui_.cellUnderVoltageLabel());
   }

   if(batteryFaults.cellOverTemperature() && !isLabelRed(ui_.cellOverTemperatureLabel())){
      setFaultFlagRed(ui_.cellOverTemperatureLabel());
   } else {
      setFaultFlagGreen(ui_.cellOverTemperatureLabel());
   }
   if(batteryFaults.cmuCommTimeout() && !isLabelRed(ui_.cmuCommunicationsTimeoutLabel())){
      setFaultFlagRed(ui_.cmuCommunicationsTimeoutLabel());
   } else {
      setFaultFlagGreen(ui_.cmuCommunicationsTimeoutLabel());
   }
}
