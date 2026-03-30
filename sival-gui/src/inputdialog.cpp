/*
 * SiVAL
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
//// end system includes

//// begin project specific includes
#include "sivalgui/inputdialog.hpp"
//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin extern declaration
//// end extern declaration

//// begin static definitions
//// end static definitions

//// begin static functions
//// end static functions

namespace SiVAL::Gui {
//// begin public member methods
/**************************************************************************************************/
/**
 *
 */
InputDialog::InputDialog(const QString &title, const QString &info, QWidget *parent)
    :OverlayDialog(parent) {

    setupUi(m_centerWidget);
    m_pLabel->setText(title);

    connect(m_pAccept, &QPushButton::clicked, this, &InputDialog::ok);
    m_pAccept->setDisabled(true);
    m_project->setText(info);
}

/**************************************************************************************************/
/**
 *
 */
InputDialog::~InputDialog() {
}

void InputDialog::setAcceptLabel(const QString &text) {
    m_pAccept->setText(text);
}
QString InputDialog::text() {
    return m_projectName->text();
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void InputDialog::retranslateUi() {
}

void InputDialog::setupUi(QWidget *ProjectNewDialog) {
    ProjectNewDialog->setObjectName("dialogCenterWidget");

    // ProjectNewDialog->resize(1042, 526);
    ProjectNewDialog->setStyleSheet(QString::fromUtf8(""));
    verticalLayout = new QVBoxLayout(ProjectNewDialog);
    verticalLayout->setObjectName("verticalLayout");
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    // m_header = new SiVAL::Gui::HeaderLabel(ProjectNewDialog);
    // m_header->setObjectName("m_header");
    // verticalLayout->addWidget(m_header);

    m_headerInfo = new SiVAL::Gui::Label(ProjectNewDialog);
    m_headerInfo->setObjectName("dialogHeaderInfo");

    verticalLayout->addWidget(m_headerInfo);

    m_project = new SiVAL::Gui::Label(ProjectNewDialog);
    m_project->setObjectName("m_project");

    verticalLayout->addWidget(m_project);

    m_projectName = new QLineEdit(ProjectNewDialog);
    m_projectName->setObjectName("m_projectName");
    m_projectName->setMinimumSize(QSize(0, 32));
    // m_projectName->setStyleSheet(QString::fromUtf8("background-color:#ffffff; color: #606060;"));
    connect(m_projectName, &QLineEdit::textChanged, this, [this]{
        if(m_projectName->text().isEmpty()) {
            m_pAccept->setDisabled(true);
        } else {
            m_pAccept->setDisabled(false);

        }
    });

    verticalLayout->addWidget(m_projectName);

    verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

    verticalLayout->addItem(verticalSpacer_2);

    retranslateUi();
}
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
//// end private slots
}