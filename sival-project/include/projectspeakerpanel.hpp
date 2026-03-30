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
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
//// end system includes

//// begin project specific includes
#include <sivalcore/documents/projectdocument.hpp>
#include <sivalgui/enclosureitem.hpp>
#include <sivalgui/speakeritem.hpp>
#include <sivalgui/label.hpp>
#include <sivalgui/line.hpp>
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::PM {
/**
 * class ProjectSpeakerPanel
 *
 * @brief
 *
 */
class ProjectSpeakerPanel : public QWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit ProjectSpeakerPanel(QWidget *parent = nullptr);
    /// Destructor
    virtual ~ProjectSpeakerPanel();
    void update(SiVAL::Core::ProjectDocument *doc);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    void retranslate();
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    //// end protected member methods (internal use only)

    //// begin private member methods
private:
    void clearEnclosureList();
    void clearSpeakerList();
    void createEnclosureNew();
    void createSpeakerNew();
    void enclosureNew(QSharedPointer<Engine::AcousticSetup> as);
    void speakerNew(Core::SpeakerDocument *spkr);
    //// end private member methods

    //// begin public member
public:
    //// end public member

    //// begin protected member
protected:
    //// end protected member

    //// begin private member
private:
    QScrollArea *scrollArea, *scrollArea_2;
    QVBoxLayout *verticalLayout;
    Gui::Label *m_newLabel;
    Gui::Label *m_projectEnclosures;
    SiVAL::Gui::SpeakerItem *m_speakerNew;
    SiVAL::Gui::EnclosureItem *m_enclosureNew;
    SiVAL::Gui::Line *line;


    SiVAL::Core::ProjectDocument *m_projectDocument;
    SiVAL::Core::SpeakerDocument *m_spkrDoc;

    QWidget *m_speakerWidget;
    QHBoxLayout *m_speakerLayout, *m_EnclosureList;

    QVector<SiVAL::Core::SpeakerDocument*> m_spkrList;
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    void createEnclosure();
    void createSpeaker();
    void speakerItemClicked(SiVAL::Gui::Card *card);
    //// end protected slots

    //// begin private slots
private slots:
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}
