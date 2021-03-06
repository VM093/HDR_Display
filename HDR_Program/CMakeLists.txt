project(HDR_display)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

#find_package(Qt4 REQUIRED)
#SET(QT_USE_QTXML TRUE)
#include(${QT_USE_FILE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5Xml REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)

find_package(OpenGL REQUIRED)
find_package(Eigen3 "3.0.3" REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories( ${QT_INCLUDE_DIR} )
include_directories( ${EIGEN3_INCLUDE_DIR} )
include_directories( ${PROJECT_SOURCE_DIR}/src )
#include_directories( ${PROJECT_SOURCE_DIR}/lib3ds )

add_definitions(-DHDR_DIR="${PROJECT_SOURCE_DIR}")
add_definitions(-DEIGEN_DONT_ALIGN_STATICALLY)

# the list of source files
set(HDR_SRCS src/main.cpp src/DisplayManager.h src/DisplayManager.cpp
             src/DisplayDevice.h src/DisplayDevice.cpp src/HDRProcess.h
             src/HDRProcess.cpp src/FrontPanel.h src/FrontPanel.cpp
             src/BackPanel.h src/BackPanel.cpp src/ImageManager.h
             src/ImageManager.cpp src/Correction.h src/Correction.cpp
             src/Window.h src/Window.cpp src/GLRender.h src/GLRender.cpp
             src/ImageIO.h src/ImageIO.cpp src/Image.h src/Image.cpp
             src/Includes.h
              ${APPLE_WORKAROUND_SRCS})

#qt4_automoc(${sire_SRCS})

add_executable(HDR_displaying ${HDR_SRCS})

target_link_libraries(HDR_displaying
    Qt5::Widgets Qt5::Xml Qt5::OpenGL
#  ${QT_QTCORE_LIBRARY}    ${QT_QTGUI_LIBRARY}  ${QT_QTXML_LIBRARY}
#  ${QT_QTOPENGL_LIBRARY}
    ${OPENGL_LIBRARIES}
)

