#include "encloserwidget.hpp"
#include "ui_encloserwidget.h"

EnclosureWidget::EnclosureWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EnclosureWidget)
{
    ui->setupUi(this);
}

EnclosureWidget::~EnclosureWidget()
{
    delete ui;
}
