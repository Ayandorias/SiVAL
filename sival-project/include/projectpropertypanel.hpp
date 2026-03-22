#pragma once

/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QWidget>
//// end system includes

//// begin project specific includes
#include <sivalcore/documents/projectdocument.hpp>
#include <sivalgui/speakerspecification.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations

namespace Ui {
class ProjectPropertyPanel;
}
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::PM {
/**
 * class ProjectPropertyPanel
 *
 * @brief
 *
 */
class ProjectPropertyPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectPropertyPanel(QWidget *parent);
    /// Destructor
    virtual ~ProjectPropertyPanel();

    void update(SiVAL::Core::ProjectDocument *doc);
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
    //// end protected member

    //// begin private member
private:
    Ui::ProjectPropertyPanel *ui;

    SiVAL::Core::ProjectDocument *m_projectDocument;
    QVector<SiVAL::Gui::SpeakerSpecification*> m_speakerList;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void openDocumentLocation();
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
