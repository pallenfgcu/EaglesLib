cmake_minimum_required(VERSION 3.22)
project(EaglesLib)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    set(SFML_ROOT "../SFML-2.5.1")
    set(SFML_INCLUDE_DIR "../SFML-2.5.1/include")
    set(SFML_LIBRARY_DIR "../SFML-2.5.1/lib")
    set(SFML_STATIC_LIBRARIES TRUE)
elseif(APPLE)
    set (SFML_ROOT "/opt/homebrew/Cellar/sfml/2.5.1_1")
    set(CMAKE_MODULE_PATH "${SFML_ROOT}/lib/cmake/SFML")
    set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
    set(SFML_LIBRARY_DIR "${SFML_ROOT}/lib")
endif()

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib)

add_library(eagles src/Random.cpp
        src/Bounds.cpp
        src/AnimatedShape.cpp
        src/AnimatedRectangle.cpp
        src/AnimatedCircle.cpp
        src/AnimatedTriangle.cpp
        src/AnimatedWindow.cpp)

configure_file(resources/RobotoMono-Regular.ttf RobotoMono-Regular.ttf COPYONLY)


if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_ROOT}/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
