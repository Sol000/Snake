<h1>A simple snake game [C++/SFML] </h1>

this game was created with the SFML Graphics library. It is easy to install, runn the following code in the shell 
<code>sudo apt-get install libsfml-dev</code>

To compile this you have to install Cmake and create a CMakeLists.txt-File in the on top of the project tree with the following code in it:
<code>
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_STATIC_LIB TRUE)

find_package(SFML 2 COMPONENTS graphics REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Snake main.cpp ${SRC_FILES})

target_include_directories(Snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Snake sfml-graphics)
</code>
