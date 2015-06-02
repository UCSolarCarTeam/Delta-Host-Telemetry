#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QSharedPointer>
#include "I_OverlordWidget.h"

class I_SolarCarWindow;
class EscapeDialog;

class OverlordWidget : public QWidget, public I_OverlordWidget
{
	Q_OBJECT
public:
    explicit OverlordWidget(QList<I_SolarCarWindow*> viewWindows, 
                            EscapeDialog* escapeDialog,
                            QWidget *parent = 0);
	  ~OverlordWidget();

    void keyPressEvent(QKeyEvent * event);
    
    QString changeState();
    QString getState();

private:
    void setupEscapeDialog();
    QTabWidget* createTabWidget();
    void addFonts();

     QList<I_SolarCarWindow*> viewWindows_;
     QString state_;
     EscapeDialog* escapeDialog_;
};
