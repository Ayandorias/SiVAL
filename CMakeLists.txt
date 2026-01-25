cmake_minimum_required(VERSION 3.20)

# 1. Projektdefinition
project(SiVAL-Suite VERSION 0.1.0 LANGUAGES CXX)

set(SUITE_BUILD_STATUS "Alpha")

# =========================================================
#  GLOBALE QT KONFIGURATION
# =========================================================

# Schritt 1: Suche nach Qt6. Wenn nicht gefunden, würde er hier abbrechen.
# Wir laden hier ALLE Komponenten, die irgendein Unterprojekt brauchen könnte.
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

# Schritt 2: Die eigentlichen Targets laden (nutzt die Version aus Schritt 1)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

# Schritt 3: Standard-Setup (Automoc etc.)
# Da wir Qt6 bevorzugen, nutzen wir diesen Befehl.
qt_standard_project_setup()

# =========================================================
#  VERSIONIERUNG
# =========================================================
find_package(Git)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE SUITE_GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-list --count HEAD
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        OUTPUT_VARIABLE SUITE_BUILD_COUNT
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
else()
    set(SUITE_GIT_HASH "unknown")
    set(SUITE_BUILD_COUNT "0")
endif()

# Fallback
if("${SUITE_GIT_HASH}" STREQUAL "")
    set(SUITE_GIT_HASH "unknown")
endif()
if("${SUITE_BUILD_COUNT}" STREQUAL "")
    set(SUITE_BUILD_COUNT "0")
endif()

string(TIMESTAMP SUITE_BUILD_DATE "%d.%m.%Y")
string(TIMESTAMP SUITE_BUILD_TIME "%H:%M:%S")

# GENERIERUNG
# Wir definieren den Pfad explizit im Binary-Dir (Build-Ordner)
set(SUITE_GENERATED_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/include")

# 1. Nutzung von CMAKE_CURRENT_SOURCE_DIR für Sicherheit beim Finden der Quelldatei
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.hpp.in"
    "${SUITE_GENERATED_INCLUDE_DIR}/sival/sival_version.hpp"
    @ONLY
)

# =========================================================
#  SETTINGS LIBRARY (Globaler Rucksack)
# =========================================================
add_library(SiVAL_Suite_Settings INTERFACE)

# cxx_std_23 ist sehr neu/aggressiv. Wenn deine anderen Projekte C++20 nutzen,
# reicht hier oft auch 20. Aber 23 ist gültig, wenn der Compiler es kann.
target_compile_features(SiVAL_Suite_Settings INTERFACE cxx_std_23)

# 2. Nutzung von BUILD_INTERFACE
# Das sagt: "Wer diese Lib linkt, bekommt diesen Include-Pfad,
# aber NUR solange wir uns im Build-Prozess befinden."
target_include_directories(SiVAL_Suite_Settings INTERFACE
    $<BUILD_INTERFACE:${SUITE_GENERATED_INCLUDE_DIR}>
)

# =========================================================
#  UNTERMODULE
# =========================================================

# 1. Ressourcen (Icons, Styles)
add_subdirectory(sival-ressource)

# 2. Core (Logik)
add_subdirectory(sival-core)

# 3. GUI (Grafik - braucht Qt Charts & Svg)
add_subdirectory(sival-gui)

# 4. App (Executable)
add_subdirectory(sival-project)




# # CMake Mindestversion und Projektname
# cmake_minimum_required(VERSION 3.16)
# project(SiVAL_Suite)

# # C++ Standard setzen (optional, aber gute Praxis)
# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # Qt 6 (oder 5) finden.
# # Dies ist notwendig, damit die Einstellungen an die Unterprojekte
# # weitergegeben werden können.
# find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

# # Automatische Qt-Magie für die Unterprojekte aktivieren
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)

# # --- Sub-Projekte ---
# # Reihenfolge ist wichtig:
# # Bibliotheken müssen ZUERST geladen werden.

# # 1. Die neue GUI-Bibliothek
# add_subdirectory(sival-core)
# add_subdirectory(sival-gui)
# add_subdirectory(sival-ressource)


# # 2. Die Anwendung, die die Bibliothek nutzt
# # add_subdirectory(sival-enclosure)
# add_subdirectory(sival-project)


