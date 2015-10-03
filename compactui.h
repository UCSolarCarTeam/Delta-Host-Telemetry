#ifndef COMPACTUI_H
#define COMPACTUI_H

#include <QMainWindow>

namespace Ui {
class compactui;
}

class compactui : public QMainWindow
{
    Q_OBJECT

public:
    explicit compactui(QWidget *parent = 0);
    ~compactui();

private:
    Ui::compactui *ui;
};

#endif // COMPACTUI_H
