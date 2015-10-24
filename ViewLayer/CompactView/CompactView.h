#pragma once

#include <QObject>
#include <QLabel>
#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"
#include "../CompactUI/CompactUI.h"

class BatteryPresenter;
class VehiclePresenter;
class PowerPresenter;
class CommunicationPresenter;
class FaultsPresenter;
class MpptPresenter;
class CompactUI;

class CompactView : public QObject
{
    Q_OBJECT
public:
    CompactView(BatteryPresenter& batteryPresenter,
              VehiclePresenter& vehiclePresenter,
              PowerPresenter& powerPresenter,
              CommunicationPresenter& communicationPresenter,
              FaultsPresenter& faultsPresenter,
              MpptPresenter& mpptPresenter,
              CompactUI& ui);
    ~CompactView();

private:
    bool isLabelRed(QLabel&);
    bool isValuesGarbage(QList<double> values);

    BatteryPresenter& batteryPresenter_;
    VehiclePresenter& vehiclePresenter_;
    PowerPresenter& powerPresenter_;
    CommunicationPresenter& communicationPresenter_;
    FaultsPresenter& faultsPresenter_;
    MpptPresenter& mpptPresenter_;

    CompactUI& ui_;

private slots:
    void driverSetSpeedMetersPerSecondReceived(double);
    void driverSetCurrentReceived(double);
    void vehicleVelocityMetersPerSecondReceived(double);
    void busCurrentAReceived(double);
    void busVoltageReceived(double);
    void batteryCurrentReceived(double);
    void batteryVoltageReceived(double);

    void mod0CellTemperatureReceived(double);
    void mod0CellVoltagesReceived(QList<double>);
    void mod1CellTemperatureReceived(double);
    void mod1CellVoltagesReceived(QList<double>);
    void mod2CellTemperatureReceived(double);
    void mod2CellVoltagesReceived(QList<double>);
    void mod3CellTemperatureReceived(double);
    void mod3CellVoltagesReceived(QList<double>);
    void highlightMinMaxVoltages();
    void highlightUntrustedVoltages();

    void motorOneFaultsReceived(MotorFaults motorFaults);
    void motorTwoFaultsReceived(MotorFaults motorFaults);
    void batteryFaultsReceived(BatteryFaults batteryFaults);

    void mppt1PowerInReceived(double);
    void mppt1PowerOutReceived(double);
    void mppt1EfficiencyReceived(double);

    void mppt2PowerInReceived(double);
    void mppt2PowerOutReceived(double);
    void mppt2EfficiencyReceived(double);

    void mppt3PowerInReceived(double);
    void mppt3PowerOutReceived(double);
    void mppt3EfficiencyReceived(double);

    void mppt4PowerInReceived(double);
    void mppt4PowerOutReceived(double);
    void mppt4EfficiencyReceived(double);

    void mppt5PowerInReceived(double);
    void mppt5PowerOutReceived(double);
    void mppt5EfficiencyReceived(double);

    void mppt6PowerInReceived(double);
    void mppt6PowerOutReceived(double);
    void mppt6EfficiencyReceived(double);

    void mppt7PowerInReceived(double);
    void mppt7PowerOutReceived(double);
    void mppt7EfficiencyReceived(double);

    void connectionFailed(QString);
    void connectionSucceeded();
};
