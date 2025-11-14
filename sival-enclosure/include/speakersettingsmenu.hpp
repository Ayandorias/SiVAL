#ifndef SPEAKERSETTINGSMENU_HPP
#define SPEAKERSETTINGSMENU_HPP

#include <QWidget>

namespace Ui {
class SpeakerSettingsMenu;
}

class SpeakerSettingsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SpeakerSettingsMenu(QWidget *parent = nullptr);
    ~SpeakerSettingsMenu();

private:
    Ui::SpeakerSettingsMenu *ui;
};

#endif // SPEAKERSETTINGSMENU_HPP
