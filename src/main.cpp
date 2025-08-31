#include "sivalwindow.hpp"

#include <QApplication>
#include "speakersettingsdocument.hpp"

// Korrigierter logischer Ablauf der Entwicklung

// GUI und Grundlayout: Beginnen Sie mit der visuellen Oberfläche.

// Datenverwaltung der Lautsprecher: Implementieren Sie die Logik, um die Lautsprecherdaten zu laden. Dazu gehört das Einlesen der Haupt-Indexdatei und die Funktion, einzelne, vollständige Lautsprecherdateien bei Bedarf zu laden.

// Projektstruktur und -verwaltung: Nachdem die Lautsprecherdaten geladen und zugänglich sind, können Sie die Struktur für das Projektobjekt definieren und die Funktionen zum Speichern, Laden und Verwalten von Projekten implementieren.

// Import-Funktion: Erstellen Sie die Funktion zum Importieren neuer Lautsprecherdaten. Sie wird neue Dateien im korrekten Format erstellen und die Haupt-Indexdatei aktualisieren.

// Anzeige der Graphen: Visualisieren Sie die Daten. Dies ist der letzte Schritt, da er auf den erfolgreich geladenen Projektdaten und Lautsprecherparametern aufbaut.

int main(int argc, char *argv[])
{
    QString project;
    SpeakerSettingsDocument *doc = new SpeakerSettingsDocument("speaker_overview.json");
    QApplication a(argc, argv);
    SiVALWindow w(project, doc);
    w.show();
    return a.exec();
}
