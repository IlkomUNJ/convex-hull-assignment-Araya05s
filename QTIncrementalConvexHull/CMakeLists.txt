cmake_minimum_required(VERSION 3.19)
project(QTIncrementalConvexHull LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(QTIncrementalConvexHull
    WIN32 MACOSX_BUNDLE
    main.cpp
    drawingcanvas.cpp
    drawingcanvas.h
    drawingwindow.ui
    drawingwindow.h
    drawingwindow.cpp
    linewidget.h
    linewidget.cpp
)


target_link_libraries(QTIncrementalConvexHull
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS QTIncrementalConvexHull
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET QTIncrementalConvexHull
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
