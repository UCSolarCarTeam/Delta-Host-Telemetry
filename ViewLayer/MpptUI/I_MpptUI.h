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
//#include "qwt_plot.h"
#include <QComboBox>
#include <QGraphicsView>
#include <QPushButton>
#include <QCheckBox>

class I_MpptUI
{
public:
	virtual ~I_MpptUI() {}

	virtual QLabel& setMppt1PowerIn() = 0;
	virtual QLabel& setMppt1VoltageIn() = 0;
	virtual QLabel& setMppt1CurrentIn() = 0;
	virtual QLabel& setMppt1PowerOut() = 0;
	virtual QLabel& setMppt1VoltageOut() = 0;
	virtual QLabel& setMppt1CurrentOut() = 0;
	virtual QLabel& setMppt1Efficiency() = 0;
	virtual QLabel& setMppt1Type() = 0;
	virtual QLabel& setMppt1Mode() = 0;

	virtual QLabel& setMppt2PowerIn() = 0;
	virtual QLabel& setMppt2VoltageIn() = 0;
	virtual QLabel& setMppt2CurrentIn() = 0;
	virtual QLabel& setMppt2PowerOut() = 0;
	virtual QLabel& setMppt2VoltageOut() = 0;
	virtual QLabel& setMppt2CurrentOut() = 0;
	virtual QLabel& setMppt2Efficiency() = 0;
	virtual QLabel& setMppt2Type() = 0;
	virtual QLabel& setMppt2Mode() = 0;

	virtual QLabel& setMppt3PowerIn() = 0;
	virtual QLabel& setMppt3VoltageIn() = 0;
	virtual QLabel& setMppt3CurrentIn() = 0;
	virtual QLabel& setMppt3PowerOut() = 0;
	virtual QLabel& setMppt3VoltageOut() = 0;
	virtual QLabel& setMppt3CurrentOut() = 0;
	virtual QLabel& setMppt3Efficiency() = 0;
	virtual QLabel& setMppt3Type() = 0;
	virtual QLabel& setMppt3Mode() = 0;

	virtual QLabel& setMppt4PowerIn() = 0;
	virtual QLabel& setMppt4VoltageIn() = 0;
	virtual QLabel& setMppt4CurrentIn() = 0;
	virtual QLabel& setMppt4PowerOut() = 0;
	virtual QLabel& setMppt4VoltageOut() = 0;
	virtual QLabel& setMppt4CurrentOut() = 0;
	virtual QLabel& setMppt4Efficiency() = 0;
	virtual QLabel& setMppt4Type() = 0;
	virtual QLabel& setMppt4Mode() = 0;

	virtual QLabel& setMppt5PowerIn() = 0;
	virtual QLabel& setMppt5VoltageIn() = 0;
	virtual QLabel& setMppt5CurrentIn() = 0;
	virtual QLabel& setMppt5PowerOut() = 0;
	virtual QLabel& setMppt5VoltageOut() = 0;
	virtual QLabel& setMppt5CurrentOut() = 0;
	virtual QLabel& setMppt5Efficiency() = 0;
	virtual QLabel& setMppt5Type() = 0;
	virtual QLabel& setMppt5Mode() = 0;

	virtual QLabel& setMppt6PowerIn() = 0;
	virtual QLabel& setMppt6VoltageIn() = 0;
	virtual QLabel& setMppt6CurrentIn() = 0;
	virtual QLabel& setMppt6PowerOut() = 0;
	virtual QLabel& setMppt6VoltageOut() = 0;
	virtual QLabel& setMppt6CurrentOut() = 0;
	virtual QLabel& setMppt6Efficiency() = 0;
	virtual QLabel& setMppt6Type() = 0;
	virtual QLabel& setMppt6Mode() = 0;

	virtual QLabel& setMppt7PowerIn() = 0;
	virtual QLabel& setMppt7VoltageIn() = 0;
	virtual QLabel& setMppt7CurrentIn() = 0;
	virtual QLabel& setMppt7PowerOut() = 0;
	virtual QLabel& setMppt7VoltageOut() = 0;
	virtual QLabel& setMppt7CurrentOut() = 0;
	virtual QLabel& setMppt7Efficiency() = 0;
	virtual QLabel& setMppt7Type() = 0;
	virtual QLabel& setMppt7Mode() = 0;
	}; 
