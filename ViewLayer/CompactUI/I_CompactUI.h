#pragma once

#include <QLabel>
#include <QTextEdit>

class I_CompactUI
{
public:
    virtual ~I_CompactUI() {}

    virtual QLabel& mppt1EfficiencyLabel() = 0;
    virtual QLabel& mppt2EfficiencyLabel() = 0;
    virtual QLabel& mppt3EfficiencyLabel() = 0;
    virtual QLabel& mppt4EfficiencyLabel() = 0;
    virtual QLabel& mppt5EfficiencyLabel() = 0;
    virtual QLabel& mppt6EfficiencyLabel() = 0;
    virtual QLabel& mppt7EfficiencyLabel() = 0;

    virtual QLabel& mppt1PowerInLabel() = 0;
    virtual QLabel& mppt2PowerInLabel() = 0;
    virtual QLabel& mppt3PowerInLabel() = 0;
    virtual QLabel& mppt4PowerInLabel() = 0;
    virtual QLabel& mppt5PowerInLabel() = 0;
    virtual QLabel& mppt6PowerInLabel() = 0;
    virtual QLabel& mppt7PowerInLabel() = 0;

    virtual QLabel& mppt1PowerOutLabel() = 0;
    virtual QLabel& mppt2PowerOutLabel() = 0;
    virtual QLabel& mppt3PowerOutLabel() = 0;
    virtual QLabel& mppt4PowerOutLabel() = 0;
    virtual QLabel& mppt5PowerOutLabel() = 0;
    virtual QLabel& mppt6PowerOutLabel() = 0;
    virtual QLabel& mppt7PowerOutLabel() = 0;

    virtual QLabel& setSpeedLabel() = 0;
    virtual QLabel& setCurrentLabel() = 0;
    virtual QLabel& actualSpeedLabel() = 0;
    virtual QLabel& busCurrentLabel() = 0;
    virtual QLabel& busVoltageLabel() = 0;
    virtual QLabel& batteryCurrentLabel() = 0;
    virtual QLabel& batteryVoltageLabel() = 0;

    virtual QLabel& batteryCMU1TempLabel() = 0;
    virtual QLabel& batteryCMU1Cell1VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell2VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell3VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell4VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell5VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell6VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell7VoltageLabel() = 0;
    virtual QLabel& batteryCMU1Cell8VoltageLabel() = 0;

    virtual QLabel& batteryCMU2TempLabel() = 0;
    virtual QLabel& batteryCMU2Cell1VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell2VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell3VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell4VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell5VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell6VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell7VoltageLabel() = 0;
    virtual QLabel& batteryCMU2Cell8VoltageLabel() = 0;

    virtual QLabel& batteryCMU3TempLabel() = 0;
    virtual QLabel& batteryCMU3Cell1VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell2VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell3VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell4VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell5VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell6VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell7VoltageLabel() = 0;
    virtual QLabel& batteryCMU3Cell8VoltageLabel() = 0;

    virtual QLabel& batteryCMU4TempLabel() = 0;
    virtual QLabel& batteryCMU4Cell1VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell2VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell3VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell4VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell5VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell6VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell7VoltageLabel() = 0;
    virtual QLabel& batteryCMU4Cell8VoltageLabel() = 0;

    virtual QLabel& softwareOverCurrentLabel1() = 0;
    virtual QLabel& hardwareOverCurrentLabel1() = 0;

    virtual QLabel& softwareOverCurrentLabel2() = 0;
    virtual QLabel& hardwareOverCurrentLabel2() = 0;

    virtual QLabel& cellOverVoltageLabel() = 0;
    virtual QLabel& cellUnderVoltageLabel() = 0;
    virtual QLabel& cellOverTemperatureLabel() = 0;
    virtual QLabel& cmuCommunicationsTimeoutLabel() = 0;

    virtual QLabel& inputSerialConnectionStatusLabel() = 0;
    virtual QLabel& output3GConnectionStatusLabel() = 0;
};
