#include "sivalgui/selectiontree.hpp"
#include <QHeaderView>
#include <QMouseEvent>
#include <QStyleOptionViewItem>
#include <QApplication>
#include <QStyle>

#include <iostream>

namespace SiVAL::Gui {

// =============================================================================
// Implementierung CheckBoxHeader
// =============================================================================

CheckBoxHeader::CheckBoxHeader(Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation, parent)
{

    // Die echte Checkbox erstellen.
    // Wichtig: 'this' als Parent, damit sie physisch IM Header liegt.
    m_checkBox = new QCheckBox(this);
    m_checkBox->setVisible(true);
    m_checkBox->setTristate(true);
    m_checkBox->setObjectName("checkHeader");

    // Styling-Attribute setzen (für QSS Selektoren, falls benötigt)
    // m_checkBox->setProperty("class", "HeaderCheckBox");

    // Verbindungen: Wenn sich Spalten ändern, muss die Checkbox wandern
    connect(this, &QHeaderView::sectionResized, this, &CheckBoxHeader::updateCheckBoxPosition);
    connect(this, &QHeaderView::geometriesChanged, this, &CheckBoxHeader::updateCheckBoxPosition);
}

void CheckBoxHeader::showEvent(QShowEvent *e)
{
    QHeaderView::showEvent(e);
    updateCheckBoxPosition();
}

void CheckBoxHeader::resizeEvent(QResizeEvent *e)
{
    QHeaderView::resizeEvent(e);
    updateCheckBoxPosition();
}

void CheckBoxHeader::updateCheckBoxPosition()
{
    // Ziel: Mitte der ersten Spalte (Index 0)
    int index = 0;

    // Position des Spaltenanfangs relativ zum Header
    int pos = sectionViewportPosition(index);

    // Breite der Spalte
    int width = sectionSize(index);

    // Höhe des Headers
    int height = this->height();

    // Größe der Checkbox
    QSize checkSize = m_checkBox->sizeHint();

    // Zentrierung berechnen
    int x = pos + (width - checkSize.width()) / 2;
    int y = (height - checkSize.height()) / 2;

    // Position anwenden
    m_checkBox->move(x, y);
    m_checkBox->resize(checkSize);
}


// =============================================================================
// Implementierung ChassisSelectTree
// =============================================================================

SelectionTree::SelectionTree(QWidget *parent)
    : QTreeWidget(parent)
{
    // 1. Den spezialisierten Header installieren
    CheckBoxHeader* myHeader = new CheckBoxHeader(Qt::Horizontal, this);
    setHeader(myHeader);

    // 2. Grundkonfiguration
    setColumnCount(3);
    // Spalte 0 leer lassen, da dort nun die echte Checkbox darüber schwebt
    setHeaderLabels({ "", tr("Chassis manufacturer"), tr("Count") });

    setAlternatingRowColors(true);
    setRootIsDecorated(false);
    setSelectionMode(QAbstractItemView::NoSelection);
    setFocusPolicy(Qt::NoFocus);

    setSortingEnabled(false);
    header()->setSectionsClickable(true);

    // 3. Spaltenbreiten
    // Spalte 0 muss breit genug für die Checkbox sein
    header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    header()->setMinimumSectionSize(30); // Sicherheitsbreite für die Checkbox

    header()->setSectionResizeMode(1, QHeaderView::Stretch);
    header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    // 4. Verbindung herstellen: Header-Checkbox -> Alle Zeilen
    connect(myHeader->checkBox(), &QCheckBox::clicked,
            this, &SelectionTree::onHeaderCheckToggled);

    connect(this, &QTreeWidget::itemChanged, this, [this](QTreeWidgetItem *item, int column) {
        // Nur relevant, wenn sich der CheckState in Spalte 0 geändert hat
        if (column == 0) {
            updateHeaderState();
        }
    });
}

void SelectionTree::addChassisEntry(const QString& manufacturer, int count, bool checked)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(this);
    // Standard-Indikator des Items nutzen
    item->setCheckState(0, checked ? Qt::Checked : Qt::Unchecked);
    item->setText(1, manufacturer);
    item->setText(2, QString::number(count));
    item->setTextAlignment(2, Qt::AlignCenter);

    // Header-Status prüfen
    updateHeaderState();
}

