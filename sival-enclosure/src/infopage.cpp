#include "infopage.hpp"
#include "ui_infopage.h"

InfoPage::InfoPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoPage)
{
    ui->setupUi(this);
}

InfoPage::~InfoPage()
{
    delete ui;
}
