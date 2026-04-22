cmake_minimum_required(VERSION 3.19)
project(1xiangmu LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Qml Multimedia MultimediaWidgets Network Multimedia)

qt_standard_project_setup()

qt_add_executable(1xiangmu
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui
    dingshi.h dingshi.cpp dingshi.ui
    jisuan.h jisuan.cpp jisuan.ui
    fanyi.h fanyi.cpp fanyi.ui
    tianqi.h tianqi.cpp tianqi.ui
    pro.qrc









)

target_link_libraries(1xiangmu
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Qml
        Qt6::Multimedia
        Qt6::MultimediaWidgets
        Qt::Network
        Qt::Multimedia

)

include(GNUInstallDirs)

install(TARGETS 1xiangmu
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET 1xiangmu
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})

























