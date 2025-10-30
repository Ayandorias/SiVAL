cmake_minimum_required(VERSION 3.16)

project(sival-gui LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg Charts)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

set(TS_FILES sival-gui_en_150.ts)

add_library(sival-gui SHARED
    include/sivalgui/gui_global.hpp
    include/sivalgui/sivalgui.hpp src/sivalgui.cpp
    include/sivalgui/framebar.hpp src/framebar.cpp
    include/sivalgui/titlebar.hpp src/titlebar.cpp
    include/sivalgui/mainwindow.hpp src/mainwindow.cpp
    include/sivalgui/toolbutton.hpp src/toolbutton.cpp
    include/sivalgui/framebarbutton.hpp src/framebarbutton.cpp
    include/sivalgui/navbarbutton.hpp src/navbarbutton.cpp


    include/sivalgui/defines.hpp
    include/sivalgui/assistant.hpp src/assistant.cpp src/assistant.ui
    include/sivalgui/button.hpp src/button.cpp
    include/sivalgui/card.hpp src/card.cpp
    include/sivalgui/counter.hpp src/counter.cpp
    include/sivalgui/frame.hpp src/frame.cpp
    include/sivalgui/headerlabel.hpp src/headerlabel.cpp
    include/sivalgui/label.hpp src/label.cpp
    include/sivalgui/navbarpanel.hpp src/navbarpanel.cpp
    include/sivalgui/overlaydialog.hpp src/overlaydialog.cpp src/overlaydialog.ui
    include/sivalgui/selectionbar.hpp src/selectionbar.cpp
    include/sivalgui/selectionbutton.hpp src/selectionbutton.cpp
    include/sivalgui/skilllabel.hpp src/skilllabel.cpp
    include/sivalgui/style.hpp src/style.cpp
    include/sivalgui/styleselectionbutton.hpp src/styleselectionbutton.cpp
    include/sivalgui/pushbutton.hpp src/pushbutton.cpp


  ${TS_FILES}
)

# target_include_directories(sival-gui PRIVATE include)
# Hier wird deklariert, welche Verzeichnisse beim Linken
# automatisch als Include-Pfade hinzugefügt werden sollen.
target_include_directories(sival-gui
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include> # Für eine spätere Installation
)

# target_link_libraries(sival-gui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Linken gegen die benötigten Qt-Module
target_link_libraries(sival-gui
    PUBLIC
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Svg
    Qt6::Charts
)

target_compile_definitions(sival-gui PRIVATE SIVAL_GUI_LIBRARY)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()
