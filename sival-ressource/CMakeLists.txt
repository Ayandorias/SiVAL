# cmake_minimum_required(VERSION 3.16)

# project(sival-ressource LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# add_library(sival-ressource SHARED



# )

# target_link_libraries(sival-ressource PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# target_compile_definitions(sival-ressource PRIVATE SIVAL_RESSOURCE_LIBRARY)


# (AUTORCC muss im Hauptprojekt aktiviert sein)

# Eine statische Bibliothek nur für die Ressourcen
add_library(sival-ressource SHARED
    sival-ressource.qrc
    light_theme.qss
    light_theme.qss
    themes.qrc
)

# Ressourcen brauchen Qt::Core
target_link_libraries(sival-ressource PUBLIC
    Qt::Core
)
