#include "DisplayView.h"
#include "../CompactUI/CompactUI.h"

DisplayView::DisplayView(CompactUI& ui)
: ui_(ui)
{
    ui_.show();
}

DisplayView::~DisplayView()
{
}
