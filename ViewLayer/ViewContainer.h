#pragma once

#include <QScopedPointer>

class DisplayView;
class CompactUI;
class CompactView;
class PresenterContainer;

class ViewContainer
{
public:
   explicit ViewContainer(PresenterContainer& presenterContainer);
   ~ViewContainer();

private:
   CompactUI* compactUI_;
   QScopedPointer<CompactView> compactView_;
   QScopedPointer<DisplayView> displayView_;
};
