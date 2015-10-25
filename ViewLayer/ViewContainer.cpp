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

#include "DisplayView/DisplayView.h"
#include "EscapeDialog/EscapeDialog.h"
#include "EscapeDialogView/EscapeDialogView.h"
#include "FaultsUI/FaultsUI.h"
#include "FaultsView/FaultsView.h"
#include "I_SolarCarWindow/I_SolarCarWindow.h"
#include "MpptUI/MpptUI.h"
#include "MpptView/MpptView.h"
#include "OverlordWidget/OverlordWidget.h"
#include "PlaybackUI/PlaybackUI.h"
#include "PlaybackView/PlaybackView.h"
#include "PowerUI/PowerUI.h"
#include "PowerView/PowerView.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer)
: escapeDialog_(new EscapeDialog())
, powerUI_(new PowerUI())
, mpptUI_(new MpptUI())
, faultsUI_(new FaultsUI())
, playbackUI_(new PlaybackUI)
, escapeDialogView_(new EscapeDialogView(
      *escapeDialog_, *playbackUI_))
, powerView_(new PowerView(
      presenterContainer.batteryPresenter(),
      presenterContainer.vehiclePresenter(),
      presenterContainer.powerPresenter(),
      presenterContainer.powerGraphsPresenter(),
      presenterContainer.communicationPresenter(),
      *powerUI_))
, mpptView_(new MpptView(presenterContainer.mpptPresenter(), *mpptUI_))
, faultsView_(new FaultsView(presenterContainer.faultsPresenter(), *faultsUI_))
, overlordWidget_(new OverlordWidget(QList<I_SolarCarWindow*>() << powerUI_ << mpptUI_ << faultsUI_,
      escapeDialog_))
, displayView_(new DisplayView(*overlordWidget_))
, playbackView_(new PlaybackView(
   presenterContainer.playbackPresenter(),
   *playbackUI_))
{
}

ViewContainer::~ViewContainer()
{
}
