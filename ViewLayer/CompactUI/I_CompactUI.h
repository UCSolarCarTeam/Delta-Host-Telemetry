#pragma once

#include <QLabel>
#include <QTextEdit>

class I_CompactUI
{
public:
    virtual ~I_CompactUI() {}

    virtual QLabel& setMppt1Efficiency() = 0;
    virtual QLabel& setMppt2Efficiency() = 0;
    virtual QLabel& setMppt3Efficiency() = 0;
    virtual QLabel& setMppt4Efficiency() = 0;
    virtual QLabel& setMppt5Efficiency() = 0;
    virtual QLabel& setMppt6Efficiency() = 0;
    virtual QLabel& setMppt7Efficiency() = 0;

    virtual QLabel& setMppt1PowerIn() = 0;
    virtual QLabel& setMppt2PowerIn() = 0;
    virtual QLabel& setMppt3PowerIn() = 0;
    virtual QLabel& setMppt4PowerIn() = 0;
    virtual QLabel& setMppt5PowerIn() = 0;
    virtual QLabel& setMppt6PowerIn() = 0;
    virtual QLabel& setMppt7PowerIn() = 0;

    virtual QLabel& setMppt1PowerOut() = 0;
    virtual QLabel& setMppt2PowerOut() = 0;
    virtual QLabel& setMppt3PowerOut() = 0;
    virtual QLabel& setMppt4PowerOut() = 0;
    virtual QLabel& setMppt5PowerOut() = 0;
    virtual QLabel& setMppt6PowerOut() = 0;
    virtual QLabel& setMppt7PowerOut() = 0;

    virtual QLabel& setSetSpeed() = 0;
    virtual QLabel& setSetCurrent() = 0;
    virtual QLabel& setActualSpeed() = 0;
    virtual QLabel& setBusCurrent() = 0;
    virtual QLabel& setBusVoltage() = 0;
    virtual QLabel& setBatteryCurrent() = 0;
    virtual QLabel& setBatteryVoltage() = 0;

    virtual QLabel& setBatteryCMU1Temp() = 0;
    virtual QLabel& setBatteryCMU1Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU2Temp() = 0;
    virtual QLabel& setBatteryCMU2Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU3Temp() = 0;
    virtual QLabel& setBatteryCMU3Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU4Temp() = 0;
    virtual QLabel& setBatteryCMU4Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell8Voltage() = 0;

    virtual QList<QLabel*>& batteryCMUCellVoltageLabels() = 0;

    virtual QLabel& softwareOverCurrentLabel1() = 0;
    virtual QLabel& hardwareOverCurrentLabel1() = 0;

    virtual QLabel& softwareOverCurrentLabel2() = 0;
    virtual QLabel& hardwareOverCurrentLabel2() = 0;

    virtual QLabel& cellOverVoltageLabel() = 0;
    virtual QLabel& cellUnderVoltageLabel() = 0;
    virtual QLabel& cellOverTemperatureLabel() = 0;
    virtual QLabel& cmuCommunicationsTimeoutLabel() = 0;

    virtual QLabel& setInputSerialConnectionStatus() = 0;
    virtual QLabel& setOutput3GConnectionStatus() = 0;
};
