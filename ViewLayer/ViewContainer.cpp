#include "DisplayView/DisplayView.h"
#include "CompactUI/CompactUI.h"
#include "CompactView/CompactView.h"
#include "I_SolarCarWindow/I_SolarCarWindow.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer)
: compactUI_(new CompactUI())
, compactView_(new CompactView(
      presenterContainer.batteryPresenter(),
      presenterContainer.vehiclePresenter(),
      presenterContainer.powerPresenter(),
      presenterContainer.communicationPresenter(),
      presenterContainer.faultsPresenter(),
      presenterContainer.mpptPresenter(),
      *compactUI_))
, displayView_(new DisplayView(*compactUI_))
{
}

ViewContainer::~ViewContainer()
{
}
