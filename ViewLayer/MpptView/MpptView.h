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

#include <QObject>

class MpptPresenter;
class MpptUI;

class MpptView : public QObject
{
	Q_OBJECT
public:
    MpptView(MpptPresenter& presenter, MpptUI& ui);
    ~MpptView();

private:
	void updateMppt1PowerIn();
	void updateMppt1PowerOut();
	void updateMppt1Efficiency();

	void updateMppt2PowerIn();
	void updateMppt2PowerOut();
	void updateMppt2Efficiency();

	void updateMppt3PowerIn();
	void updateMppt3PowerOut();
	void updateMppt3Efficiency();

	void updateMppt4PowerIn();
	void updateMppt4PowerOut();
	void updateMppt4Efficiency();

	void updateMppt5PowerIn();
	void updateMppt5PowerOut();
	void updateMppt5Efficiency();

	void updateMppt6PowerIn();
	void updateMppt6PowerOut();
	void updateMppt6Efficiency();

	void updateMppt7PowerIn();
	void updateMppt7PowerOut();
	void updateMppt7Efficiency();

	MpptPresenter& presenter_;
	MpptUI& ui_;

private slots:
	void mppt1VoltageInReceived(double);
	void mppt1CurrentInReceived(double);
	void mppt1VoltageOutReceived(double);
	void mppt1CurrentOutReceived(double);
	void mppt1TypeReceived(QString);
	void mppt1ModeReceived(QString);

	void mppt2VoltageInReceived(double);
	void mppt2CurrentInReceived(double);
	void mppt2VoltageOutReceived(double);
	void mppt2CurrentOutReceived(double);
	void mppt2TypeReceived(QString);
	void mppt2ModeReceived(QString);

	void mppt3VoltageInReceived(double);
	void mppt3CurrentInReceived(double);
	void mppt3VoltageOutReceived(double);
	void mppt3CurrentOutReceived(double);
	void mppt3TypeReceived(QString);
	void mppt3ModeReceived(QString);

	void mppt4VoltageInReceived(double);
	void mppt4CurrentInReceived(double);
	void mppt4VoltageOutReceived(double);
	void mppt4CurrentOutReceived(double);
	void mppt4TypeReceived(QString);
	void mppt4ModeReceived(QString);

	void mppt5VoltageInReceived(double);
	void mppt5CurrentInReceived(double);
	void mppt5VoltageOutReceived(double);
	void mppt5CurrentOutReceived(double);
	void mppt5TypeReceived(QString);
	void mppt5ModeReceived(QString);

	void mppt6VoltageInReceived(double);
	void mppt6CurrentInReceived(double);
	void mppt6VoltageOutReceived(double);
	void mppt6CurrentOutReceived(double);
	void mppt6TypeReceived(QString);
	void mppt6ModeReceived(QString);

	void mppt7VoltageInReceived(double);
	void mppt7CurrentInReceived(double);
	void mppt7VoltageOutReceived(double);
	void mppt7CurrentOutReceived(double);
	void mppt7TypeReceived(QString);
	void mppt7ModeReceived(QString);
};


