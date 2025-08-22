#ifndef HEADER_GUARD_AetheriumArchivar_TitleBar_HPP
#define HEADER_GUARD_AetheriumArchivar_TitleBar_HPP

/*
 * GhostWriter
 *
 * Copyright (C) 2021 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QHBoxLayout>
#include <QWidget>
//// end includes

//// begin specific includes
//// end specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace NW {
/**
 * class TitleBar
 *
 * @brief
 *
 */
class TitleBar : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit TitleBar(QWidget *parent = nullptr);
    /// Destructor
    virtual ~TitleBar();
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    QHBoxLayout *m_pLayout;
    //// end protected member

    //// begin private member
private:
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
#endif // HEADER_GUARD_AetheriumArchivar_TitleBar_HPP
