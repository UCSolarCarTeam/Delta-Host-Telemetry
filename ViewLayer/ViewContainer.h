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

#include <QScopedPointer>

class DisplayView;
class EscapeDialog;
class EscapeDialogView;
class FaultsUI;
class FaultsView;
class MpptUI;
class MpptView;
class OverlordWidget;
class PlaybackUI;
class PlaybackView;
class PowerUI;
class PowerView;
class PresenterContainer;

class ViewContainer
{
public:
   explicit ViewContainer(PresenterContainer& presenterContainer);
   ~ViewContainer();

private:
   EscapeDialog* escapeDialog_;
   PowerUI* powerUI_;
   MpptUI* mpptUI_;
   FaultsUI* faultsUI_;
   QScopedPointer<PlaybackUI> playbackUI_;
   QScopedPointer<EscapeDialogView> escapeDialogView_;
   QScopedPointer<PowerView> powerView_;
   QScopedPointer<MpptView> mpptView_;
   QScopedPointer<FaultsView> faultsView_;
   QScopedPointer<OverlordWidget> overlordWidget_;
   QScopedPointer<DisplayView> displayView_;
   QScopedPointer<PlaybackView> playbackView_;
};
