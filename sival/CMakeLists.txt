cmake_minimum_required(VERSION 3.19)
project(sival LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg)

qt_standard_project_setup()


# --- 1. Versions-Definition ---
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
set(SIVAL_BUILD_STATUS "Alpha") # Alpha, Beta, Release

# --- 2. Git Informationen holen (für Revision & Build Count) ---
find_package(Git)
if(GIT_FOUND)
    # Hash holen (kurz)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE SIVAL_GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    # Anzahl der Commits als "Build Number" nutzen
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-list --count HEAD
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE SIVAL_BUILD_COUNT
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
else()
    set(SIVAL_GIT_HASH "unknown")
    set(SIVAL_BUILD_COUNT "0")
endif()

# --- 3. Zeitstempel holen ---
string(TIMESTAMP SIVAL_BUILD_DATE "%d.%m.%Y")
string(TIMESTAMP SIVAL_BUILD_TIME "%H:%M:%S")

# --- 4. Datei generieren ---
# Nimmt "version.hpp.in", ersetzt die Variablen und speichert "version.hpp"
# im Build-Ordner (nicht im Quell-Ordner, um diesen sauber zu halten).
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.hpp.in"
    "${CMAKE_CURRENT_BINARY_DIR}/include/version.hpp"
    @ONLY
)

# WICHTIG: Den Ordner mit der generierten Datei dem Include-Path hinzufügen
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")


qt_add_executable(sival
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    include/mainwindow.hpp  src/mainwindow.cpp
    include/startview.hpp src/startview.cpp
    include/startpanel.hpp src/startpanel.cpp
    include/startitem.hpp src/startitem.cpp
    include/settingsview.hpp src/settingsview.cpp
    include/helpview.hpp src/helpview.cpp
    include/projectview.hpp src/projectview.cpp
    include/sival.hpp
    include/settingspanel.hpp src/settingspanel.cpp
    include/settingsgeneral.hpp src/settingsgeneral.cpp
    include/settingsabout.hpp src/settingsabout.cpp
    include/settingsspeaker.hpp src/settingsspeaker.cpp
)

target_include_directories(sival-gui
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include> # Für eine spätere Installation
)

target_link_libraries(sival
    PRIVATE
    sival-gui
    sival-core
        Qt::Core
        Qt::Widgets
        Qt::Svg
)

include(GNUInstallDirs)

install(TARGETS sival
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET sival
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
