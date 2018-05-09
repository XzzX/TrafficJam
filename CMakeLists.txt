cmake_minimum_required(VERSION 3.5)

set (CMAKE_CXX_STANDARD 14)

project(TrafficJam)
add_executable(${PROJECT_NAME} "main.cpp" "lodepng/lodepng.cpp")
target_compile_options(TrafficJam PUBLIC -Wall -Wextra -Werror)
