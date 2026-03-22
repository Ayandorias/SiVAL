cmake_minimum_required(VERSION 3.20)

project(sival-core LANGUAGES CXX)

# =========================================================
#  GRUNDEINSTELLUNGEN
# =========================================================
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================================================
#  QT ABHÄNGIGKEITEN
# =========================================================
# QtJson ist Teil von QtCore, daher ist keine externe JSON-Lib nötig.
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

# Standard-Include für generierte Dateien
include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")

# =========================================================
#  QUELLCODE DEFINITION (SHARED LIBRARY)
# =========================================================
add_library(sival-core SHARED
    include/sivalcore/core_global.hpp
    include/sivalcore/abstractions/abstractdocument.hpp src/abstractions/abstractdocument.cpp
    include/sivalcore/documents/projectdocument.hpp src/documents/projectdocument.cpp
    include/sivalcore/documents/settingsdocument.hpp src/documents/settingsdocument.cpp
    include/sivalcore/documents/workspacedocument.hpp src/documents/workspacedocument.cpp
    include/sivalcore/abstractions/abstractiohandler.hpp src/abstractions/abstractiohandler.cpp

    include/sivalcore/sivalglobal.hpp
    include/sivalcore/settings/general.hpp src/settings/general.cpp
    include/sivalcore/settings/project.hpp src/settings/project.cpp
    include/sivalcore/settings/system.hpp src/settings/system.cpp
    include/sivalcore/io/fileiohandler.hpp src/io/fileiohandler.cpp
    include/sivalcore/io/settingsiohandler.hpp src/io/settingsiohandler.cpp

    include/sivalcore/documents/drivercatalog.hpp src/documents/drivercatalog.cpp
    include/sivalcore/generic/chassismanufacturer.hpp src/generic/chassismanufacturer.cpp
    include/sivalcore/settings/lastprojectlist.hpp src/settings/lastprojectlist.cpp
    include/sivalcore/documents/speakerdocument.hpp src/documents/speakerdocument.cpp
)

# Alias für interne Nutzung
add_library(SiVAL::Core ALIAS sival-core)

# =========================================================
#  LINKING & ABHÄNGIGKEITEN
# =========================================================
target_link_libraries(sival-core
    PUBLIC
    # Die externe Basis-Bibliothek (wie im ursprünglichen Plan gefordert)
    libSiVAL

    # Qt Module
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core    # Enthält QJsonDocument etc.
    Qt6::Svg
    Qt6::Charts
)

# =========================================================
#  INCLUDES
# =========================================================
target_include_directories(sival-core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# =========================================================
#  PRECOMPILED HEADERS
# =========================================================
# Optimierung der Kompilierzeit
target_precompile_headers(sival-core PUBLIC include/sivalcore/sivalglobal.hpp)

# =========================================================
#  COMPILER DEFINITIONS
# =========================================================
# Definiert SIVAL_CORE_LIBRARY für den korrekten DLL-Export (Q_DECL_EXPORT)
target_compile_definitions(sival-core PRIVATE SIVAL_CORE_LIBRARY)







# cmake_minimum_required(VERSION 3.19)
# project(sival-core LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# # 1. KONSISTENZ: Nutze genau wie in den anderen Projekten direkt Qt6
# find_package(Qt6 REQUIRED COMPONENTS Core Widgets Svg Charts LinguistTools)

# include_directories("${CMAKE_CURRENT_BINARY_DIR}/include")

# # 2. BIBLIOTHEK DEFINIEREN
# add_library(sival-core SHARED
#     include/sivalcore/core_global.hpp
#     include/sivalcore/abstractions/abstractdocument.hpp src/abstractions/abstractdocument.cpp
#     include/sivalcore/documents/projectdocument.hpp src/documents/projectdocument.cpp
#     include/sivalcore/documents/settingsdocument.hpp src/documents/settingsdocument.cpp
#     include/sivalcore/documents/workspacedocument.hpp src/documents/workspacedocument.cpp
#     include/sivalcore/abstractions/abstractiohandler.hpp src/abstractions/abstractiohandler.cpp

#     include/sivalcore/sivalglobal.hpp
#     include/sivalcore/settings/general.hpp src/settings/general.cpp
#     include/sivalcore/settings/project.hpp src/settings/project.cpp
#     include/sivalcore/settings/system.hpp src/settings/system.cpp
#     include/sivalcore/io/fileiohandler.hpp src/io/fileiohandler.cpp
#     include/sivalcore/io/settingsiohandler.hpp src/io/settingsiohandler.cpp

#     include/sivalcore/documents/speakerdocument.hpp src/documents/speakerdocument.cpp
#     include/sivalcore/generic/chassismanufacturer.hpp src/generic/chassismanufacturer.cpp
#     include/sivalcore/settings/lastprojectlist.hpp src/settings/lastprojectlist.cpp
# )

# # 3. VERBINDUNGEN (MUSS VOR PCH PASSIEREN!)
# # Damit erbt sival-core die Include-Pfade von libSiVAL
# target_link_libraries(sival-core
#     PUBLIC
#     libSiVAL          # Hierarchisch wichtigste Abhängigkeit
#     Qt6::Widgets
#     Qt6::Gui
#     Qt6::Core
#     Qt6::Svg
#     Qt6::Charts
# )

# # 4. INCLUDES SETZEN
# target_include_directories(sival-core
#     PUBLIC
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#         $<INSTALL_INTERFACE:include>
# )

# # 5. PCH (JETZT SICHER)
# # Jetzt sind die Include-Pfade von libSiVAL bekannt, falls sivalglobal.hpp sie braucht.
# target_precompile_headers(sival-core PUBLIC include/sivalcore/sivalglobal.hpp)

# target_compile_definitions(sival-core PRIVATE SIVAL_GUI_LIBRARY)
