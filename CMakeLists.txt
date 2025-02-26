cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src/snake src/pong)

add_executable(SnakeGame src/snake/main.cpp src/snake/game.cpp src/snake/controller.cpp src/snake/renderer.cpp src/snake/snake.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(SnakeGame ${SDL2_LIBRARIES})

add_executable(PongGame src/pong/main.cpp src/pong/game.cpp src/pong/controller.cpp src/pong/renderer.cpp src/pong/ball.cpp src/pong/paddle.cpp src/pong/pongObject.cpp src/pong/wall.cpp)
# string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PongGame ${SDL2_LIBRARIES})
