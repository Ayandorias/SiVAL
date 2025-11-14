# CMake Mindestversion und Projektname
cmake_minimum_required(VERSION 3.16)
project(SiVAL_Suite)

# C++ Standard setzen (optional, aber gute Praxis)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 6 (oder 5) finden.
# Dies ist notwendig, damit die Einstellungen an die Unterprojekte
# weitergegeben werden können.
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# Automatische Qt-Magie für die Unterprojekte aktivieren
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- Sub-Projekte ---
# Reihenfolge ist wichtig:
# Bibliotheken müssen ZUERST geladen werden.

# 1. Die neue GUI-Bibliothek
add_subdirectory(sival-core)
add_subdirectory(sival-gui)
add_subdirectory(sival-ressource)


# 2. Die Anwendung, die die Bibliothek nutzt
# add_subdirectory(sival-enclosure)
add_subdirectory(sival)
