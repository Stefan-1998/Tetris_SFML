cmake_minimum_required(VERSION 3.10 )

project(Tetris CXX)


include_directories(lib)
add_subdirectory(src)


add_executable(Tetris main/main.cpp)

target_link_libraries(Tetris PUBLIC 
   sfml-window
   sfml-system
   sfml-graphics
    #sfml-audio
    #sfml-app

    #"${PROJECT_SOURCE_DIR}/lib"
    #"${PROJECT_SOURCE_DIR}/src"
    src
    
    #lib
    )
#target_link_directories(Tetris PUBLIC /src)

target_include_directories(Tetris PUBLIC 
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
    #"${PROJECT_SOURCE_DIR}/lib"
    lib
    #src
    )
