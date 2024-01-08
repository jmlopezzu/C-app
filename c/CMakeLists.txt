cmake_minimum_required(VERSION 3.15)
project(MySDLApp C)

set(CMAKE_C_STANDARD 11)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add the include directory for SDL2
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(MySDLApp main.c)

# Link against SDL2
target_link_libraries(MySDLApp ${SDL2_LIBRARIES})
