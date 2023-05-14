cmake_minimum_required(VERSION 3.23)
project(PalanoChatUtenti)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES User.cpp User.h UserRegistry.cpp UserRegistry.h)
add_executable(PalanoChatUtenti main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(PalanoChatUtenti core)