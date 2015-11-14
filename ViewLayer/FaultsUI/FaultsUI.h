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

#include "I_FaultsUI.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

namespace Ui {
	class FaultsUI;
}

class FaultsUI : public I_SolarCarWindow, public I_FaultsUI
{
	Q_OBJECT
public:
    explicit FaultsUI();
    ~FaultsUI();

    void hideHeaderBar();

    /* Motor One Error Flags */
	QLabel& desaturationFaultLabel1();
	QLabel& badMotorPositionHallSequenceLabel1();
	QLabel& fifteenVoltRailUnderVoltageLockoutLabel1();
	QLabel& dcBusOverVoltageLabel1();
	QLabel& configReadErrorLabel1();
	QLabel& softwareOverCurrentLabel1();
	QLabel& watchDogCausedLastResetLabel1();
	QLabel& hardwareOverCurrentLabel1();

    /* Motor Two Error Flags */
	QLabel& desaturationFaultLabel2();
	QLabel& badMotorPositionHallSequenceLabel2();
	QLabel& fifteenVoltRailUnderVoltageLockoutLabel2();
	QLabel& dcBusOverVoltageLabel2();
	QLabel& configReadErrorLabel2();
	QLabel& softwareOverCurrentLabel2();
	QLabel& watchDogCausedLastResetLabel2();
	QLabel& hardwareOverCurrentLabel2();

	/* Motor One Limit Flags */
	QLabel& ipmTemperatureOrMotorTemperatureLabel1();
	QLabel& velocityLabel1();
	QLabel& busVoltageUpperLimitLabel1();
	QLabel& busVoltageLowerLimitLabel1();
	QLabel& motorCurrentLabel1();
	QLabel& outputVoltagePwmLabel1();
	QLabel& busCurrentLabel1();

	/* Motor Two Limit Flags */
	QLabel& ipmTemperatureOrMotorTemperatureLabel2();
	QLabel& velocityLabel2();
	QLabel& busVoltageUpperLimitLabel2();
	QLabel& busVoltageLowerLimitLabel2();
	QLabel& motorCurrentLabel2();
	QLabel& outputVoltagePwmLabel2();
	QLabel& busCurrentLabel2();

	/* Battery Error Flags */
	QLabel& cellOverVoltageLabel();
	QLabel& cellUnderVoltageLabel();
	QLabel& cellOverTemperatureLabel();
	QLabel& measurementUntrustedLabel();
	QLabel& vehicleCommunicationsTimeoutLabel();
	QLabel& bmuInSetupModeLabel();
	QLabel& cmuCanBusPowerStatusLabel();
	QLabel& packIsolationTestFailureLabel();
	QLabel& softwareOverCurrentMeasurementNotValidLabel();
	QLabel& can12vSupplyLowLabel();
	QLabel& contactorStuckOrNotEngagedLabel();
	QLabel& cmuDetectedExtraCellLabel();
	QLabel& cmuCommunicationsTimeoutLabel();

	QTextEdit& historyTextEdit();

private:
	Ui::FaultsUI *ui;
};

