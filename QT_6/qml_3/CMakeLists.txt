cmake_minimum_required(VERSION 3.16)

project(qml_3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(Qt6 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_add_executable(appqml_3
    main.cpp
)

qt_add_qml_module(appqml_3
    URI qml_3
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appqml_3 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appqml_3
    PRIVATE Qt6::Quick  Qt6::QuickControls2 )

install(TARGETS appqml_3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