QStringList SelectionTree::getSelectedManufacturers() const
{
    QStringList selected;
    for (int i = 0; i < topLevelItemCount(); ++i) {
        QTreeWidgetItem *item = topLevelItem(i);
        if (item->checkState(0) == Qt::Checked) {
            selected.append(item->text(1));
        }
    }
    return selected;
}

void SelectionTree::setAllChecked(bool checked)
{
    const bool wasBlocked = blockSignals(true);
    Qt::CheckState state = checked ? Qt::Checked : Qt::Unchecked;

    for (int i = 0; i < topLevelItemCount(); ++i) {
        topLevelItem(i)->setCheckState(0, state);
    }

    blockSignals(wasBlocked);
    viewport()->update();

    // Header visuell synchronisieren (ohne rekursives Signal)
    if (auto head = qobject_cast<CheckBoxHeader*>(header())) {
        QSignalBlocker blocker(head->checkBox());
        head->checkBox()->setChecked(checked);
    }
}

void SelectionTree::onHeaderCheckToggled(bool checked)
{
    // Benutzer hat oben geklickt -> Alle Zeilen anpassen
    setAllChecked(checked);
}

void SelectionTree::updateHeaderState()
{
    int total = topLevelItemCount();
    if (total == 0) return;

    int checkedCount = 0;
    for (int i = 0; i < total; ++i) {
        if (topLevelItem(i)->checkState(0) == Qt::Checked) {
            checkedCount++;
        }
    }

    Qt::CheckState newState;
    if (checkedCount == 0) {
        newState = Qt::Unchecked;
    } else if (checkedCount == total) {
        newState = Qt::Checked;
    } else {
        newState = Qt::PartiallyChecked;
    }

    if (auto head = qobject_cast<CheckBoxHeader*>(header())) {
        QSignalBlocker blocker(head->checkBox());
        head->checkBox()->setCheckState(newState);
    }
}

void SelectionTree::mouseReleaseEvent(QMouseEvent *event)
{
    // Logik für die erweiterte Klickzone in den Zeilen
    QModelIndex index = indexAt(event->pos());

    if (index.isValid() && index.column() == 0) {
        QStyleOptionViewItem opt;
        initViewItemOption(&opt);
        opt.rect = visualRect(index);
        opt.features |= QStyleOptionViewItem::HasCheckIndicator;

        // Wo zeichnet Qt den Indikator?
        QRect checkRect = style()->subElementRect(QStyle::SE_ItemViewItemCheckIndicator, &opt, this);

        // Klick war NICHT auf der Checkbox (sondern daneben) -> Manuell toggeln
        bool manualToggleNeeded = !checkRect.contains(event->pos());

        if (manualToggleNeeded) {
            QTreeWidgetItem *item = itemFromIndex(index);
            bool isChecked = (item->checkState(0) == Qt::Checked);
            item->setCheckState(0, isChecked ? Qt::Unchecked : Qt::Checked);

            // Header aktualisieren und abbrechen
            updateHeaderState();
            return;
        }
    }

    // Standardverhalten (Qt toggelt selbst, wenn man die Checkbox trifft)
    QTreeWidget::mouseReleaseEvent(event);

    // Auch nach Standard-Klick den Header prüfen
    if (index.isValid() && index.column() == 0) {
        updateHeaderState();
    }
}

} // namespace SiVAL::GUI






#if 0

/*
 * SiVAL GUI
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 */

//// begin includes
//// end includes

//// begin system includes
#include <QMouseEvent>
#include <QStyleOptionViewItem>
//// end system includes

//// begin project specific includes
#include "sivalgui/selectiontree.hpp"
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
SelectionTree::SelectionTree(QWidget *parent)
    :QTreeWidget(parent) {

    // 1. Spaltenkonfiguration
    setColumnCount(3);
    setHeaderLabels({ "Auswahl", "Hersteller", "Anzahl" });

    // 2. Optik und Verhalten
    // setAlternatingRowColors(true);
    setRootIsDecorated(false); // Flache Liste, keine Äste
    setFocusPolicy(Qt::NoFocus);
    setSelectionMode(QAbstractItemView::NoSelection); // Fokus auf Checkboxen
    setUniformRowHeights(true);

    // 3. Spaltenbreiten
    // Spalte 0 (Checkbox) passt sich dem Inhalt (Text "Auswahl") an
    header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    // Spalte 1 (Name) nimmt den Raum ein
    header()->setSectionResizeMode(1, QHeaderView::Stretch);
    // Spalte 2 (Anzahl) passt sich an
    header()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    // 4. Interaktion aktivieren
    header()->setSectionsClickable(true);

    // Verbindung herstellen
    connect(header(), &QHeaderView::sectionClicked,
            this, &SelectionTree::onHeaderClicked);
}

