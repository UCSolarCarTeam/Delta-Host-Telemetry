#include "compactui.h"
#include "ui_compactui.h"

compactui::compactui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::compactui)
{
    ui->setupUi(this);
}

compactui::~compactui()
{
    delete ui;
}
