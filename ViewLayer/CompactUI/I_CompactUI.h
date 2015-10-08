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

    virtual double getMppt1VoltageIn() = 0;
    virtual double getMppt1VoltageOut() = 0;
    virtual double getMppt2VoltageIn() = 0;
    virtual double getMppt2VoltageOut() = 0;
    virtual double getMppt3VoltageIn() = 0;
    virtual double getMppt3VoltageOut() = 0;
    virtual double getMppt4VoltageIn() = 0;
    virtual double getMppt4VoltageOut() = 0;
    virtual double getMppt5VoltageIn() = 0;
    virtual double getMppt5VoltageOut() = 0;
    virtual double getMppt6VoltageIn() = 0;
    virtual double getMppt6VoltageOut() = 0;
    virtual double getMppt7VoltageIn() = 0;
    virtual double getMppt7VoltageOut() = 0;

    virtual double getMppt1CurrentIn() = 0;
    virtual double getMppt1CurrentOut() = 0;
    virtual double getMppt2CurrentIn() = 0;
    virtual double getMppt2CurrentOut() = 0;
    virtual double getMppt3CurrentIn() = 0;
    virtual double getMppt3CurrentOut() = 0;
    virtual double getMppt4CurrentIn() = 0;
    virtual double getMppt4CurrentOut() = 0;
    virtual double getMppt5CurrentIn() = 0;
    virtual double getMppt5CurrentOut() = 0;
    virtual double getMppt6CurrentIn() = 0;
    virtual double getMppt6CurrentOut() = 0;
    virtual double getMppt7CurrentIn() = 0;
    virtual double getMppt7CurrentOut() = 0;

    virtual void setMppt1VoltageIn(double) = 0;
    virtual void setMppt1VoltageOut(double) = 0;
    virtual void setMppt2VoltageIn(double) = 0;
    virtual void setMppt2VoltageOut(double) = 0;
    virtual void setMppt3VoltageIn(double) = 0;
    virtual void setMppt3VoltageOut(double) = 0;
    virtual void setMppt4VoltageIn(double) = 0;
    virtual void setMppt4VoltageOut(double) = 0;
    virtual void setMppt5VoltageIn(double) = 0;
    virtual void setMppt5VoltageOut(double) = 0;
    virtual void setMppt6VoltageIn(double) = 0;
    virtual void setMppt6VoltageOut(double) = 0;
    virtual void setMppt7VoltageIn(double) = 0;
    virtual void setMppt7VoltageOut(double) = 0;
    virtual void setMppt1CurrentIn(double) = 0;
    virtual void setMppt1CurrentOut(double) = 0;
    virtual void setMppt2CurrentIn(double) = 0;
    virtual void setMppt2CurrentOut(double) = 0;
    virtual void setMppt3CurrentIn(double) = 0;
    virtual void setMppt3CurrentOut(double) = 0;
    virtual void setMppt4CurrentIn(double) = 0;
    virtual void setMppt4CurrentOut(double) = 0;
    virtual void setMppt5CurrentIn(double) = 0;
    virtual void setMppt5CurrentOut(double) = 0;
    virtual void setMppt6CurrentIn(double) = 0;
    virtual void setMppt6CurrentOut(double) = 0;
    virtual void setMppt7CurrentIn(double) = 0;
    virtual void setMppt7CurrentOut(double) = 0;

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

    virtual QTextEdit& historyTextEdit() = 0;

    virtual QLabel& setInputSerialConnectionStatus() = 0;
    virtual QLabel& setOutput3GConnectionStatus() = 0;
};
