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

#include <QPushButton>
#include <QCheckBox>
#include <QStackedWidget>
#include <QWidget>
#include <QLineEdit>
class I_EscapeDialog
{
public:
    virtual ~I_EscapeDialog() {}

    void keyPressEvent(QKeyEvent * event);
    virtual QPushButton& settingsSelectionPushButton() = 0;
    virtual QPushButton& aboutSelectionPushButton() = 0;
    virtual QPushButton& exitPushButton() = 0;
    virtual QPushButton& okPushButton() = 0;
    virtual QPushButton& closePushButton() = 0;
    virtual QPushButton& playbackModePushButton() = 0;
    virtual QCheckBox& fullscreenCheckBox() = 0;
    virtual QStackedWidget& optionsDisplayWidget() = 0;
};
