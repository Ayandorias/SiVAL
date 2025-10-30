cmake_minimum_required(VERSION 3.19)
# Der Projektname wurde zu sival-enclosure geändert
project(sival-enclosure LANGUAGES CXX)

# Standard C++-Standard setzen
# Entspricht CONFIG += c++17
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt-Automatisierungen für UI-Dateien, Ressourcen und MOC aktivieren
# MOC: Meta-Object Compiler, für Q_OBJECT Makros
# UIC: UI Compiler, für .ui Dateien
# RCC: Resource Compiler, für .qrc Dateien
# TR: Translation (für .ts Dateien, in Qt6 bevorzugt gegenüber LinguistTools)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOTR ON) # Dies ist für die automatische Handhabung von .ts Dateien in Qt6

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg Charts)

qt_standard_project_setup()

# Der Name des Ziels (executable) wurde zu sival-enclosure geändert
qt_add_executable(sival-enclosure
    WIN32 MACOSX_BUNDLE

    #Deklarations Dateien
    include/centerstack.hpp
    include/enclosurewidget.hpp
    include/homepanel.hpp

    include/projectpanel.hpp
    include/sivalwindow.hpp

    include/speakersettingsmenu.hpp
    include/speakersettingspage.hpp
    include/speakersettingswidget.hpp

    # Definitions Dateien
    src/centerstack.cpp
    src/enclosurewidget.cpp
    src/homepanel.cpp
    src/main.cpp
    src/projectpanel.cpp
    src/sivalwindow.cpp
    src/speakersettingsmenu.cpp
    src/speakersettingspage.cpp
    src/speakersettingswidget.cpp

    # Forms Dateien
    src/enclosurewidget.ui
    src/homepanel.ui

    src/projectpanel.ui
    src/sivalwindow.ui

    src/speakersettingsmenu.ui
    src/speakersettingspage.ui
    src/speakersettingswidget.ui

    # Ressource Dateien
    resource/nw.qrc
    resource/sival.qrc




    include/speakermanufacturercard.hpp src/speakermanufacturercard.cpp
    include/headerlabel.hpp src/headerlabel.cpp
    include/projecttreewidget.hpp src/projecttreewidget.cpp




    include/sivalgui.hpp

    include/homewidget.hpp src/homewidget.cpp src/homewidget.ui
    include/projectnewdialog.hpp src/projectnewdialog.cpp src/projectnewdialog.ui
    include/enclosurenewdialog.hpp src/enclosurenewdialog.cpp src/enclosurenewdialog.ui
    include/speakerbrandcard.hpp src/speakerbrandcard.cpp
    include/treeitem.hpp src/treeitem.cpp
    include/projectmenu.hpp src/projectmenu.cpp src/projectmenu.ui
    include/enclosuremenu.hpp src/enclosuremenu.cpp src/enclosuremenu.ui


    include/chartview.hpp src/chartview.cpp
    include/infopage.hpp src/infopage.cpp src/infopage.ui
    include/recentprojectcard.hpp src/recentprojectcard.cpp
    include/recentprjpage.hpp src/recentprjpage.cpp src/recentprjpage.ui
)

# 1. Manuelle Definition des Pfades zur Bibliotheksdatei und zu den Headern
# DIESE PFADE MÜSSEN AN DIE LOKALEN GEGEBENHEITEN ANGEPASST WERDEN!
# set(LIBSIVAL_INCLUDE_DIR "../libsival")
# set(MYLIB_LIBRARY      "../libSiVAL.a") # Oder .lib, je nach System

# set(SIVAL_GUI_INCLUDE "../sival-gui/include")

# Der Zielname wurde hier ebenfalls geändert
target_include_directories(sival-enclosure PRIVATE include libsivalgui
    ${LIBSIVAL_INCLUDE_DIR}
    ${SIVAL_GUI_INCLUDE}
)

# Der Zielname wurde hier ebenfalls geändert
target_link_libraries(sival-enclosure
    PRIVATE
    sival-gui
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Svg
    Qt6::Charts
)

include(GNUInstallDirs)

# Der Zielname wurde hier ebenfalls geändert
install(TARGETS sival-enclosure
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Der Zielname wurde hier ebenfalls geändert
qt_generate_deploy_app_script(
    TARGET sival-enclosure
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
