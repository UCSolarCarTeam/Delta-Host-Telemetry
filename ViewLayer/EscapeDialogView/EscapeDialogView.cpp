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

#include "EscapeDialogView.h"
#include "../EscapeDialog/EscapeDialog.h"
#include "../PlaybackUI/I_PlaybackUI.h"
#include <QDebug>
#include <QApplication>

EscapeDialogView::EscapeDialogView(EscapeDialog& ui, I_PlaybackUI& playbackUi)
: ui_(ui)
, playbackUi_(playbackUi)
{
   connect(&ui.settingsSelectionPushButton(), SIGNAL(clicked()),
      this, SLOT(handleSettingsSelectionPushButtonClicked()));
   connect(&ui.aboutSelectionPushButton(), SIGNAL(clicked()),
      this, SLOT(handleAboutSelectionPushButtonClicked()));
   connect(&ui.closePushButton(), SIGNAL(clicked()),
      this, SLOT(handleClosePushButtonClicked()));
   connect(&ui.exitPushButton(), SIGNAL(clicked()),
      this, SLOT(handleExitPushButtonClicked()));
   connect(&ui.okPushButton(), SIGNAL(clicked()),
      this, SLOT(handleOkPushButtonClicked()));
   connect(&ui.playbackModePushButton(), SIGNAL(clicked()),
      this, SLOT(handleRequestToOpenPlaybackMode()));

}

EscapeDialogView::~EscapeDialogView()
{
}

void EscapeDialogView::handleSettingsSelectionPushButtonClicked()
{
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(100,100,100);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(50,50,50);");
    ui_.optionsDisplayWidget().setCurrentIndex(1);
}

void EscapeDialogView::handleAboutSelectionPushButtonClicked()
{
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(50,50,50);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(100,100,100);");
    ui_.optionsDisplayWidget().setCurrentIndex(0);
}

void EscapeDialogView::handleExitPushButtonClicked()
{
    QApplication::exit();
}

void EscapeDialogView::handleClosePushButtonClicked()
{
    ui_.hide();
}

void EscapeDialogView::handleOkPushButtonClicked()
{
    saveChanges();
    ui_.hide();
}

void EscapeDialogView::saveChanges()
{
}

void EscapeDialogView::handleRequestToOpenPlaybackMode()
{
   if(!playbackUi_.isVisible()){
      Qt::WindowFlags windowFlags = Qt::Tool | Qt::WindowStaysOnTopHint;
      playbackUi_.setWindowFlags(windowFlags);
      ui_.hide();
      playbackUi_.show();
   }
}

