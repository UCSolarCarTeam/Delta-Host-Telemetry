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

    QLabel& setMppt1Efficiency();
    QLabel& setMppt2Efficiency();
    QLabel& setMppt3Efficiency();
    QLabel& setMppt4Efficiency();
    QLabel& setMppt5Efficiency();
    QLabel& setMppt6Efficiency();
    QLabel& setMppt7Efficiency();

    QLabel& setMppt1PowerIn();
    QLabel& setMppt2PowerIn();
    QLabel& setMppt3PowerIn();
    QLabel& setMppt4PowerIn();
    QLabel& setMppt5PowerIn();
    QLabel& setMppt6PowerIn();
    QLabel& setMppt7PowerIn();

    QLabel& setMppt1PowerOut();
    QLabel& setMppt2PowerOut();
    QLabel& setMppt3PowerOut();
    QLabel& setMppt4PowerOut();
    QLabel& setMppt5PowerOut();
    QLabel& setMppt6PowerOut();
    QLabel& setMppt7PowerOut();

    QLabel& setSetSpeed();
    QLabel& setSetCurrent();
    QLabel& setActualSpeed();
    QLabel& setBusCurrent();
    QLabel& setBusVoltage();
    QLabel& setBatteryCurrent();
    QLabel& setBatteryVoltage();

    QLabel& setBatteryCMU1Temp();
    QLabel& setBatteryCMU1Cell1Voltage();
    QLabel& setBatteryCMU1Cell2Voltage();
    QLabel& setBatteryCMU1Cell3Voltage();
    QLabel& setBatteryCMU1Cell4Voltage();
    QLabel& setBatteryCMU1Cell5Voltage();
    QLabel& setBatteryCMU1Cell6Voltage();
    QLabel& setBatteryCMU1Cell7Voltage();
    QLabel& setBatteryCMU1Cell8Voltage();

    QLabel& setBatteryCMU2Temp();
    QLabel& setBatteryCMU2Cell1Voltage();
    QLabel& setBatteryCMU2Cell2Voltage();
    QLabel& setBatteryCMU2Cell3Voltage();
    QLabel& setBatteryCMU2Cell4Voltage();
    QLabel& setBatteryCMU2Cell5Voltage();
    QLabel& setBatteryCMU2Cell6Voltage();
    QLabel& setBatteryCMU2Cell7Voltage();
    QLabel& setBatteryCMU2Cell8Voltage();

    QLabel& setBatteryCMU3Temp();
    QLabel& setBatteryCMU3Cell1Voltage();
    QLabel& setBatteryCMU3Cell2Voltage();
    QLabel& setBatteryCMU3Cell3Voltage();
    QLabel& setBatteryCMU3Cell4Voltage();
    QLabel& setBatteryCMU3Cell5Voltage();
    QLabel& setBatteryCMU3Cell6Voltage();
    QLabel& setBatteryCMU3Cell7Voltage();
    QLabel& setBatteryCMU3Cell8Voltage();

    QLabel& setBatteryCMU4Temp();
    QLabel& setBatteryCMU4Cell1Voltage();
    QLabel& setBatteryCMU4Cell2Voltage();
    QLabel& setBatteryCMU4Cell3Voltage();
    QLabel& setBatteryCMU4Cell4Voltage();
    QLabel& setBatteryCMU4Cell5Voltage();
    QLabel& setBatteryCMU4Cell6Voltage();
    QLabel& setBatteryCMU4Cell7Voltage();
    QLabel& setBatteryCMU4Cell8Voltage();

    QList<QLabel*>& batteryCMUCellVoltageLabels();

    QLabel& softwareOverCurrentLabel1();
    QLabel& hardwareOverCurrentLabel1();

    QLabel& softwareOverCurrentLabel2();
    QLabel& hardwareOverCurrentLabel2();

    QLabel& cellOverVoltageLabel();
    QLabel& cellUnderVoltageLabel();
    QLabel& cellOverTemperatureLabel();
    QLabel& cmuCommunicationsTimeoutLabel();

    QLabel& setInputSerialConnectionStatus();
    QLabel& setOutput3GConnectionStatus();

private:
    Ui::CompactUI *ui;
    QList<QLabel*> batteryCMUCellVoltageLabels_;
};
