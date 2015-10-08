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
    
    void setMppt1CurrentIn(double);
    void setMppt1CurrentOut(double);
    void setMppt2CurrentIn(double);
    void setMppt2CurrentOut(double);
    void setMppt3CurrentIn(double);
    void setMppt3CurrentOut(double);
    void setMppt4CurrentIn(double);
    void setMppt4CurrentOut(double);
    void setMppt5CurrentIn(double);
    void setMppt5CurrentOut(double);
    void setMppt6CurrentIn(double);
    void setMppt6CurrentOut(double);
    void setMppt7CurrentIn(double);
    void setMppt7CurrentOut(double);
    void setMppt1VoltageIn(double);
    void setMppt1VoltageOut(double);
    void setMppt2VoltageIn(double);
    void setMppt2VoltageOut(double);
    void setMppt3VoltageIn(double);
    void setMppt3VoltageOut(double);
    void setMppt4VoltageIn(double);
    void setMppt4VoltageOut(double);
    void setMppt5VoltageIn(double);
    void setMppt5VoltageOut(double);
    void setMppt6VoltageIn(double);
    void setMppt6VoltageOut(double);
    void setMppt7VoltageIn(double);
    void setMppt7VoltageOut(double);

    double getMppt1CurrentIn();
    double getMppt1CurrentOut();
    double getMppt2CurrentIn();
    double getMppt2CurrentOut();
    double getMppt3CurrentIn();
    double getMppt3CurrentOut();
    double getMppt4CurrentIn();
    double getMppt4CurrentOut();
    double getMppt5CurrentIn();
    double getMppt5CurrentOut();
    double getMppt6CurrentIn();
    double getMppt6CurrentOut();
    double getMppt7CurrentIn();
    double getMppt7CurrentOut();

    double getMppt1VoltageIn();
    double getMppt1VoltageOut();
    double getMppt2VoltageIn();
    double getMppt2VoltageOut();
    double getMppt3VoltageIn();
    double getMppt3VoltageOut();
    double getMppt4VoltageIn();
    double getMppt4VoltageOut();
    double getMppt5VoltageIn();
    double getMppt5VoltageOut();
    double getMppt6VoltageIn();
    double getMppt6VoltageOut();
    double getMppt7VoltageIn();
    double getMppt7VoltageOut();

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

    QTextEdit& historyTextEdit();

    QLabel& setInputSerialConnectionStatus();
    QLabel& setOutput3GConnectionStatus();

private:
    double mppt1CurrentIn;
    double mppt1CurrentOut;
    double mppt1VoltageOut;
    double mppt1VoltageIn;

    double mppt2CurrentIn;
    double mppt2CurrentOut;
    double mppt2VoltageOut;
    double mppt2VoltageIn;

    double mppt3CurrentIn;
    double mppt3CurrentOut;
    double mppt3VoltageOut;
    double mppt3VoltageIn;

    double mppt4CurrentIn;
    double mppt4CurrentOut;
    double mppt4VoltageOut;
    double mppt4VoltageIn;

    double mppt5CurrentIn;
    double mppt5CurrentOut;
    double mppt5VoltageOut;
    double mppt5VoltageIn;

    double mppt6CurrentIn;
    double mppt6CurrentOut;
    double mppt6VoltageOut;
    double mppt6VoltageIn;

    double mppt7CurrentIn;
    double mppt7CurrentOut;
    double mppt7VoltageOut;
    double mppt7VoltageIn;

    Ui::CompactUI *ui;
    QList<QLabel*> batteryCMUCellVoltageLabels_;
};
