cmake_minimum_required(VERSION 3.20)

project(sival-gui LANGUAGES CXX)

# =========================================================
#  GRUNDEINSTELLUNGEN
# =========================================================
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================================================
#  QT BASIS
# =========================================================
# Da das Hauptprojekt (SiVAL-Suite) Qt bereits sucht, können wir hier
# direkt auf die Targets zugreifen. Zur Sicherheit für IDEs belassen
# wir den Lookup, reduzieren ihn aber auf das Nötige.
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

# =========================================================
#  QUELLCODE (SHARED LIBRARY)
# =========================================================
add_library(sival-gui SHARED
    include/sivalgui/global.hpp

    include/sivalgui/mainwindow.hpp src/mainwindow.cpp
    include/sivalgui/framebar.hpp src/framebar.cpp
    include/sivalgui/framebarbutton.hpp src/framebarbutton.cpp
    include/sivalgui/navigationbutton.hpp src/navigationbutton.cpp
    include/sivalgui/navigationwidget.hpp src/navigationwidget.cpp
    include/sivalgui/navigationpanel.hpp src/navigationpanel.cpp
    include/sivalgui/navigationbar.hpp src/navigationbar.cpp

    include/sivalgui/card.hpp src/card.cpp
    include/sivalgui/cardlist.hpp src/cardlist.cpp
    include/sivalgui/sectioncard.hpp src/sectioncard.cpp
    include/sivalgui/enclosurecard.hpp src/enclosurecard.cpp

    include/sivalgui/headerlabel.hpp src/headerlabel.cpp
    include/sivalgui/label.hpp src/label.cpp
    include/sivalgui/overlaydialog.hpp src/overlaydialog.cpp
    include/sivalgui/view.hpp src/view.cpp
    include/sivalgui/diagramm.hpp src/diagramm.cpp
    include/sivalgui/startitembig.hpp src/startitembig.cpp
    include/sivalgui/section.hpp src/section.cpp
    include/sivalgui/spinwidget.hpp src/spinwidget.cpp
    include/sivalgui/line.hpp src/line.cpp
    include/sivalgui/selectiontree.hpp src/selectiontree.cpp
    include/sivalgui/toolbutton.hpp src/toolbutton.cpp
    include/sivalgui/filesystempanel.hpp src/filesystempanel.cpp
    include/sivalgui/filelistview.hpp src/filelistview.cpp
    include/sivalgui/filesystemcard.hpp src/filesystemcard.cpp
)

# Alias für saubere Referenzierung
add_library(SiVAL::Gui ALIAS sival-gui)

# =========================================================
#  INCLUDES
# =========================================================
target_include_directories(sival-gui
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# =========================================================
#  LINKING
# =========================================================
target_link_libraries(sival-gui
    PUBLIC
    # Interne Module
    sival-core        # Bringt Logik & libSiVAL mit
    sival-ressource   # Bringt Icons & Themes mit

    # Qt Module (Grafik-spezifisch)
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Svg
    Qt6::Charts
)

# =========================================================
#  DEFINITIONS
# =========================================================
# Steuert Q_DECL_EXPORT in include/sivalgui/global.hpp
target_compile_definitions(sival-gui PRIVATE SIVAL_GUI_LIBRARY)



















# cmake_minimum_required(VERSION 3.16)

# project(sival-gui LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg Charts)
# find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

# add_library(sival-gui SHARED
#     include/sivalgui/global.hpp

#     include/sivalgui/framebar.hpp src/framebar.cpp

#     include/sivalgui/mainwindow.hpp src/mainwindow.cpp

#     include/sivalgui/framebarbutton.hpp src/framebarbutton.cpp
#     include/sivalgui/navigationbutton.hpp src/navigationbutton.cpp





#     include/sivalgui/card.hpp src/card.cpp


#     include/sivalgui/headerlabel.hpp src/headerlabel.cpp
#     include/sivalgui/label.hpp src/label.cpp
#     include/sivalgui/navigationwidget.hpp src/navigationwidget.cpp
#     include/sivalgui/overlaydialog.hpp src/overlaydialog.cpp

#   include/sivalgui/view.hpp src/view.cpp
#   include/sivalgui/navigationbar.hpp src/navigationbar.cpp
#   include/sivalgui/cardlist.hpp src/cardlist.cpp
#   include/sivalgui/navigationpanel.hpp src/navigationpanel.cpp
#   include/sivalgui/diagramm.hpp src/diagramm.cpp
#   include/sivalgui/startitembig.hpp src/startitembig.cpp
#   include/sivalgui/section.hpp src/section.cpp
#   include/sivalgui/sectioncard.hpp src/sectioncard.cpp
#   include/sivalgui/spinwidget.hpp src/spinwidget.cpp
#   include/sivalgui/line.hpp src/line.cpp
#   include/sivalgui/selectiontree.hpp src/selectiontree.cpp
#   include/sivalgui/toolbutton.hpp src/toolbutton.cpp
#   include/sivalgui/enclosurecard.hpp src/enclosurecard.cpp
# )

# # target_include_directories(sival-gui PRIVATE include)
# # Hier wird deklariert, welche Verzeichnisse beim Linken
# # automatisch als Include-Pfade hinzugefügt werden sollen.
# target_include_directories(sival-gui
#     PUBLIC
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#         $<INSTALL_INTERFACE:include> # Für eine spätere Installation
# )

# # target_link_libraries(sival-gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# # Linken gegen die benötigten Qt-Module
# target_link_libraries(sival-gui
#     PUBLIC
#     Qt6::Widgets
#     Qt6::Gui
#     Qt6::Core
#     Qt6::Svg
#     Qt6::Charts
#     sival-ressource
#     sival-core
# )
# target_link_libraries(sival-gui PRIVATE Qt${QT_VERSION_MAJOR}::Core)

# target_compile_definitions(sival-gui PRIVATE SIVAL_GUI_LIBRARY)
