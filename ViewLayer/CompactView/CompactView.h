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
    void updateMppt1PowerIn();
    void updateMppt1PowerOut();
    void updateMppt1Efficiency();

    void updateMppt2PowerIn();
    void updateMppt2PowerOut();
    void updateMppt2Efficiency();

    void updateMppt3PowerIn();
    void updateMppt3PowerOut();
    void updateMppt3Efficiency();

    void updateMppt4PowerIn();
    void updateMppt4PowerOut();
    void updateMppt4Efficiency();

    void updateMppt5PowerIn();
    void updateMppt5PowerOut();
    void updateMppt5Efficiency();

    void updateMppt6PowerIn();
    void updateMppt6PowerOut();
    void updateMppt6Efficiency();

    void updateMppt7PowerIn();
    void updateMppt7PowerOut();
    void updateMppt7Efficiency();

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
    void motorOneLimitFlagsReceived(LimitFlags limitFlags);
    void motorTwoFaultsReceived(MotorFaults motorFaults);
    void motorTwoLimitFlagsReceived(LimitFlags limitFlags);
    void batteryFaultsReceived(BatteryFaults batteryFaults);

    void mppt1VoltageInReceived(double);
    void mppt1CurrentInReceived(double);
    void mppt1VoltageOutReceived(double);
    void mppt1CurrentOutReceived(double);

    void mppt2VoltageInReceived(double);
    void mppt2CurrentInReceived(double);
    void mppt2VoltageOutReceived(double);
    void mppt2CurrentOutReceived(double);

    void mppt3VoltageInReceived(double);
    void mppt3CurrentInReceived(double);
    void mppt3VoltageOutReceived(double);
    void mppt3CurrentOutReceived(double);

    void mppt4VoltageInReceived(double);
    void mppt4CurrentInReceived(double);
    void mppt4VoltageOutReceived(double);
    void mppt4CurrentOutReceived(double);

    void mppt5VoltageInReceived(double);
    void mppt5CurrentInReceived(double);
    void mppt5VoltageOutReceived(double);
    void mppt5CurrentOutReceived(double);

    void mppt6VoltageInReceived(double);
    void mppt6CurrentInReceived(double);
    void mppt6VoltageOutReceived(double);
    void mppt6CurrentOutReceived(double);

    void mppt7VoltageInReceived(double);
    void mppt7CurrentInReceived(double);
    void mppt7VoltageOutReceived(double);
    void mppt7CurrentOutReceived(double);

    void connectionFailed(QString);
    void connectionSucceeded();
};
