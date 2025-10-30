#include "speakersettingsmenu.hpp"
#include "ui_speakersettingsmenu.h"

SpeakerSettingsMenu::SpeakerSettingsMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpeakerSettingsMenu)
{
    ui->setupUi(this);
}

SpeakerSettingsMenu::~SpeakerSettingsMenu()
{
    delete ui;
}
