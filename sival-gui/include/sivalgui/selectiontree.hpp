#pragma once

#include <QTreeWidget>
#include <QHeaderView>
#include <QCheckBox>

namespace SiVAL::Gui {

// =============================================================================
// Klasse: CheckBoxHeader
// Beschreibung: Ein spezialisierter Header, der eine echte QCheckBox in der
//               ersten Spalte als Kind-Widget enthält.
// =============================================================================
class CheckBoxHeader : public QHeaderView
{
    Q_OBJECT

public:
    explicit CheckBoxHeader(Qt::Orientation orientation, QWidget *parent = nullptr);

    // Zugriff auf die eingebettete Checkbox (für Verbindungen)
    QCheckBox* checkBox() const { return m_checkBox; }

protected:
    // Diese Ereignisse nutzen wir, um die Checkbox neu zu positionieren,
    // wenn sich die Größe des Headers ändert.
    void showEvent(QShowEvent *e) override;
    void resizeEvent(QResizeEvent *e) override;

private slots:
    // Berechnet die Mitte der ersten Spalte und bewegt die Checkbox dorthin
    void updateCheckBoxPosition();

private:
    QCheckBox *m_checkBox;
};


// =============================================================================
// Klasse: ChassisSelectTree
// Beschreibung: Die Baumansicht zur Auswahl der Chassis mit Checkbox-Logik.
// =============================================================================
class SelectionTree : public QTreeWidget
{
    Q_OBJECT

public:
    explicit SelectionTree(QWidget *parent = nullptr);
    virtual ~SelectionTree() = default;

    // Fügt eine Zeile hinzu: Checkbox | Hersteller | Anzahl
    void addChassisEntry(const QString& manufacturer, int count, bool checked = false);

    // Liefert die ausgewählten Hersteller
    QStringList getSelectedManufacturers() const;

    // Setzt den Haken bei allen Einträgen (und aktualisiert den Header visuell)
    void setAllChecked(bool checked);

protected:
    // Erweiterte Klick-Zone für die Zellen in Spalte 0 (nicht nur auf den Haken)
    void mouseReleaseEvent(QMouseEvent *event) override;

private slots:
    // Slot, wenn der Benutzer auf die Header-Checkbox klickt
    void onHeaderCheckToggled(bool checked);

    // Slot, um zu prüfen, ob der Header-Status noch mit den Zeilen übereinstimmt
    // (wird gerufen, wenn eine Zeile geändert wurde)
    void updateHeaderState();
};

} // namespace SiVAL::GUI




#if 0

#pragma once

/*
 * SiVAL GUI
 *
 * Copyright (C) since 2025 Bruno Pierucki
 *
 * Author: Bruno Pierucki <b.pierucki@gmx.de>
 *
 */
//// begin system includes
#include <QTreeWidget>
#include <QHeaderView>
//// end system includes

//// begin project specific includes

//// end project specific includes

//// begin using namespaces
//// end using namespaces

//// begin global definition
//// end global definition

//// begin forward declarations
//// end forward declarations

//// begin extern declaration
//// end extern declaration

namespace SiVAL::Gui {
/**
 * class SelectionTree
 *
 * @brief
 *
 */
class SelectionTree : public QTreeWidget
{
    Q_OBJECT
    //// begin public member methods
public:
    /// Constructor
    explicit SelectionTree(QWidget *parent = nullptr);
    /// Destructor
    virtual ~SelectionTree();
    void addChassisEntry(const QString& manufacturer, int count, bool checked = false);
    void setAllChecked(bool checked);
    //// end public member methods

    //// begin public member methods (internal use only)
public:
    //// end public member methods (internal use only)

    //// begin protected member methods
protected:
    //// end protected member methods

    //// begin protected member methods (internal use only)
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
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
    //// end private member

    //// begin public slots
public slots:
    //// end public slots

    //// begin protected slots
protected slots:
    //// end protected slots

    //// begin private slots
private slots:
    void onHeaderClicked(int section);
    //// end private slots

    //// begin signals
signals:
    //// end signals
};
}


#endif
