cmake_minimum_required(VERSION 3.19)
project(SiVAL LANGUAGES CXX)

# Standard C++-Standard setzen
# Entspricht CONFIG += c++17
set(CMAKE_CXX_STANDARD 17)
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

qt_add_executable(SiVAL
    WIN32 MACOSX_BUNDLE

    # Nebenwelten Deklarations Dateien.
    # Überprüfen, welche tatsächlich genutzt werden.
    include/nw/assistant.hpp
    include/nw/button.hpp
    include/nw/card.hpp
    include/nw/counter.hpp
    include/nw/date.hpp
    include/nw/frame.hpp
    include/nw/framebar.hpp
    include/nw/framebarbutton.hpp
    include/nw/headerlabel.hpp
    include/nw/label.hpp
    include/nw/mainwindow.hpp
    include/nw/navbarbutton.hpp
    include/nw/navbarpanel.hpp
    include/nw/overlaydialog.hpp
    include/nw/selectionbar.hpp
    include/nw/selectionbutton.hpp
    include/nw/skilllabel.hpp
    include/nw/style.hpp
    include/nw/styleselectionbutton.hpp
    include/nw/titlebar.hpp
    include/nw/toolbutton.hpp

    # Nebenwelten Definitions Dateien.
    # Überprüfen, welche tatsächlich genutzt werden.
    src/nw/assistant.cpp
    src/nw/assistant.ui
    src/nw/button.cpp
    src/nw/card.cpp
    src/nw/counter.cpp
    src/nw/date.cpp
    src/nw/frame.cpp
    src/nw/framebar.cpp
    src/nw/framebarbutton.cpp
    src/nw/headerlabel.cpp
    src/nw/label.cpp
    src/nw/mainwindow.cpp
    src/nw/navbarbutton.cpp
    src/nw/navbarpanel.cpp
    src/nw/overlaydialog.cpp
    src/nw/overlaydialog.ui
    src/nw/selectionbar.cpp
    src/nw/selectionbutton.cpp
    src/nw/skilllabel.cpp
    src/nw/style.cpp
    src/nw/styleselectionbutton.cpp
    src/nw/titlebar.cpp
    src/nw/toolbutton.cpp

    #Deklarations Dateien
    include/aadefines.hpp
    include/centerstack.hpp
    include/enclosurewidget.hpp
    include/homepanel.hpp
    include/idocument.hpp
    include/projectpanel.hpp
    include/sivalwindow.hpp
    include/speakerparameter.hpp
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
    src/idocument.cpp
    src/projectpanel.ui
    src/sivalwindow.ui
    src/speakerparameter.cpp
    src/speakersettingsmenu.ui
    src/speakersettingspage.ui
    src/speakersettingswidget.ui

    # Ressource Dateien
    resource/nw.qrc
    resource/sival.qrc
    include/manufacturerdocument.hpp src/manufacturerdocument.cpp
    include/projectdocument.hpp src/projectdocument.cpp
    include/settingsdocument.hpp src/settingsdocument.cpp
    include/speakermanufacturer.hpp src/speakermanufacturer.cpp
    include/speakermanufacturercard.hpp src/speakermanufacturercard.cpp
    include/headerlabel.hpp src/headerlabel.cpp
    include/projecttreewidget.hpp src/projecttreewidget.cpp
    include/speakerdocument.hpp src/speakerdocument.cpp
    include/ienclosure.hpp src/ienclosure.cpp
    include/ventedenclosure.hpp src/ventedenclosure.cpp
    include/sealedenclosure.hpp src/sealedenclosure.cpp
    include/sival.hpp
    include/enclosuredocument.hpp src/enclosuredocument.cpp
    include/homewidget.hpp src/homewidget.cpp src/homewidget.ui
    include/projectnewdialog.hpp src/projectnewdialog.cpp src/projectnewdialog.ui
    include/enclosurenewdialog.hpp src/enclosurenewdialog.cpp src/enclosurenewdialog.ui
    include/speakerbrandcard.hpp src/speakerbrandcard.cpp
    include/treeitem.hpp src/treeitem.cpp
    include/nw/pushbutton.hpp src/nw/pushbutton.cpp
    include/projectmenu.hpp src/projectmenu.cpp src/projectmenu.ui


)

target_include_directories(SiVAL PRIVATE include)

target_link_libraries(SiVAL
    PRIVATE
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Svg
    Qt6::Charts
)

include(GNUInstallDirs)

install(TARGETS SiVAL
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SiVAL
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
