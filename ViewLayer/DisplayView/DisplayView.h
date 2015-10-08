#pragma once

#include <QObject>

class CompactUI;

class DisplayView : public QObject
{
   Q_OBJECT
public:
   DisplayView(CompactUI& ui);
   ~DisplayView();

private:
   CompactUI& ui_;
};
