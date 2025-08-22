#pragma once

#ifndef HEADER_GUARD_AetheriumArchivar_SkillLabel_HPP
#define HEADER_GUARD_AetheriumArchivar_SkillLabel_HPP

/*
 * AetheriumArchivar$
 *
 * Copyright (C) 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin includes
#include <QLabel>
#include <QList>
#include <QPair>
#include <QSvgRenderer>
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
     * class SkillLabel
     *
     * @brief
     *
     */
    class SkillLabel : public QLabel
    {
        Q_OBJECT
        //// begin public member methods
    public:
        /// Constructor
        explicit SkillLabel(const QString &label, QWidget *parent);
        /// Destructor
        virtual ~SkillLabel();
        void addInfoText(const QString &key, const QString & value, bool dummy = false);
        void last();
        void setIcon(const QString &icon);
        void setSeparator(const QString &sep);
        void setSubentry(bool entry);
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
        void paintEvent(QPaintEvent *event) override;
        //// end private member methods

        //// begin public member
    public:
        //// end public member

        //// begin protected member
    protected:
        //// end protected member

        //// begin private member
    private:
        QList<QPair<QString, QString>> map;
        QString m_sLabel;
        QString m_sSep;
        QSvgRenderer *m_pIconRenderer;
        bool m_bDummy;
        bool m_bLast;
        bool m_bSubentry;
        int m_iSubentry;
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
#endif // HEADER_GUARD_AetheriumArchivar$_SkillLabel$_HPP
