#ifndef ENCLOSERWIDGET_HPP
#define ENCLOSERWIDGET_HPP

#include <QWidget>

namespace Ui {
class EnclosureWidget;
}

class EnclosureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EnclosureWidget(QWidget *parent = nullptr);
    ~EnclosureWidget();

private:
    Ui::EnclosureWidget *ui;
};

#endif // ENCLOSERWIDGET_HPP
