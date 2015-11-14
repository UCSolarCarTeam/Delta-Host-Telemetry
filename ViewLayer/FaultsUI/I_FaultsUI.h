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

#include <QLabel>
#include <QTextEdit>

class I_FaultsUI
{
public:
	virtual ~I_FaultsUI() {}

	/* Motor One Limit Flags */
	virtual QLabel& ipmTemperatureOrMotorTemperatureLabel1() = 0;
	virtual QLabel& busVoltageUpperLimitLabel1() = 0;
	virtual QLabel& motorCurrentLabel1() = 0;
	virtual QLabel& busVoltageLowerLimitLabel1() = 0;
	virtual QLabel& outputVoltagePwmLabel1() = 0;
	virtual QLabel& busCurrentLabel1() = 0;
	virtual QLabel& velocityLabel1() = 0;

	/* Motor Two Limit Flags */
	virtual QLabel& desaturationFaultLabel1() = 0;
	virtual QLabel& badMotorPositionHallSequenceLabel1() = 0;
	virtual QLabel& fifteenVoltRailUnderVoltageLockoutLabel1() = 0;
	virtual QLabel& configReadErrorLabel1() = 0;
	virtual QLabel& watchDogCausedLastResetLabel1() = 0;
	virtual QLabel& dcBusOverVoltageLabel1() = 0;
	virtual QLabel& softwareOverCurrentLabel1() = 0;
	virtual QLabel& hardwareOverCurrentLabel1() = 0;

    /* Motor One Error Flags */
	virtual QLabel& ipmTemperatureOrMotorTemperatureLabel2() = 0;
	virtual QLabel& busVoltageUpperLimitLabel2() = 0;
	virtual QLabel& motorCurrentLabel2() = 0;
	virtual QLabel& busVoltageLowerLimitLabel2() = 0;
	virtual QLabel& outputVoltagePwmLabel2() = 0;
	virtual QLabel& busCurrentLabel2() = 0;
	virtual QLabel& velocityLabel2() = 0;

    /* Motor Two Error Flags */
	virtual QLabel& desaturationFaultLabel2() = 0;
	virtual QLabel& badMotorPositionHallSequenceLabel2() = 0;
	virtual QLabel& fifteenVoltRailUnderVoltageLockoutLabel2() = 0;
	virtual QLabel& configReadErrorLabel2() = 0;
	virtual QLabel& watchDogCausedLastResetLabel2() = 0;
	virtual QLabel& dcBusOverVoltageLabel2() = 0;
	virtual QLabel& softwareOverCurrentLabel2() = 0;
	virtual QLabel& hardwareOverCurrentLabel2() = 0;

	/* Battery Error Flags */
	virtual QLabel& cellOverVoltageLabel() = 0;
	virtual QLabel& bmuInSetupModeLabel() = 0;
	virtual QLabel& cellOverTemperatureLabel() = 0;
	virtual QLabel& softwareOverCurrentMeasurementNotValidLabel() = 0;
	virtual QLabel& cellUnderVoltageLabel() = 0;
	virtual QLabel& can12vSupplyLowLabel() = 0;
	virtual QLabel& vehicleCommunicationsTimeoutLabel() = 0;
	virtual QLabel& packIsolationTestFailureLabel() = 0;
	virtual QLabel& contactorStuckOrNotEngagedLabel() = 0;
	virtual QLabel& cmuCanBusPowerStatusLabel() = 0;
	virtual QLabel& measurementUntrustedLabel() = 0;
	virtual QLabel& cmuDetectedExtraCellLabel() = 0;

	virtual QTextEdit& historyTextEdit() = 0;
};
