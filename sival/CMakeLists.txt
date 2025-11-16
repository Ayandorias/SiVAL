cmake_minimum_required(VERSION 3.19)
project(sival LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg)

qt_standard_project_setup()

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
)

target_include_directories(sival-gui
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include> # Für eine spätere Installation
)

target_link_libraries(sival
    PRIVATE
    sival-gui
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
