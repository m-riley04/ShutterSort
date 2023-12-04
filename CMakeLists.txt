cmake_minimum_required(VERSION 3.5)
set(CMAKE_TOOLCHAIN_FILE C:/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(ShutterSort VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

#-- Libraries
include_directories(C:/vcpkg/installed/x64-windows/include)
link_directories(C:/vcpkg/installed/x64-windows/lib)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        src/anchor.cpp
        src/anchor.h
        src/application.cpp
        src/application.h
        src/LocalImage.cpp
        src/LocalImage.h
        src/metadata.cpp
        src/metadata.h
        src/Sorter.cpp
        src/Sorter.h
        src/sortingmethod.cpp
        src/sortingmethod.h
        src/sorttimer.cpp
        src/sorttimer.h
        src/timer.cpp
        src/timer.h
        src/sortingfunctions.cpp
        src/sortingfunctions.h
        src/sortingmethod_qt.h
        src/sortingmethod_qt.cpp
        src/sortingmethod_qt.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ShutterSort
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        vcpkg.json
        src/stylesheet.qss
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ShutterSort APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ShutterSort SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ShutterSort
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ShutterSort
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        exiv2.lib
        inih.lib
        INIReader.lib
        libpng16.lib
        zlib.lib)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ShutterSort)
endif()
set_target_properties(ShutterSort PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ShutterSort
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ShutterSort)
endif()
