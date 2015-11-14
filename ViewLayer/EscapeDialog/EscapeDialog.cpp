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

#include "EscapeDialog.h"
#include "ui_EscapeDialog.h"
#include <QPainter>
#include <QDebug>


EscapeDialog::EscapeDialog()
: ui(new Ui::EscapeDialog)
{
    ui->setupUi(this);
    connect(&(this->fullscreenCheckBox()),SIGNAL(stateChanged(int)),
            this, SLOT(handleFullScreenCheckBoxStateChange(int)));
}

EscapeDialog::~EscapeDialog()
{
    delete ui;
}

void EscapeDialog::keyPressEvent(QKeyEvent * event){
   hide();
}

void EscapeDialog::hideHeaderBar()
{
    ui->escapeTitleBarWidget->hide();
}

void EscapeDialog::handleFullScreenCheckBoxStateChange(int state)
{
    emit changeWindowState(state);
}

void EscapeDialog::paintEvent(QPaintEvent* e)
{
   QColor backgroundColor = palette().light().color();
    backgroundColor.setAlpha(50);
    QPainter customPainter(this);
    customPainter.fillRect(rect(), backgroundColor);
}
QPushButton& EscapeDialog::settingsSelectionPushButton()
{
   return *ui->settingsSelectionPushButton;
}
QPushButton& EscapeDialog::aboutSelectionPushButton()
{
   return *ui->aboutSelectionPushButton;
}

QPushButton& EscapeDialog::exitPushButton()
{
   return *ui->exitPushButton;
}
QPushButton& EscapeDialog::okPushButton()
{
   return *ui->okPushButton;
}
QPushButton& EscapeDialog::closePushButton()
{
   return *ui->closePushButton;
}
QPushButton& EscapeDialog::playbackModePushButton()
{
   return *ui->playbackModePushButton;
}
QCheckBox& EscapeDialog::fullscreenCheckBox()
{
   return *ui->fullscreenCheckBox;
}
QStackedWidget& EscapeDialog::optionsDisplayWidget()
{
   return *ui->optionsDisplayWidget;
}
