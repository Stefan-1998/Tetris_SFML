cmake_minimum_required(VERSION 3.10 )

project(SFML CXX)


#include_directories(lib)
#add_subdirectory(src)


add_executable(SFML main/main.cpp)

target_link_libraries(SFML PUBLIC 
   sfml-window
   sfml-system
   sfml-graphics
    #sfml-audio
    #sfml-app

    #"${PROJECT_SOURCE_DIR}/lib"
    #"${PROJECT_SOURCE_DIR}/src"
    #src
    )
target_include_directories(SFML PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
    )
