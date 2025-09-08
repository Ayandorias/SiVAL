#ifndef PROJECTMENU_HPP
#define PROJECTMENU_HPP

#include <QWidget>

namespace Ui {
class ProjectMenu;
}

class ProjectMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectMenu(QWidget *parent = nullptr);
    ~ProjectMenu();

private:
    Ui::ProjectMenu *ui;
};

#endif // PROJECTMENU_HPP
