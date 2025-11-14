#ifndef ENCLOSUREMENU_HPP
#define ENCLOSUREMENU_HPP

#include <QWidget>

namespace Ui {
class EnclosureMenu;
}

class EnclosureMenu : public QWidget
{
    Q_OBJECT

public:
    explicit EnclosureMenu(QWidget *parent = nullptr);
    ~EnclosureMenu();

private:
    Ui::EnclosureMenu *ui;
};

#endif // ENCLOSUREMENU_HPP
