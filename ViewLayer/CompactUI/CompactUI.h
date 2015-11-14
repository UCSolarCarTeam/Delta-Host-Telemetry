#pragma once

#include "I_CompactUI.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

namespace Ui {
    class CompactUI;
}
class CompactUI : public I_SolarCarWindow, public I_CompactUI
{
    Q_OBJECT

public:
    explicit CompactUI();
    ~CompactUI();

    QLabel& mppt1EfficiencyLabel();
    QLabel& mppt2EfficiencyLabel();
    QLabel& mppt3EfficiencyLabel();
    QLabel& mppt4EfficiencyLabel();
    QLabel& mppt5EfficiencyLabel();
    QLabel& mppt6EfficiencyLabel();
    QLabel& mppt7EfficiencyLabel();

    QLabel& mppt1PowerInLabel();
    QLabel& mppt2PowerInLabel();
    QLabel& mppt3PowerInLabel();
    QLabel& mppt4PowerInLabel();
    QLabel& mppt5PowerInLabel();
    QLabel& mppt6PowerInLabel();
    QLabel& mppt7PowerInLabel();

    QLabel& mppt1PowerOutLabel();
    QLabel& mppt2PowerOutLabel();
    QLabel& mppt3PowerOutLabel();
    QLabel& mppt4PowerOutLabel();
    QLabel& mppt5PowerOutLabel();
    QLabel& mppt6PowerOutLabel();
    QLabel& mppt7PowerOutLabel();

    QLabel& setSpeedLabel();
    QLabel& setCurrentLabel();
    QLabel& actualSpeedLabel();
    QLabel& busCurrentLabel();
    QLabel& busVoltageLabel();
    QLabel& batteryCurrentLabel();
    QLabel& batteryVoltageLabel();

    QLabel& batteryCMU1TempLabel();
    QLabel& batteryCMU1Cell1VoltageLabel();
    QLabel& batteryCMU1Cell2VoltageLabel();
    QLabel& batteryCMU1Cell3VoltageLabel();
    QLabel& batteryCMU1Cell4VoltageLabel();
    QLabel& batteryCMU1Cell5VoltageLabel();
    QLabel& batteryCMU1Cell6VoltageLabel();
    QLabel& batteryCMU1Cell7VoltageLabel();
    QLabel& batteryCMU1Cell8VoltageLabel();

    QLabel& batteryCMU2TempLabel();
    QLabel& batteryCMU2Cell1VoltageLabel();
    QLabel& batteryCMU2Cell2VoltageLabel();
    QLabel& batteryCMU2Cell3VoltageLabel();
    QLabel& batteryCMU2Cell4VoltageLabel();
    QLabel& batteryCMU2Cell5VoltageLabel();
    QLabel& batteryCMU2Cell6VoltageLabel();
    QLabel& batteryCMU2Cell7VoltageLabel();
    QLabel& batteryCMU2Cell8VoltageLabel();

    QLabel& batteryCMU3TempLabel();
    QLabel& batteryCMU3Cell1VoltageLabel();
    QLabel& batteryCMU3Cell2VoltageLabel();
    QLabel& batteryCMU3Cell3VoltageLabel();
    QLabel& batteryCMU3Cell4VoltageLabel();
    QLabel& batteryCMU3Cell5VoltageLabel();
    QLabel& batteryCMU3Cell6VoltageLabel();
    QLabel& batteryCMU3Cell7VoltageLabel();
    QLabel& batteryCMU3Cell8VoltageLabel();

    QLabel& batteryCMU4TempLabel();
    QLabel& batteryCMU4Cell1VoltageLabel();
    QLabel& batteryCMU4Cell2VoltageLabel();
    QLabel& batteryCMU4Cell3VoltageLabel();
    QLabel& batteryCMU4Cell4VoltageLabel();
    QLabel& batteryCMU4Cell5VoltageLabel();
    QLabel& batteryCMU4Cell6VoltageLabel();
    QLabel& batteryCMU4Cell7VoltageLabel();
    QLabel& batteryCMU4Cell8VoltageLabel();

    QLabel& softwareOverCurrentLabel1();
    QLabel& hardwareOverCurrentLabel1();

    QLabel& softwareOverCurrentLabel2();
    QLabel& hardwareOverCurrentLabel2();

    QLabel& cellOverVoltageLabel();
    QLabel& cellUnderVoltageLabel();
    QLabel& cellOverTemperatureLabel();
    QLabel& cmuCommunicationsTimeoutLabel();

    QLabel& inputSerialConnectionStatusLabel();
    QLabel& output3GConnectionStatusLabel();

private:
    Ui::CompactUI *ui;
};
