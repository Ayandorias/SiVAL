cmake_minimum_required(VERSION 3.16)

project(sival-core LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg Charts)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

add_library(sival-core SHARED
    include/sivalcore/core_global.hpp
    include/sivalcore/abstractions/abstractdocument.hpp src/abstractions/abstractdocument.cpp
    include/sivalcore/documents/projectdocument.hpp src/documents/projectdocument.cpp
    include/sivalcore/documents/workspacedocument.hpp src/documents/workspacedocument.cpp
    include/sivalcore/abstractions/abstractiohandler.hpp src/abstractions/abstractiohandler.cpp
    include/sivalcore/io/settingsiohandler.hpp src/io/settingsiohandler.cpp
    include/sivalcore/io/settingsjsonhandler.hpp src/io/settingsjsonhandler.cpp
)

# target_include_directories(sival-core PRIVATE include)
# Hier wird deklariert, welche Verzeichnisse beim Linken
# automatisch als Include-Pfade hinzugefügt werden sollen.
target_include_directories(sival-core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include> # Für eine spätere Installation
)

# target_link_libraries(sival-core PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
# Linken gegen die benötigten Qt-Module
target_link_libraries(sival-core
    PUBLIC
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::Svg
    Qt6::Charts
)

target_compile_definitions(sival-core PRIVATE SIVAL_GUI_LIBRARY)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()
