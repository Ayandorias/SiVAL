#include "enclosuremenu.hpp"
#include "ui_enclosuremenu.h"

EnclosureMenu::EnclosureMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnclosureMenu)
{
    ui->setupUi(this);
}

EnclosureMenu::~EnclosureMenu()
{
    delete ui;
}
