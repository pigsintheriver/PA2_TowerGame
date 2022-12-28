#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(int w,int h,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("SETTINGS");
    ui->wSPB->setValue(w);
    ui->hSPB->setValue(h);

    //connect()
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
