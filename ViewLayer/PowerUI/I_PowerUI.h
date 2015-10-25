/**
 *  Schulich Delta Host Telemetry
 *  Copyright (C) 2015 University of Calgary Solar Car Team
 *
 *  This file is part of the Schulich Delta Host Telemetry
 *
 *  The Schulich Delta Host Telemetry is free software: 
 *  you can redistribute it and/or modify it under the terms 
 *  of the GNU Affero General Public License as published by 
 *  the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  The Schulich Delta Host Telemetry is distributed 
 *  in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
 *  without even the implied warranty of MERCHANTABILITY or 
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Affero 
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General 
 *  Public License along with the Schulich Delta Host Telemetry.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  For further contact, email <software@calgarysolarcar.ca>
 */

#pragma once

//#include "qwt_plot.h"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>
//#include <qwt_plot_curve.h>

class I_PowerUI
{
public:
	virtual ~I_PowerUI() {}

    virtual QPushButton& connectButton() = 0;
    virtual QLabel& setConnectionStatus() = 0;
    virtual QWidget& setConnectionHealth() = 0;
    virtual QComboBox& getConnectionType() = 0;
    virtual QLineEdit& getUdpGroupAddress() = 0;
    virtual QSpinBox& getUdpPortNumber() = 0;
    virtual QWidget& getSerialParametersWidget() = 0;
    virtual QLineEdit& getSerialPortName() = 0;
    virtual QLineEdit& getBaudRate() = 0;

    virtual QLabel& secondsSinceLastPacket() = 0;
    virtual QLabel& packetInLastMinute() = 0;
    virtual QLabel& secondsSinceLastValidPacket() = 0;
    virtual QLabel& validPacketsInLastMinute() = 0;
    virtual QLabel& invalidPacketsInLastMinute() = 0;

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

    virtual QPushButton& busGraphButton() = 0;
    virtual QPushButton& driverGraphButton() = 0;
    virtual QPushButton& batteryGraphButton() = 0;

    virtual QStackedWidget& setGraphsStackedWidget() = 0;
    /*
    virtual QwtPlotCurve& setPositiveBusCurrentCurve() = 0; 
    virtual QwtPlotCurve& setNegativeBusCurrentCurve() = 0; 
    virtual QwtPlotCurve& setBusVoltageCurve() = 0; 
    virtual QwtPlotCurve& setBusPowerCurve() = 0; 
    virtual QwtPlotCurve& setSetSpeedCurve() = 0; 
    virtual QwtPlotCurve& setActualSpeedCurve() = 0; 
    virtual QwtPlotCurve& setSetCurrentCurve() = 0;
    virtual QwtPlotCurve& setMod0CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod1CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod2CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod3CellTempCurve() = 0;
    virtual QwtPlotCurve& setMaxCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setMinCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setAvgCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setBatteryPowerCurve() = 0;*/
};
