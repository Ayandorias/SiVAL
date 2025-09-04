#include "homewidget.hpp"
#include "ui_homewidget.h"

HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    ui->m_pNewProject->setTitle(tr("Neuen Character erstellen ..."));
    // ui->m_pNewProject->setInfoText(tr("Erstelle einen neuen individuellen Charakter!"));
    ui->m_pNewProject->setIcon(":/icon/new_dark.svg");

    ui->m_pOpenProject->setTitle(tr("Open Project"));
    ui->m_pOpenProject->setIcon(":/sival/open_dark.svg");
}

HomeWidget::~HomeWidget(){
    delete ui;
}
