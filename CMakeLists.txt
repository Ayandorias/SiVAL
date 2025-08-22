cmake_minimum_required(VERSION 3.19)
project(SiVAL LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Svg)

qt_standard_project_setup()

qt_add_executable(SiVAL
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui
    include/mainwindow.hpp
    include/nw/assistant.hpp include/nw/button.hpp include/nw/card.hpp include/nw/counter.hpp include/nw/date.hpp include/nw/frame.hpp include/nw/framebar.hpp include/nw/framebarbutton.hpp include/nw/headerlabel.hpp include/nw/label.hpp include/nw/mainwindow.hpp include/nw/navbarbutton.hpp include/nw/navbarpanel.hpp include/nw/overlaydialog.hpp include/nw/selectionbar.hpp include/nw/selectionbutton.hpp include/nw/skilllabel.hpp include/nw/style.hpp include/nw/styleselectionbutton.hpp include/nw/titlebar.hpp include/nw/toolbutton.hpp
    src/nw/assistant.cpp src/nw/assistant.ui src/nw/button.cpp src/nw/card.cpp src/nw/counter.cpp src/nw/date.cpp src/nw/frame.cpp src/nw/framebar.cpp src/nw/framebarbutton.cpp src/nw/headerlabel.cpp src/nw/label.cpp src/nw/mainwindow.cpp src/nw/navbarbutton.cpp src/nw/navbarpanel.cpp src/nw/overlaydialog.cpp src/nw/overlaydialog.ui src/nw/selectionbar.cpp src/nw/selectionbutton.cpp src/nw/skilllabel.cpp src/nw/style.cpp src/nw/styleselectionbutton.cpp src/nw/titlebar.cpp src/nw/toolbutton.cpp
    include/aadefines.hpp
    resource/nw.qrc

)

target_include_directories(SiVAL PRIVATE include)

target_link_libraries(SiVAL
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt6::Svg
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
