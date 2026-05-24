cmake_minimum_required(VERSION 3.19)
project(chess LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(chess
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    piece.h piece.cpp
    board.h board.cpp
    mymath.h
    gamemanager.h gamemanager.cpp

)

target_link_libraries(chess
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_include_directories(chess PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS chess
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET chess
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
