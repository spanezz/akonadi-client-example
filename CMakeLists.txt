cmake_minimum_required(VERSION 3.0)

project(example)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Qt4 REQUIRED)

find_package(KDE4 REQUIRED)
include (KDE4Defaults)

find_package(KdepimLibs 4.14.1)
find_package(Akonadi 1.12.90 QUIET CONFIG)

# Akonadi currently needs this, since tag.h #includes <KUrl> and not <KDE/KUrl>
include_directories(${KDE4_INCLUDES})

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

qt4_wrap_ui(UI_HEADERS example.ui)
# qt4_add_resources(UI_RESOURCES example.qrc)

add_executable(zavai
   akonadical.h akonadical.cpp
   example.h example.cpp
   main.cpp
   ${UI_HEADERS}
   # ${UI_RESOURCES}
)

target_link_libraries(zavai
    ${QT_LIBRARIES}
    ${KDEPIMLIBS_AKONADI_LIBS}
)
