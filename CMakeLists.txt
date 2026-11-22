cmake_minimum_required(VERSION 3.16)

project(QTQMLAPP2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

# Content of downloaded design from Figma to Qt or similar
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/importedcontent/CMakeLists.txt")
    add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/importedcontent)
endif()

qt_add_executable(appQTQMLAPP2
    main.cpp
)

qt_add_qml_module(appQTQMLAPP2
    URI QTQMLAPP2
    QML_FILES
        Main.qml
        SOURCES firefox.h firefox.cpp
        SOURCES
        SOURCES userinteractor.h userinteractor.cpp
        SOURCES internetexplorer.h internetexplorer.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQTQMLAPP2 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQTQMLAPP2
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(appQTQMLAPP2
    PRIVATE Qt6::Quick
)

install(TARGETS appQTQMLAPP2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