SelectionTree::~SelectionTree() {
}

void SelectionTree::addChassisEntry(const QString& manufacturer, int count, bool checked) {
    QTreeWidgetItem *item = new QTreeWidgetItem(this);

    // Spalte 0: Checkbox
    item->setCheckState(0, checked ? Qt::Checked : Qt::Unchecked);

    // Daten
    item->setText(1, manufacturer);
    item->setText(2, QString::number(count));
    item->setTextAlignment(2, Qt::AlignCenter);
}

void SelectionTree::setAllChecked(bool checked) {
    // Performance: Signale blockieren, um ein "Gewitter" bei 1000 Items zu vermeiden
    const bool wasBlocked = blockSignals(true);

    Qt::CheckState state = checked ? Qt::Checked : Qt::Unchecked;

    for (int i = 0; i < topLevelItemCount(); ++i) {
        topLevelItem(i)->setCheckState(0, state);
    }

    // Signale wieder freigeben
    blockSignals(wasBlocked);

    // Ein einzelnes Signal senden, um Updates auszulösen (falls nötig)
    // emit itemChanged(topLevelItem(0), 0);
}
//// end public member methods

//// begin public member methods (internal use only)
//// end public member methods (internal use only)

//// begin protected member methods
//// end protected member methods

//// begin protected member methods (internal use only)
void SelectionTree::mouseReleaseEvent(QMouseEvent *event) {
    // 1. Ermitteln, welches Item unter der Maus liegt
    QModelIndex index = indexAt(event->pos());

    // 2. Nur reagieren, wenn es ein gültiges Item ist UND wir in Spalte 0 (Checkboxen) sind
    if (index.isValid() && index.column() == 0) {

        // 3. Geometrie der Checkbox ermitteln (Qt 6 Weg)
        QStyleOptionViewItem opt;
        initViewItemOption(&opt); // Befüllt das Optionsobjekt mit den Standardwerten der View

        opt.rect = visualRect(index); // Das Rechteck der gesamten Zelle
        opt.features |= QStyleOptionViewItem::HasCheckIndicator;

        // Qt fragen, wo genau der Indikator (Checkbox) gezeichnet wird
        QRect checkRect = style()->subElementRect(QStyle::SE_ItemViewItemCheckIndicator, &opt, this);

        // 4. Die Erweiterung der Klickfläche:
        // Wenn der Benutzer NICHT genau die Checkbox getroffen hat (sondern daneben klickte),
        // dann toggeln wir manuell.
        if (!checkRect.contains(event->pos())) {

            QTreeWidgetItem *item = itemFromIndex(index);
            // Zustand invertieren
            bool isChecked = (item->checkState(0) == Qt::Checked);
            item->setCheckState(0, isChecked ? Qt::Unchecked : Qt::Checked);

            // Abbruch, damit Qt das Event nicht weiterverarbeitet (kein Fokus-Springen)
            return;
        }
    }

    // 5. Standardverhalten für alle anderen Fälle
    QTreeWidget::mouseReleaseEvent(event);
}
//// end protected member methods (internal use only)

//// begin private member methods
//// end private member methods

//// begin public slots
//// end public slots

//// begin protected slots
//// end protected slots

//// begin private slots
void SelectionTree::onHeaderClicked(int section) {
    // Nur reagieren, wenn auf "Auswahl" (Index 0) geklickt wurde
    if (section == 0) {

        // Logik-Prüfung: Sind aktuell alle an?
        bool allAreChecked = true;
        for (int i = 0; i < topLevelItemCount(); ++i) {
            if (topLevelItem(i)->checkState(0) == Qt::Unchecked) {
                allAreChecked = false;
                break;
            }
        }

        // Wenn alle an sind -> Alle aus.
        // Wenn auch nur einer aus ist -> Alle an.
        setAllChecked(!allAreChecked);
    }
}
//// end private slots
}
#endif
