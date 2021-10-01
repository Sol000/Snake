#Chnge this if you need to target a specific CMake version
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_STATIC_LIB TRUE)

find_package(SFML 2 COMPONENTS graphics REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Snake main.cpp ${SRC_FILES})

target_include_directories(Snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Snake sfml-graphics)
