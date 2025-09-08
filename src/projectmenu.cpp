#include "projectmenu.hpp"
#include "ui_projectmenu.h"

ProjectMenu::ProjectMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectMenu)
{
    ui->setupUi(this);
}

ProjectMenu::~ProjectMenu()
{
    delete ui;
}
