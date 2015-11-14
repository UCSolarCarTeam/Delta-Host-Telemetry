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

#include <QMainWindow>
#include "../I_SolarCarWindow/I_SolarCarWindow.h"
#include "I_EscapeDialog.h"
namespace Ui {
   class EscapeDialog;
}

class EscapeDialog : public I_SolarCarWindow, public I_EscapeDialog
{
    Q_OBJECT
public:
   explicit EscapeDialog();
   ~EscapeDialog();

   void hideHeaderBar();
   void keyPressEvent(QKeyEvent * event);
   void paintEvent(QPaintEvent* e);
   QPushButton& settingsSelectionPushButton();
   QPushButton& aboutSelectionPushButton();
   QPushButton& exitPushButton();
   QPushButton& okPushButton();
   QPushButton& closePushButton();
   QPushButton& playbackModePushButton();
   QCheckBox& fullscreenCheckBox();
   QStackedWidget& optionsDisplayWidget();

signals:
   void changeWindowState(int);

private slots:
   void handleFullScreenCheckBoxStateChange(int);

private:
   Ui::EscapeDialog *ui;
};
